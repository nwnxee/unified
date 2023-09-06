#include <stdio.h>
#include <string.h>
#include <funchook.h>
#include "test.h"
#include "libfunchook_test.h"
#ifdef WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

#define DUMP_BYTES(var) dump_bytes((void *)&var, sizeof(var))
static void dump_bytes(void *addr, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        if (i != 0 && i % 4 == 0) {
            printf(" ");
        }
        printf("%02x", ((uint8_t*)addr)[i]);
    }
}

static int (*dllfunc_1_func)(int a, int b);
static int (*dllfunc_2_func)(int a, int b);

static int dllfunc_1_hook_is_called = 0;
static int dllfunc_1_hook(int a, int b)
{
    dllfunc_1_hook_is_called = 1;
    return dllfunc_1_func(a, b);
}

funchook_info_t saved_func_info;

static void prehook(funchook_info_t *info)
{
    saved_func_info = *info;
}

static void test_dllfunc(void)
{
    funchook_t *funchook;
    int rv;
    void *dllfunc_1_user_data = (void*)(size_t)0xdeadbeef;
    void *dllfunc_2_user_data = (void*)(size_t)0xcafebabe;
#ifdef WIN32
    HANDLE hMod = GetModuleHandleA("funchook_test_dll.dll");
    if (hMod == NULL) {
        hMod = GetModuleHandleA("libfunchook_test.so");
    }
    void *dllfunc_1_addr = GetProcAddress(hMod, "dllfunc_1");
    void *dllfunc_2_addr = GetProcAddress(hMod, "dllfunc_2");
#else
    void *dlhandle = dlopen("libfunchook_test.so", RTLD_LAZY);
    void *dllfunc_1_addr = dlsym(dlhandle, "dllfunc_1");
    void *dllfunc_2_addr = dlsym(dlhandle, "dllfunc_2");
    dlclose(dlhandle);
#endif

    printf("[%d] test_prehook: func_info\n", ++test_cnt);

    funchook = funchook_create();

    dllfunc_1_func = dllfunc_1;
    const funchook_params_t params1 = {
        .hook_func = dllfunc_1_hook,
        .prehook = prehook,
        .user_data = dllfunc_1_user_data,
    };
    rv = funchook_prepare_with_params(funchook, (void**)&dllfunc_1_func, &params1);
    if (rv != 0) {
        printf("ERROR: failed to prepare hook dllfunc_1 with prehook. (%s)\n", funchook_error_message(funchook));
        error_cnt++;
        return;
    }

    dllfunc_2_func = dllfunc_2;
    const funchook_params_t params2 = {
        .prehook = prehook,
        .user_data = dllfunc_2_user_data,
    };
    rv = funchook_prepare_with_params(funchook, (void**)&dllfunc_2_func, &params2);
    if (rv != 0) {
        printf("ERROR: failed to prepare hook dllfunc_2 with prehook. (%s)\n", funchook_error_message(funchook));
        error_cnt++;
        return;
    }

    rv = funchook_install(funchook, 0);
    if (rv != 0) {
        printf("ERROR: failed to install hooks. (%s)\n", funchook_error_message(funchook));
        error_cnt++;
        return;
    }

    memset(&saved_func_info, 0, sizeof(saved_func_info));
    dllfunc_1_hook_is_called = 0;
    rv = dllfunc_1(2, 3);
    if (rv != 2 * 3 + 1) {
        printf("ERROR: dllfunc_1 returns %d\n", rv);
        error_cnt++;
        return;
    }
    if (dllfunc_1_hook_is_called == 0) {
      printf("ERROR: dllfunc_1_hook isn't called.\n");
      error_cnt++;
      return;
    }
    if (saved_func_info.original_target_func != dllfunc_1 ||
        saved_func_info.target_func != dllfunc_1_addr ||
        saved_func_info.trampoline_func != dllfunc_1_func ||
        saved_func_info.hook_func != dllfunc_1_hook ||
        saved_func_info.user_data != dllfunc_1_user_data) {
        printf("ERROR: unexpected dllfunc_1's saved func_info.\n"
               "   expected {%p, %p, %p, %p, %p}\n"
               "        but {%p, %p, %p, %p, %p}\n",
               dllfunc_1, dllfunc_1_addr, dllfunc_1_func, dllfunc_1_hook, dllfunc_1_user_data,
               saved_func_info.original_target_func,
               saved_func_info.target_func,
               saved_func_info.trampoline_func,
               saved_func_info.hook_func,
               saved_func_info.user_data);
          error_cnt++;
        return;
    }

    memset(&saved_func_info, 0, sizeof(saved_func_info));
    rv = dllfunc_2(3, 4);
    if (rv != 3 * 4 + 2) {
        printf("ERROR: dllfunc_2 returns %d\n", rv);
        error_cnt++;
        return;
    }
    if (saved_func_info.original_target_func != dllfunc_2 ||
        saved_func_info.target_func != dllfunc_2_addr ||
        saved_func_info.trampoline_func != dllfunc_2_func ||
        saved_func_info.hook_func != NULL ||
        saved_func_info.user_data != dllfunc_2_user_data) {
        printf("ERROR: unexpected dllfunc_2's saved func_info.\n"
               "   expected {%p, %p, %p, %p, %p}\n"
               "        but {%p, %p, %p, %p, %p}\n",
               dllfunc_2, dllfunc_2_addr, dllfunc_2_func, NULL, dllfunc_2_user_data,
               saved_func_info.original_target_func,
               saved_func_info.target_func,
               saved_func_info.trampoline_func,
               saved_func_info.hook_func,
               saved_func_info.user_data);
        error_cnt++;
        return;
    }

    funchook_uninstall(funchook, 0);
    funchook_destroy(funchook);
}

static long (*long_args_func)(long arg1, long arg2, long arg3, long arg4, long arg5, long arg6, long arg7, long arg8, long arg9, long arg10);
long long_args_in_prehook[10];
static void long_args_prehook(funchook_info_t *info)
{
    for (int i = 0; i < 10; i++) {
      long val;
      if (funchook_get_arg(info->arg_handle, i + 1, &val) == 0) {
          long_args_in_prehook[i] = val;
      }
    }
}

static void test_long_args(void)
{
    funchook_t *funchook;
    int rv;

    printf("[%d] test_prehook: long_args\n", ++test_cnt);

    funchook = funchook_create();

    long_args_func = long_args;
    const funchook_params_t long_args_params = {
        .prehook = long_args_prehook,
        .arg_types = "lllllllllll",
    };
    rv = funchook_prepare_with_params(funchook, (void**)&long_args_func, &long_args_params);
    if (rv != 0) {
        printf("ERROR: failed to prepare hook long_args with prehook. (%s)\n", funchook_error_message(funchook));
        error_cnt++;
        return;
    }

    rv = funchook_install(funchook, 0);
    if (rv != 0) {
        printf("ERROR: failed to install hooks. (%s)\n", funchook_error_message(funchook));
        error_cnt++;
        return;
    }

    long retval = long_args(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    for (int i = 0; i < 10; i++) {
        if (long_args_in_prehook[i] != i + 1 || long_args_in_target[i] != i + 1) {
            printf("ERROR: unexpected arguments in long_args\n"
                   "          expected [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, ]\n"
                   "   args in prehook [");
            for (i = 0; i < 10; i++) {
                printf("%lu, ", long_args_in_prehook[i]);
            }
            printf("]\n"
                   "    args in target [");
            for (i = 0; i < 10; i++) {
                printf("%lu, ", long_args_in_target[i]);
            }
            printf("]\n");
            error_cnt++;
            return;
        }
    }

    funchook_uninstall(funchook, 0);
    funchook_destroy(funchook);
}

static double (*double_args_func)(double arg1, double arg2, double arg3, double arg4, double arg5, double arg6, double arg7, double arg8, double arg9, double arg10);
double double_args_in_prehook[10];
static void double_args_prehook(funchook_info_t *info)
{
    for (int i = 0; i < 10; i++) {
      double val;
      if (funchook_get_arg(info->arg_handle, i + 1, &val) == 0) {
          double_args_in_prehook[i] = val;
      }
    }
}

static void test_double_args(void)
{
    funchook_t *funchook;
    int rv;

    printf("[%d] test_prehook: double_args\n", ++test_cnt);

    funchook = funchook_create();

    double_args_func = double_args;
    const funchook_params_t double_args_params = {
        .prehook = double_args_prehook,
        .arg_types = "ddddddddddd",
    };
    rv = funchook_prepare_with_params(funchook, (void**)&double_args_func, &double_args_params);
    if (rv != 0) {
        printf("ERROR: failed to prepare hook double_args with prehook. (%s)\n", funchook_error_message(funchook));
        error_cnt++;
        return;
    }

    rv = funchook_install(funchook, 0);
    if (rv != 0) {
        printf("ERROR: failed to install hooks. (%s)\n", funchook_error_message(funchook));
        error_cnt++;
        return;
    }

    double retval = double_args(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    for (int i = 0; i < 10; i++) {
        if (double_args_in_prehook[i] != i + 1 || double_args_in_target[i] != i + 1) {
            printf("ERROR: unexpected arguments in double_args\n"
                   "          expected [%f, %f, %f, %f, %f, %f, %f, %f, %f, %f, ]\n"
                   "   args in prehook [",
                   1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0);
            for (i = 0; i < 10; i++) {
                printf("%f, ", double_args_in_prehook[i]);
            }
            printf("]\n"
                   "    args in target [");
            for (i = 0; i < 10; i++) {
                printf("%f, ", double_args_in_target[i]);
            }
            printf("]\n");
            error_cnt++;
            return;
        }
    }

    funchook_uninstall(funchook, 0);
    funchook_destroy(funchook);
}

static mixed_args_t (*mixed_args_func)(
    uint8_t u8_1, double dbl1_1, uint16_t u16_1, float flt1_1, uint32_t u32_1, double dbl2_1,
    long lng_1, float flt2_1, uint64_t u64_1, double dbl3_1, uintptr_t uptr_1, float flt3_1,
    uint8_t u8_2, double dbl1_2, uint16_t u16_2, float flt1_2, uint32_t u32_2, double dbl2_2,
    long lng_2, float flt2_2, uint64_t u64_2, double dbl3_2, uintptr_t uptr_2, float flt3_2);
mixed_args_t mixed_args_in_prehook[2];
static void mixed_args_prehook(funchook_info_t *info)
{
    memset(mixed_args_in_prehook, PADDING_BYTE, sizeof(mixed_args_in_prehook));
    for (int i = 0; i < 2; i++) {
        mixed_args_t *arg  = &mixed_args_in_prehook[i];
        funchook_get_arg(info->arg_handle, 12 * i + 1, &arg->u8);
        funchook_get_arg(info->arg_handle, 12 * i + 2, &arg->dbl1);
        funchook_get_arg(info->arg_handle, 12 * i + 3, &arg->u16);
        funchook_get_arg(info->arg_handle, 12 * i + 4, &arg->flt1);
        funchook_get_arg(info->arg_handle, 12 * i + 5, &arg->u32);
        funchook_get_arg(info->arg_handle, 12 * i + 6, &arg->dbl2);
        funchook_get_arg(info->arg_handle, 12 * i + 7, &arg->lng);
        funchook_get_arg(info->arg_handle, 12 * i + 8, &arg->flt2);
        funchook_get_arg(info->arg_handle, 12 * i + 9, &arg->u64);
        funchook_get_arg(info->arg_handle, 12 * i + 10, &arg->dbl3);
        funchook_get_arg(info->arg_handle, 12 * i + 11, &arg->uptr);
        funchook_get_arg(info->arg_handle, 12 * i + 12, &arg->flt3);
    }
}

static void test_mixed_args(void)
{
    funchook_t *funchook;
    int rv;

    printf("[%d] test_prehook: mixed_args\n", ++test_cnt);

    funchook = funchook_create();

    mixed_args_func = mixed_args;
    const funchook_params_t mixed_args_params = {
        .prehook = mixed_args_prehook,
        .arg_types = "SbdhfidlfLdpfbdhfidlfLdpf",
    };
    rv = funchook_prepare_with_params(funchook, (void**)&mixed_args_func, &mixed_args_params);
    if (rv != 0) {
        printf("ERROR: failed to prepare hook mixed_args with prehook. (%s)\n", funchook_error_message(funchook));
        error_cnt++;
        return;
    }

    rv = funchook_install(funchook, 0);
    if (rv != 0) {
        printf("ERROR: failed to install hooks. (%s)\n", funchook_error_message(funchook));
        error_cnt++;
        return;
    }

    mixed_args_t expected_args[2];
    memset(expected_args, PADDING_BYTE, sizeof(expected_args));
    expected_args[0].u8 = 1;
    expected_args[0].dbl1 = 2.0;
    expected_args[0].u16 = 3;
    expected_args[0].flt1 = 4.0f;
    expected_args[0].u32 = 5;
    expected_args[0].dbl2 = 6.0;
    expected_args[0].lng = 7;
    expected_args[0].flt2 = 8.0f;
    expected_args[0].u64 = 9;
    expected_args[0].dbl3 = 10.0;
    expected_args[0].uptr = 11;
    expected_args[0].flt3 = 12.0f;
    expected_args[1].u8 = 13;
    expected_args[1].dbl1 = 14.0;
    expected_args[1].u16 = 15;
    expected_args[1].flt1 = 16.0f;
    expected_args[1].u32 = 17;
    expected_args[1].dbl2 = 18.0;
    expected_args[1].lng = 19;
    expected_args[1].flt2 = 20.0f;
    expected_args[1].u64 = 21;
    expected_args[1].dbl3 = 22.0;
    expected_args[1].uptr = 23;
    expected_args[1].flt3 = 24.0f;
    mixed_args_t retval = mixed_args(1, 2.0, 3, 4.0f, 5, 6.0,
                                     7, 8.0f, 9, 10.0, 11, 12.0f,
                                     13, 14.0, 15, 16.0f, 17, 18.0,
                                     19, 20.0f, 21, 22.0, 23, 24.0f);
    if (memcmp(&expected_args, mixed_args_in_prehook, sizeof(expected_args)) != 0 ||
        memcmp(&expected_args, mixed_args_in_target, sizeof(expected_args)) != 0) {
        printf("ERROR: unexpected arguments in mixed_args\n"
               "          expected [");
        DUMP_BYTES(expected_args);
        printf("]\n"
               "   args in prehook [");
        DUMP_BYTES(mixed_args_in_prehook);
        printf("]\n"
               "    args in target [");
        DUMP_BYTES(mixed_args_in_target);
        printf("]\n");
        error_cnt++;
        return;
    }

    funchook_uninstall(funchook, 0);
    funchook_destroy(funchook);
}

fastcall_args_t fastcall_args_in_prehook;
static void fastcall_llld_prehook(funchook_info_t *info)
{
    memset(&fastcall_args_in_prehook, PADDING_BYTE, sizeof(fastcall_args_in_prehook));
    funchook_get_arg(info->arg_handle, 1, &fastcall_args_in_prehook.l1);
    funchook_get_arg(info->arg_handle, 2, &fastcall_args_in_prehook.l2);
    funchook_get_arg(info->arg_handle, 3, &fastcall_args_in_prehook.l3);
    funchook_get_arg(info->arg_handle, 4, &fastcall_args_in_prehook.d);
}
static void fastcall_lldl_prehook(funchook_info_t *info)
{
    memset(&fastcall_args_in_prehook, PADDING_BYTE, sizeof(fastcall_args_in_prehook));
    funchook_get_arg(info->arg_handle, 1, &fastcall_args_in_prehook.l1);
    funchook_get_arg(info->arg_handle, 2, &fastcall_args_in_prehook.l2);
    funchook_get_arg(info->arg_handle, 3, &fastcall_args_in_prehook.d);
    funchook_get_arg(info->arg_handle, 4, &fastcall_args_in_prehook.l3);
}
static void fastcall_ldll_prehook(funchook_info_t *info)
{
    memset(&fastcall_args_in_prehook, PADDING_BYTE, sizeof(fastcall_args_in_prehook));
    funchook_get_arg(info->arg_handle, 1, &fastcall_args_in_prehook.l1);
    funchook_get_arg(info->arg_handle, 2, &fastcall_args_in_prehook.d);
    funchook_get_arg(info->arg_handle, 3, &fastcall_args_in_prehook.l2);
    funchook_get_arg(info->arg_handle, 4, &fastcall_args_in_prehook.l3);
}
static void fastcall_dlll_prehook(funchook_info_t *info)
{
    memset(&fastcall_args_in_prehook, PADDING_BYTE, sizeof(fastcall_args_in_prehook));
    funchook_get_arg(info->arg_handle, 1, &fastcall_args_in_prehook.d);
    funchook_get_arg(info->arg_handle, 2, &fastcall_args_in_prehook.l1);
    funchook_get_arg(info->arg_handle, 3, &fastcall_args_in_prehook.l2);
    funchook_get_arg(info->arg_handle, 4, &fastcall_args_in_prehook.l3);
}
static void fastcall_ret_struct_prehook(funchook_info_t *info)
{
    memset(&fastcall_args_in_prehook, PADDING_BYTE, sizeof(fastcall_args_in_prehook));
    funchook_get_arg(info->arg_handle, 1, &fastcall_args_in_prehook.l1);
    funchook_get_arg(info->arg_handle, 2, &fastcall_args_in_prehook.d);
    funchook_get_arg(info->arg_handle, 3, &fastcall_args_in_prehook.l2);
    funchook_get_arg(info->arg_handle, 4, &fastcall_args_in_prehook.l3);
}

static void test_fastcall_args(void)
{
    funchook_t *funchook;
    int rv;
    void *target_func;

    printf("[%d] test_prehook: fastcall_args\n", ++test_cnt);

    funchook = funchook_create();

    target_func = (void*)fastcall_llld;
    const funchook_params_t fastcall_llld_params = {
        .prehook = fastcall_llld_prehook,
        .flags = FUNCHOOK_FLAG_FASTCALL,
        .arg_types = "dllld",
    };
    rv = funchook_prepare_with_params(funchook, &target_func, &fastcall_llld_params);
    if (rv != 0) {
        printf("ERROR: failed to prepare hook fastcall_llld with prehook. (%s)\n", funchook_error_message(funchook));
        error_cnt++;
        return;
    }

    target_func = (void*)fastcall_lldl;
    const funchook_params_t fastcall_lldl_params = {
        .prehook = fastcall_lldl_prehook,
        .flags = FUNCHOOK_FLAG_FASTCALL,
        .arg_types = "dlldl",
    };
    rv = funchook_prepare_with_params(funchook, &target_func, &fastcall_lldl_params);
    if (rv != 0) {
        printf("ERROR: failed to prepare hook fastcall_lldl with prehook. (%s)\n", funchook_error_message(funchook));
        error_cnt++;
        return;
    }

    target_func = (void*)fastcall_ldll;
    const funchook_params_t fastcall_ldll_params = {
        .prehook = fastcall_ldll_prehook,
        .flags = FUNCHOOK_FLAG_FASTCALL,
        .arg_types = "dldll",
    };
    rv = funchook_prepare_with_params(funchook, &target_func, &fastcall_ldll_params);
    if (rv != 0) {
        printf("ERROR: failed to prepare hook fastcall_ldll with prehook. (%s)\n", funchook_error_message(funchook));
        error_cnt++;
        return;
    }

    target_func = (void*)fastcall_dlll;
    const funchook_params_t fastcall_dlll_params = {
        .prehook = fastcall_dlll_prehook,
        .flags = FUNCHOOK_FLAG_FASTCALL,
        .arg_types = "ddlll",
    };
    rv = funchook_prepare_with_params(funchook, &target_func, &fastcall_dlll_params);
    if (rv != 0) {
        printf("ERROR: failed to prepare hook fastcall_dlll with prehook. (%s)\n", funchook_error_message(funchook));
        error_cnt++;
        return;
    }

    target_func = (void*)fastcall_ret_struct;
    const funchook_params_t fastcall_ret_struct_params = {
        .prehook = fastcall_ret_struct_prehook,
        .flags = FUNCHOOK_FLAG_FASTCALL,
        .arg_types = "Sldll",
    };
    rv = funchook_prepare_with_params(funchook, &target_func, &fastcall_ret_struct_params);
    if (rv != 0) {
        printf("ERROR: failed to prepare hook fastcall_ret_struct with prehook. (%s)\n", funchook_error_message(funchook));
        error_cnt++;
        return;
    }

    rv = funchook_install(funchook, 0);
    if (rv != 0) {
        printf("ERROR: failed to install hooks. (%s)\n", funchook_error_message(funchook));
        error_cnt++;
        funchook_destroy(funchook);
        return;
    }

    fastcall_args_t fastcall_args_expected;
    double retval;

    memset(&fastcall_args_in_target, 0, sizeof(fastcall_args_t));
    memset(&fastcall_args_expected, PADDING_BYTE, sizeof(fastcall_args_t));
    fastcall_args_expected.l1 = 1;
    fastcall_args_expected.l2 = 2;
    fastcall_args_expected.l3 = 3;
    fastcall_args_expected.d = 4.0;
    retval = fastcall_llld(1, 2, 3, 4.0);
    if (memcmp(&fastcall_args_expected, &fastcall_args_in_target, sizeof(fastcall_args_t)) != 0 ||
        memcmp(&fastcall_args_expected, &fastcall_args_in_prehook, sizeof(fastcall_args_t)) != 0) {
        printf("ERROR: unexpected arguments in fastcall_llld\n"
               "          expected [");
        DUMP_BYTES(fastcall_args_expected);
        printf("]\n"
               "   args in prehook [");
        DUMP_BYTES(fastcall_args_in_prehook);
        printf("]\n"
               "    args in target [");
        DUMP_BYTES(fastcall_args_in_target);
        printf("]\n");
        error_cnt++;
        goto cleanup;
    }

    memset(&fastcall_args_in_target, 0, sizeof(fastcall_args_t));
    memset(&fastcall_args_expected, PADDING_BYTE, sizeof(fastcall_args_t));
    fastcall_args_expected.l1 = 1;
    fastcall_args_expected.l2 = 2;
    fastcall_args_expected.d = 3.0;
    fastcall_args_expected.l3 = 4;
    retval = fastcall_lldl(1, 2, 3, 4.0);
    if (memcmp(&fastcall_args_expected, &fastcall_args_in_target, sizeof(fastcall_args_t)) != 0 ||
        memcmp(&fastcall_args_expected, &fastcall_args_in_prehook, sizeof(fastcall_args_t)) != 0) {
        printf("ERROR: unexpected arguments in fastcall_lldl\n"
               "          expected [");
        DUMP_BYTES(fastcall_args_expected);
        printf("]\n"
               "   args in prehook [");
        DUMP_BYTES(fastcall_args_in_prehook);
        printf("]\n"
               "    args in target [");
        DUMP_BYTES(fastcall_args_in_target);
        printf("]\n");
        error_cnt++;
        goto cleanup;
    }

    memset(&fastcall_args_in_target, 0, sizeof(fastcall_args_t));
    memset(&fastcall_args_expected, PADDING_BYTE, sizeof(fastcall_args_t));
    fastcall_args_expected.l1 = 1;
    fastcall_args_expected.d = 2.0;
    fastcall_args_expected.l2 = 3;
    fastcall_args_expected.l3 = 4;
    retval = fastcall_ldll(1, 2.0, 3, 4);
    if (memcmp(&fastcall_args_expected, &fastcall_args_in_target, sizeof(fastcall_args_t)) != 0 ||
        memcmp(&fastcall_args_expected, &fastcall_args_in_prehook, sizeof(fastcall_args_t)) != 0) {
        printf("ERROR: unexpected arguments in fastcall_ldll\n"
               "          expected [");
        DUMP_BYTES(fastcall_args_expected);
        printf("]\n"
               "   args in prehook [");
        DUMP_BYTES(fastcall_args_in_prehook);
        printf("]\n"
               "    args in target [");
        DUMP_BYTES(fastcall_args_in_target);
        printf("]\n");
        error_cnt++;
        goto cleanup;
    }

    memset(&fastcall_args_in_target, 0, sizeof(fastcall_args_t));
    memset(&fastcall_args_expected, PADDING_BYTE, sizeof(fastcall_args_t));
    fastcall_args_expected.d = 1.0;
    fastcall_args_expected.l1 = 2;
    fastcall_args_expected.l2 = 3;
    fastcall_args_expected.l3 = 4;
    retval = fastcall_dlll(1.0, 2, 3, 4);
    if (memcmp(&fastcall_args_expected, &fastcall_args_in_target, sizeof(fastcall_args_t)) != 0 ||
        memcmp(&fastcall_args_expected, &fastcall_args_in_prehook, sizeof(fastcall_args_t)) != 0) {
        printf("ERROR: unexpected arguments in fastcall_dlll\n"
               "          expected [");
        DUMP_BYTES(fastcall_args_expected);
        printf("]\n"
               "   args in prehook [");
        DUMP_BYTES(fastcall_args_in_prehook);
        printf("]\n"
               "    args in target [");
        DUMP_BYTES(fastcall_args_in_target);
        printf("]\n");
        error_cnt++;
        goto cleanup;
    }

    memset(&fastcall_args_in_target, 0, sizeof(fastcall_args_t));
    memset(&fastcall_args_expected, PADDING_BYTE, sizeof(fastcall_args_t));
    fastcall_args_expected.l1 = 1;
    fastcall_args_expected.d = 2.0;
    fastcall_args_expected.l2 = 3;
    fastcall_args_expected.l3 = 4;
    fastcall_args_t ret_struct = fastcall_ret_struct(1, 2.0, 3, 4);
    if (memcmp(&fastcall_args_expected, &fastcall_args_in_target, sizeof(fastcall_args_t)) != 0 ||
        memcmp(&fastcall_args_expected, &fastcall_args_in_prehook, sizeof(fastcall_args_t)) != 0 ||
        memcmp(&fastcall_args_expected, &ret_struct, sizeof(fastcall_args_t)) != 0) {
        printf("ERROR: unexpected arguments in fastcall_ret_struct\n"
               "          expected [");
        DUMP_BYTES(fastcall_args_expected);
        printf("]\n"
               "   args in prehook [");
        DUMP_BYTES(fastcall_args_in_prehook);
        printf("]\n"
               "    args in target [");
        DUMP_BYTES(fastcall_args_in_target);
        printf("]\n"
               "      return value [");
        DUMP_BYTES(ret_struct);
        printf("]\n");
        error_cnt++;
        goto cleanup;
    }

cleanup:
    funchook_uninstall(funchook, 0);
    funchook_destroy(funchook);
}

void test_prehook(void)
{
    funchook_set_debug_file("debug.log");
    test_dllfunc();
    test_long_args();
    test_double_args();
    test_mixed_args();
    test_fastcall_args();
}

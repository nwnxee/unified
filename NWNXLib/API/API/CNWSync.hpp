#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSync)
#endif


namespace NWSync {

struct CNWSync {
    void *m_internal;
    char *m_tmp1;
    uint32_t m_tmp2;

    struct ManifestMetaData {
        char field0_0x0;
        long long field1_0x1;
        long long field2_0x9;
        int field3_0x11;
        char field4_0x15;
        char field5_0x16;
        char field6_0x17;
        char field7_0x18;
        char field8_0x19;
        char field9_0x1a;
        char field10_0x1b;
        char field11_0x1c;
        char field12_0x1d;
        char field13_0x1e;
        char field14_0x1f;
        char field15_0x20;
        char field16_0x21;
        char field17_0x22;
        char field18_0x23;
        char field19_0x24;
        char field20_0x25;
        char field21_0x26;
        char field22_0x27;
        char field23_0x28;
        char field24_0x29;
        char field25_0x2a;
        char field26_0x2b;
        char field27_0x2c;
        char field28_0x2d;
        char field29_0x2e;
        char field30_0x2f;
        char field31_0x30;
        char field32_0x31;
        char field33_0x32;
        char field34_0x33;
        char field35_0x34;
        char field36_0x35;
        char field37_0x36;
        char field38_0x37;
        char field39_0x38;
        char field40_0x39;
        char field41_0x3a;
        char field42_0x3b;
        char field43_0x3c;
        char field44_0x3d;
        char field45_0x3e;
        char field46_0x3f;
        char field47_0x40;
        char field48_0x41;
        char field49_0x42;
        char field50_0x43;
        char field51_0x44;
        char field52_0x45;
        char field53_0x46;
        char field54_0x47;
        char field55_0x48;
        char field56_0x49;
        char field57_0x4a;
        char field58_0x4b;
        char field59_0x4c;
        char field60_0x4d;
        char field61_0x4e;
        char field62_0x4f;
        char field63_0x50;
        char field64_0x51;
        char field65_0x52;
        char field66_0x53;
        char field67_0x54;
        char field68_0x55;
        char field69_0x56;
        char field70_0x57;
        char field71_0x58;
        char field72_0x59;
        char field73_0x5a;
        char field74_0x5b;
        char field75_0x5c;
        char field76_0x5d;
        char field77_0x5e;
        char field78_0x5f;
        char field79_0x60;
        char field80_0x61;
        char field81_0x62;
        char field82_0x63;
        char field83_0x64;
        char field84_0x65;
        char field85_0x66;
        char field86_0x67;
        long long field87_0x68;
        long long field88_0x70;
    };

#ifdef NWN_CLASS_EXTENSION_CNWSync
    NWN_CLASS_EXTENSION_CNWSync
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSync)
#endif

}

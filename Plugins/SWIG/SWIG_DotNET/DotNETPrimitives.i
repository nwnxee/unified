%define MarshalPrimitive(CTYPE, CSTYPE, CSARRAYTYPE)
%typemap(ctype)  CTYPE*,CTYPE&,CTYPE[ANY] "CTYPE*"
%typemap(ctype)  CTYPE "CTYPE"
%typemap(imtype) CTYPE*,CTYPE&,CTYPE[ANY] "global::System.IntPtr"
%typemap(imtype) CTYPE "CSTYPE"
%typemap(cstype) CTYPE*,CTYPE& "CSTYPE*"
%typemap(cstype) CTYPE[ANY] "NativeArray<CSARRAYTYPE>"
%typemap(cstype) CTYPE "CSTYPE"
%typemap(csin)   CTYPE*,CTYPE& "(global::System.IntPtr)$csinput"
%typemap(csin)   CTYPE[ANY] "$csinput"
%typemap(csin)   CTYPE "$csinput"
%typemap(in)     CTYPE,CTYPE*,CTYPE&,CTYPE[ANY] %{ $1 = $input; %}
%typemap(out)    CTYPE,CTYPE*,CTYPE& %{ $result = $1; %}

%typemap(csout, excode=SWIGEXCODE) CTYPE*,CTYPE& {
    global::System.IntPtr retVal = $imcall;$excode
    return (CSTYPE*)retVal;
  }

%typemap(csvarout, excode=SWIGEXCODE2) CTYPE*,CTYPE& %{
    get {
        global::System.IntPtr retVal = $imcall;$excode
        return (CSTYPE*)retVal;
    }
%}

%typemap(csout, excode=SWIGEXCODE) CTYPE[ANY] {
    global::System.IntPtr arrayPtr = $imcall;$excode
    NativeArray<CSARRAYTYPE> retVal = new NativeArray<CSARRAYTYPE>(arrayPtr, $1_dim0);

    return retVal; // CSTYPE[$1_dim0]
  }

%typemap(csvarout, excode=SWIGEXCODE2) CTYPE[ANY] %{
    get {
      global::System.IntPtr arrayPtr = $imcall;$excode
      NativeArray<CSARRAYTYPE> retVal = new NativeArray<CSARRAYTYPE>(arrayPtr, $1_dim0);

      return retVal; // CSTYPE[$1_dim0]
    }
%}

%typemap(csout, excode=SWIGEXCODE) CTYPE {
    CSTYPE retVal = $imcall;$excode
    return retVal;
  }

%typemap(csvarout, excode=SWIGEXCODE2) CTYPE %{
    get {
      CSTYPE retVal = $imcall;$excode
      return retVal;
    }
%}
%enddef

// Marshal primitive types to managed types.
MarshalPrimitive(signed char, sbyte, sbyte)
MarshalPrimitive(char, byte, byte)
MarshalPrimitive(char*, byte*, global::System.IntPtr) // char**
MarshalPrimitive(unsigned char, byte, byte)
MarshalPrimitive(unsigned char*, byte*, global::System.IntPtr) //unsigned char**
MarshalPrimitive(short int, short, short)
MarshalPrimitive(int, int, int)
MarshalPrimitive(int*, int*, global::System.IntPtr) // int**
MarshalPrimitive(float, float, float)
MarshalPrimitive(float*, float*, global::System.IntPtr) //float**
MarshalPrimitive(float**, float**, global::System.IntPtr) //float***
MarshalPrimitive(long, long, long)
MarshalPrimitive(unsigned short int, ushort, ushort)
MarshalPrimitive(unsigned int, uint, uint)
MarshalPrimitive(unsigned int*, uint*, global::System.IntPtr) //unsigned int**
MarshalPrimitive(unsigned long, ulong, ulong)

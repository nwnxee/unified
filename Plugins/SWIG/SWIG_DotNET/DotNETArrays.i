// C# code for accessing native arrays
%define MapArray(TYPE, CSTYPE, NAME)
%typemap(cstype) TYPE[ANY] "NAME"
%typemap(csin)   TYPE[ANY] "NAME.getCPtr($csinput)"
%typemap(csout, excode=SWIGEXCODE) TYPE[ANY] {
    global::System.IntPtr cPtr = $imcall;$excode;
    NAME ret = (cPtr == global::System.IntPtr.Zero) ? null : new NAME(cPtr, false);
    return ret;
  }

%typemap(csvarout, excode=SWIGEXCODE2) TYPE[ANY] %{
    get {
        global::System.IntPtr cPtr = $imcall;$excode;
        NAME ret = (cPtr == global::System.IntPtr.Zero) ? null : new NAME(cPtr, false);
        return ret;
    }
%}

%typemap(cscode, noblock=1) NAME {
SWIG_DOTNET_EXTENSIONS

  public CSTYPE this[int index] {
    get {
      return GetItem(index);
    }
    set {
      SetItem(index, value);
    }
  }
}
%enddef

// Native array definition for a C-style array define.
%define DefineArray(TYPE, CSTYPE, NAME)
%{
typedef TYPE NAME;
%}
typedef struct {} NAME;

%extend NAME {
NAME(int nElements) {
  return new TYPE[nElements]();
}

~NAME() {
  delete [] self;
}

TYPE GetItem(int index) {
  return self[index];
}

void SetItem(int index, TYPE value) {
  self[index] = value;
}

static NAME* FromPointer(TYPE *ptr) {
  return (NAME *) ptr;
}

};
%enddef

// Native array definition for an array defined as a pointer, with a separate length variable.
%define DefineArrayPtr(TYPE, CSTYPE, NAME)
%{
typedef TYPE NAME;
%}
typedef struct {} NAME;

%extend NAME {
NAME(int nElements) {
  return new TYPE[nElements]();
}

~NAME() {
  delete [] self;
}

TYPE* GetItem(int index) {
  return &self[index];
}

void SetItem(int index, TYPE* value) {
  self[index] = *value;
}

static NAME* FromPointer(TYPE *ptr) {
  return static_cast<NAME*>(ptr);
}

};
%enddef

%define SWIG_DOTNET_EXTENSIONS

  public global::System.IntPtr Pointer {
    get {
      return swigCPtr.Handle;
    }
  }

  public static unsafe implicit operator void*($csclassname self) {
    return (void*)self.swigCPtr.Handle;
  }

  public static unsafe $csclassname FromPointer(void* pointer, bool memoryOwn = false) {
    return pointer != null ? new $csclassname((global::System.IntPtr)pointer, memoryOwn) : null;
  }

  public static $csclassname FromPointer(global::System.IntPtr pointer, bool memoryOwn = false) {
    return pointer != global::System.IntPtr.Zero ? new $csclassname(pointer, memoryOwn) : null;
  }

  public bool Equals($csclassname other) {
    if (ReferenceEquals(null, other)) {
      return false;
    }

    if (ReferenceEquals(this, other)) {
      return true;
    }

    return Pointer.Equals(other.Pointer);
  }

  public override bool Equals(object obj) {
    return ReferenceEquals(this, obj) || obj is $csclassname other && Equals(other);
  }

  public override int GetHashCode() {
    return swigCPtr.Handle.GetHashCode();
  }

  public static bool operator ==($csclassname left, $csclassname right) {
    return Equals(left, right);
  }

  public static bool operator !=($csclassname left, $csclassname right) {
    return !Equals(left, right);
  }
%enddef

// C# Wrapper Class Extensions - Default
%typemap(cscode, noblock=1) SWIGTYPE, SWIGTYPE *, SWIGTYPE &, SWIGTYPE (CLASS::*) {
SWIG_DOTNET_EXTENSIONS
}

// C# Wrapper Class Extensions - CExoString
%typemap(cscode, noblock=1) CExoString {
SWIG_DOTNET_EXTENSIONS

  public CExoString(string source) : this(NWNX.NET.Native.StringUtils.GetNullTerminatedString(source)) {
  }

  /// <summary>
  /// Converts this CExoString to a C# string.
  /// </summary>
  /// <returns>The equivalent C# string for this CExoString.</returns>
  public override string ToString() {
    return NWNX.NET.Native.StringUtils.ReadNullTerminatedString(CStr());
  }
}

// C# Wrapper Class Extensions - CResRef
%typemap(cscode, noblock=1) CResRef {
SWIG_DOTNET_EXTENSIONS

  public CResRef(string source) : this(NWNX.NET.Native.StringUtils.GetNullTerminatedString(source)) {
  }

  /// <summary>
  /// Gets a C# string representing this ResRef (GetResRefStr())
  /// </summary>
  /// <returns>A C# string representing this ResRef.</returns>
  public override string ToString() {
    return NWNX.NET.Native.StringUtils.ReadNullTerminatedString(GetResRefStr());
  }
}

// Destructor method
%define SWIG_DOTNET_DESTRUCTORS(TypeName)
%extend TypeName {
    void _Destructor() { $self->~TypeName(); }
}
%enddef

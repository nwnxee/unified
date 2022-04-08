/* -----------------------------------------------------------------------------
 * CExoArrayList.i
 *
 * SWIG typemaps for CExoArrayList<T>, based on std::vector implementation: https://github.com/swig/swig/blob/master/Lib/csharp/std_vector.i
 * C# implementation
 * The C# wrapper is made to look and feel like a C# System.Collections.Generic.List<> collection.
 *
 * Note that IEnumerable<> is implemented in the proxy class which is useful for using LINQ with
 * C++ CExoArrayList wrappers. The IList<> interface is also implemented to provide enhanced functionality
 * whenever we are confident that the required C++ operator== is available. This is the case for when
 * T is a primitive type or a pointer. If T does define an operator==, then use the SWIG_CEXOARRAYLIST_ENHANCED
 * macro to obtain this enhanced functionality, for example:
 *
 *   SWIG_CEXOARRAYLIST_ENHANCED(SomeNamespace::Klass)
 *   %template(VectKlass) CExoArrayList<SomeNamespace::Klass>;
 * ----------------------------------------------------------------------------- */

%include <std_common.i>

// MACRO for use within the CExoArrayList class body
%define SWIG_CEXOARRAYLIST_MINIMUM_INTERNAL(CSINTERFACE, CTYPE)
%typemap(csinterfaces) CExoArrayList< CTYPE > "global::System.IDisposable, global::System.Collections.IEnumerable, global::System.Collections.Generic.CSINTERFACE<$typemap(cstype, CTYPE)>\n";
%proxycode %{
  public $csclassname(global::System.Collections.IEnumerable c) : this() {
    if (c == null)
      throw new global::System.ArgumentNullException("c");
    foreach ($typemap(cstype, CTYPE) element in c) {
      this.Add(element);
    }
  }

  public $csclassname(global::System.Collections.Generic.IEnumerable<$typemap(cstype, CTYPE)> c) : this() {
    if (c == null)
      throw new global::System.ArgumentNullException("c");
    foreach ($typemap(cstype, CTYPE) element in c) {
      this.Add(element);
    }
  }

  public bool IsFixedSize {
    get {
      return false;
    }
  }

  public bool IsReadOnly {
    get {
      return false;
    }
  }

  public $typemap(cstype, CTYPE) this[int index] {
    get {
      return InternalGetItem(index);
    }
    set {
      InternalSetItem(index, value);
    }
  }

  public int Capacity {
    get {
      return (int)array_size;
    }
    set {
      if (value < num)
        throw new global::System.ArgumentOutOfRangeException("Capacity");
      SetSize(value);
    }
  }

  public int Count {
    get {
      return (int)num;
    }
  }

  public bool IsSynchronized {
    get {
      return false;
    }
  }

  public void CopyTo($typemap(cstype, CTYPE)[] array)
  {
    CopyTo(0, array, 0, this.Count);
  }

  public void CopyTo($typemap(cstype, CTYPE)[] array, int arrayIndex)
  {
    CopyTo(0, array, arrayIndex, this.Count);
  }

  public void Clear()
  {
    SetSize(0);
  }

  public void CopyTo(int index, $typemap(cstype, CTYPE)[] array, int arrayIndex, int count)
  {
    if (array == null)
      throw new global::System.ArgumentNullException("array");
    if (index < 0)
      throw new global::System.ArgumentOutOfRangeException("index", "Value is less than zero");
    if (arrayIndex < 0)
      throw new global::System.ArgumentOutOfRangeException("arrayIndex", "Value is less than zero");
    if (count < 0)
      throw new global::System.ArgumentOutOfRangeException("count", "Value is less than zero");
    if (array.Rank > 1)
      throw new global::System.ArgumentException("Multi dimensional array.", "array");
    if (index+count > this.Count || arrayIndex+count > array.Length)
      throw new global::System.ArgumentException("Number of elements to copy is too large.");
    for (int i=0; i<count; i++)
      array.SetValue(InternalGetItemCopy(index+i), arrayIndex+i);
  }

  public $typemap(cstype, CTYPE)[] ToArray() {
    $typemap(cstype, CTYPE)[] array = new $typemap(cstype, CTYPE)[this.Count];
    this.CopyTo(array);
    return array;
  }

  global::System.Collections.Generic.IEnumerator<$typemap(cstype, CTYPE)> global::System.Collections.Generic.IEnumerable<$typemap(cstype, CTYPE)>.GetEnumerator() {
    return new $csclassnameEnumerator(this);
  }

  global::System.Collections.IEnumerator global::System.Collections.IEnumerable.GetEnumerator() {
    return new $csclassnameEnumerator(this);
  }

  public $csclassnameEnumerator GetEnumerator() {
    return new $csclassnameEnumerator(this);
  }

  // Type-safe enumerator
  /// Note that the IEnumerator documentation requires an InvalidOperationException to be thrown
  /// whenever the collection is modified. This has been done for changes in the size of the
  /// collection but not when one of the elements of the collection is modified as it is a bit
  /// tricky to detect unmanaged code that modifies the collection under our feet.
  public sealed class $csclassnameEnumerator : global::System.Collections.IEnumerator
    , global::System.Collections.Generic.IEnumerator<$typemap(cstype, CTYPE)>
  {
    private $csclassname collectionRef;
    private int currentIndex;
    private object currentObject;
    private int currentSize;

    public $csclassnameEnumerator($csclassname collection) {
      collectionRef = collection;
      currentIndex = -1;
      currentObject = null;
      currentSize = collectionRef.Count;
    }

    // Type-safe iterator Current
    public $typemap(cstype, CTYPE) Current {
      get {
        if (currentIndex == -1)
          throw new global::System.InvalidOperationException("Enumeration not started.");
        if (currentIndex > currentSize - 1)
          throw new global::System.InvalidOperationException("Enumeration finished.");
        if (currentObject == null)
          throw new global::System.InvalidOperationException("Collection modified.");
        return ($typemap(cstype, CTYPE))currentObject;
      }
    }

    // Type-unsafe IEnumerator.Current
    object global::System.Collections.IEnumerator.Current {
      get {
        return Current;
      }
    }

    public bool MoveNext() {
      int size = collectionRef.Count;
      bool moveOkay = (currentIndex+1 < size) && (size == currentSize);
      if (moveOkay) {
        currentIndex++;
        currentObject = collectionRef[currentIndex];
      } else {
        currentObject = null;
      }
      return moveOkay;
    }

    public void Reset() {
      currentIndex = -1;
      currentObject = null;
      if (collectionRef.Count != currentSize) {
        throw new global::System.InvalidOperationException("Collection modified.");
      }
    }

    public void Dispose() {
        currentIndex = -1;
        currentObject = null;
    }
  }
%}

public:
  int32_t num;
  int32_t array_size;

  void Add(CTYPE t);
  void Pack();
  void Allocate(int32_t s);
  void SetSize(int32_t s);

  CExoArrayList(int32_t s = 0);
  CExoArrayList(const CExoArrayList<CTYPE> &list);
  ~CExoArrayList();

  %extend {
    void RemoveAt(int index) throw (std::out_of_range) {
      if (index>=0 && index<(int)$self->num)
        $self->DelIndex(index);
      else
        throw std::out_of_range("index");
    }
  }
%enddef

%define SWIG_CEXOARRAYLIST_GET_SET(CTYPE)
  %extend {
    const CTYPE& InternalGetItem(int index) throw (std::out_of_range) {
        if (index>=0 && index<(int)$self->num)
        return (*$self)[index];
        else
        throw std::out_of_range("index");
    }

    CTYPE InternalGetItemCopy(int index) throw (std::out_of_range) {
        if (index>=0 && index<(int)$self->num)
        return (*$self)[index];
        else
        throw std::out_of_range("index");
    }

    void InternalSetItem(int index, CTYPE const& val) throw (std::out_of_range) {
        if (index>=0 && index<(int)$self->num)
        (*$self)[index] = val;
        else
        throw std::out_of_range("index");
    }

    void Insert(int index, CTYPE const& x) throw (std::out_of_range) {
        if (index >= 0 && index < (int)$self->num+1)
        $self->Insert(x, index);
        else
        throw std::out_of_range("index");
    }
  }
%enddef

%define SWIG_CEXOARRAYLIST_EXTRA_OP_PTR(CTYPE)
  int32_t IndexOf(CTYPE t);
  BOOL AddUnique(CTYPE t);

  %extend {
    CTYPE InternalGetItem(int index) throw (std::out_of_range) {
        if (index>=0 && index<(int)$self->num)
        return (*$self)[index];
        else
        throw std::out_of_range("index");
    }

    CTYPE InternalGetItemCopy(int index) throw (std::out_of_range) {
        if (index>=0 && index<(int)$self->num)
        return (*$self)[index];
        else
        throw std::out_of_range("index");
    }

    void InternalSetItem(int index, CTYPE val) throw (std::out_of_range) {
        if (index>=0 && index<(int)$self->num)
        (*$self)[index] = val;
        else
        throw std::out_of_range("index");
    }

    void Insert(int index, CTYPE x) throw (std::out_of_range) {
        if (index >= 0 && index < (int)$self->num+1)
        $self->Insert(x, index);
        else
        throw std::out_of_range("index");
    }

    bool Contains(CTYPE value) {
      for (int32_t i = 0; i < $self->num; i++)
      {
        if ($self->element[i] == value)
        {
          return true;
        }
      }

      return false;
    }

    int LastIndexOf(CTYPE value) {
      for (int32_t i = $self->num - 1; i >= 0; i--)
      {
          if ($self->element[i] == value)
          {
              return i;
          }
      }

      return -1;
    }

    bool Remove(CTYPE value) {
      for (int32_t i = 0; i < $self->num; i++)
      {
          if ($self->element[i] == value)
          {
              $self->DelIndex(i);
              return true;
          }
      }

      return false;
    }
  }
%enddef

// Extra methods added to the collection class if operator== is defined for the class being wrapped
// The class will then implement IList<>, which adds extra functionality
%define SWIG_CEXOARRAYLIST_EXTRA_OP_EQUALS_EQUALS(CTYPE)
  int32_t IndexOf(CTYPE t);
  BOOL AddUnique(CTYPE t);

  %extend {
    bool Contains(CTYPE const& value) {
      for (int32_t i = 0; i < $self->num; i++)
      {
        if ($self->element[i] == value)
        {
          return true;
        }
      }

      return false;
    }

    int LastIndexOf(CTYPE const& value) {
      for (int32_t i = $self->num - 1; i >= 0; i--)
      {
          if ($self->element[i] == value)
          {
              return i;
          }
      }

      return -1;
    }

    bool Remove(CTYPE const& value) {
      for (int32_t i = 0; i < $self->num; i++)
      {
          if ($self->element[i] == value)
          {
              $self->DelIndex(i);
              return true;
          }
      }

      return false;
    }
  }
%enddef

%define SWIG_CEXOARRAYLIST_EXTRA_OP_DEREF_EQUALS_EQUALS(CTYPE)
  BOOL DerefContains(CTYPE t);
%enddef

// Macros for CExoArrayList class specializations/enhancements
%define SWIG_CEXOARRAYLIST_ENHANCED(CTYPE)
template<> class CExoArrayList< CTYPE > {
SWIG_CEXOARRAYLIST_MINIMUM_INTERNAL(IList, CTYPE)
SWIG_CEXOARRAYLIST_GET_SET(CTYPE)
SWIG_CEXOARRAYLIST_EXTRA_OP_EQUALS_EQUALS(CTYPE)
};
%enddef

%define SWIG_CEXOARRAYLIST_ENHANCED_PTR(CTYPE)
template<> class CExoArrayList< CTYPE > {
SWIG_CEXOARRAYLIST_MINIMUM_INTERNAL(IList, CTYPE)
SWIG_CEXOARRAYLIST_EXTRA_OP_PTR(CTYPE)
SWIG_CEXOARRAYLIST_EXTRA_OP_DEREF_EQUALS_EQUALS(CTYPE)
};
%enddef

%{
#include "API/CExoArrayList.hpp"
#include <algorithm>
#include <stdexcept>
%}

%csmethodmodifiers CExoArrayList::num "private"
%csmethodmodifiers CExoArrayList::element "private"
%csmethodmodifiers CExoArrayList::array_size "private"
%csmethodmodifiers CExoArrayList::Allocate "private"
%csmethodmodifiers CExoArrayList::InternalGetItemCopy "private"
%csmethodmodifiers CExoArrayList::InternalGetItem "private"
%csmethodmodifiers CExoArrayList::InternalSetItem "private"

// primary (unspecialized) class template for CExoArrayList
// does not require operator== to be defined
template<class T> class CExoArrayList {
    SWIG_CEXOARRAYLIST_MINIMUM_INTERNAL(IEnumerable, T)
    SWIG_CEXOARRAYLIST_GET_SET(T)
};
// specialization for pointers
template<class T> class CExoArrayList<T*> {
    SWIG_CEXOARRAYLIST_MINIMUM_INTERNAL(IList, T*)
    SWIG_CEXOARRAYLIST_EXTRA_OP_PTR(T*)
};
// bool is specialized in the C++ standard - const_reference in particular
template<> class CExoArrayList<bool> {
SWIG_CEXOARRAYLIST_MINIMUM_INTERNAL(IList, bool)
SWIG_CEXOARRAYLIST_EXTRA_OP_EQUALS_EQUALS(bool)
};

// template specializations for CExoArrayList
// these provide extra collections methods as operator== is defined
SWIG_CEXOARRAYLIST_ENHANCED(char)
SWIG_CEXOARRAYLIST_ENHANCED(signed char)
SWIG_CEXOARRAYLIST_ENHANCED(unsigned char)
SWIG_CEXOARRAYLIST_ENHANCED(short)
SWIG_CEXOARRAYLIST_ENHANCED(unsigned short)
SWIG_CEXOARRAYLIST_ENHANCED(int)
SWIG_CEXOARRAYLIST_ENHANCED(unsigned int)
SWIG_CEXOARRAYLIST_ENHANCED(long)
SWIG_CEXOARRAYLIST_ENHANCED(unsigned long)
SWIG_CEXOARRAYLIST_ENHANCED(long long)
SWIG_CEXOARRAYLIST_ENHANCED(unsigned long long)
SWIG_CEXOARRAYLIST_ENHANCED(float)
SWIG_CEXOARRAYLIST_ENHANCED(double)
SWIG_CEXOARRAYLIST_ENHANCED(CExoString)
SWIG_CEXOARRAYLIST_ENHANCED_PTR(CExoString*)
SWIG_CEXOARRAYLIST_ENHANCED(std::string) // also requires a %include <std_string.i>
SWIG_CEXOARRAYLIST_ENHANCED(std::wstring) // also requires a %include <std_wstring.i>

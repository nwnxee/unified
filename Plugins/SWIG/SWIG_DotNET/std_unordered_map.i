/* -----------------------------------------------------------------------------
 * std_unordered_map.i
 *
 * SWIG typemaps for std::unordered_map< K, T >
 *
 * The C# wrapper is made to look and feel like a C# System.Collections.Generic.IDictionary<>.
 *
 * Using this wrapper is fairly simple. For example, to create a map from integers to doubles use:
 *
 *   %include <std_unordered_map.i>
 *   %template(UnorderedMapIntDouble) std::unordered_map<int, double>
 *
 * Notes:
 * 1) IEnumerable<> is implemented in the proxy class which is useful for using LINQ with
 *    C++ std::unordered_map wrappers.
 *
 * Warning: heavy macro usage in this file. Use swig -E to get a sane view on the real file contents!
 * ----------------------------------------------------------------------------- */

%{
#include <unordered_map>
#include <stdexcept>
%}

%csmethodmodifiers std::unordered_map::size "private";
%csmethodmodifiers std::unordered_map::find "private";
%csmethodmodifiers std::unordered_map::begin "private";
%csmethodmodifiers std::unordered_map::end "private";
%csmethodmodifiers std::unordered_map::InternalSetValue "private";
%csmethodmodifiers std::unordered_map::InternalRemove "private";

%rename(Iterator) std::unordered_map::iterator;
%nodefaultctor std::unordered_map::iterator;
%csmethodmodifiers std::unordered_map::iterator::GetNext "internal";
%csmethodmodifiers std::unordered_map::iterator::IsEqual "internal";
%csmethodmodifiers std::unordered_map::iterator::GetKey "internal";
%csmethodmodifiers std::unordered_map::iterator::GetValue "internal";
%csmethodmodifiers std::unordered_map::iterator::SetValue "internal";

namespace std {

template<class K, class T> class unordered_map {

%typemap(csinterfaces) std::unordered_map<K, T>
    "global::System.IDisposable, global::System.Collections.Generic.IDictionary<$typemap(cstype, K), $typemap(cstype, T)>"

%proxycode %{
  public bool IsReadOnly
  {
    get => false;
  }

  public int Count
  {
    get => (int)size();
  }

  public $typemap(cstype, T) this[$typemap(cstype, K) key]
  {
    get
    {
      Iterator iterator = find(key);
      if (iterator.IsEqual(end()))
      {
         throw new global::System.Collections.Generic.KeyNotFoundException("The given key was not present in the UnorderedMap.");
      }

      return iterator.GetValue();
    }

    set => InternalSetValue(key, value);
  }

  public bool Remove($typemap(cstype, K) key)
  {
    Iterator iterator = find(key);
    if (!iterator.IsEqual(end()))
    {
      InternalRemove(iterator);
      return true;
    }

    return false;
  }

  public bool TryGetValue($typemap(cstype, K) key, out $typemap(cstype, T) value)
  {
      Iterator iterator = find(key);
      if (iterator.IsEqual(end()))
      {
         value = default;
         return false;
      }

      value = iterator.GetValue();
      return true;
  }

  public global::System.Collections.Generic.ICollection<$typemap(cstype, K)> Keys
  {
    get
    {
      int startCount = Count;
      Iterator iterator = begin();
      Iterator endIterator = end();

      global::System.Collections.Generic.ICollection<$typemap(cstype, K)> keys = new global::System.Collections.Generic.List<$typemap(cstype, K)>();

      while (!iterator.IsEqual(endIterator))
      {
        if (Count != startCount)
        {
          throw new System.InvalidOperationException("Collection was modified; enumeration operation may not execute.");
        }

        keys.Add(iterator.GetKey());
        iterator = iterator.MoveNext();
      }

      return keys;
    }
  }

  public global::System.Collections.Generic.ICollection<$typemap(cstype, T)> Values
  {
    get
    {
      int startCount = Count;
      Iterator iterator = begin();
      Iterator endIterator = end();

      global::System.Collections.Generic.ICollection<$typemap(cstype, T)> values = new global::System.Collections.Generic.List<$typemap(cstype, T)>();

      while (!iterator.IsEqual(endIterator))
      {
        if (Count != startCount)
        {
          throw new System.InvalidOperationException("Collection was modified; enumeration operation may not execute.");
        }

        values.Add(iterator.GetValue());
        iterator = iterator.MoveNext();
      }

      return values;
    }
  }

  public void Add($typemap(cstype, K) key, $typemap(cstype, T) value)
  {
    if (ContainsKey(key))
    {
      throw new global::System.ArgumentException(nameof(key), "An item with the same key has already been added.");
    }

    InternalSetValue(key, value);
  }

  public void Add(global::System.Collections.Generic.KeyValuePair<$typemap(cstype, K), $typemap(cstype, T)> item)
  {
    Add(item.Key, item.Value);
  }

  bool global::System.Collections.Generic.ICollection<global::System.Collections.Generic.KeyValuePair<$typemap(cstype, K), $typemap(cstype, T)>>.Contains(global::System.Collections.Generic.KeyValuePair<$typemap(cstype, K), $typemap(cstype, T)> keyValuePair)
  {
    return TryGetValue(keyValuePair.Key, out $typemap(cstype, T) value) && value == keyValuePair.Value;
  }

  bool global::System.Collections.Generic.ICollection<global::System.Collections.Generic.KeyValuePair<$typemap(cstype, K), $typemap(cstype, T)>>.Remove(global::System.Collections.Generic.KeyValuePair<$typemap(cstype, K), $typemap(cstype, T)> keyValuePair)
  {
    Iterator iterator = find(keyValuePair.Key);
    if (!iterator.IsEqual(end()) && iterator.GetValue() == keyValuePair.Value)
    {
      InternalRemove(iterator);
      return true;
    }

    return false;
  }

  public void CopyTo(global::System.Collections.Generic.KeyValuePair<$typemap(cstype, K), $typemap(cstype, T)>[] array)
  {
    CopyTo(array, 0);
  }

  public void CopyTo(global::System.Collections.Generic.KeyValuePair<$typemap(cstype, K), $typemap(cstype, T)>[] array, int arrayIndex)
  {
    if (array == null)
      throw new global::System.ArgumentNullException("array");
    if (arrayIndex < 0)
      throw new global::System.ArgumentOutOfRangeException("arrayIndex", "Value is less than zero");
    if (array.Rank > 1)
      throw new global::System.ArgumentException("Multi dimensional array.", "array");
    if (arrayIndex+this.Count > array.Length)
      throw new global::System.ArgumentException("Number of elements to copy is too large.");

    int startCount = Count;
    Iterator iterator = begin();
    Iterator endIterator = end();

    for (int i = 0; i < Count && !iterator.IsEqual(endIterator); i++, iterator = iterator.MoveNext())
    {
      if (Count != startCount)
      {
        throw new System.InvalidOperationException("Collection was modified; enumeration operation may not execute.");
      }

      array.SetValue(new global::System.Collections.Generic.KeyValuePair<$typemap(cstype, K), $typemap(cstype, T)>(iterator.GetKey(), iterator.GetValue()), arrayIndex+i);
    }
  }

  public global::System.Collections.Generic.IEnumerator<global::System.Collections.Generic.KeyValuePair<$typemap(cstype, K), $typemap(cstype, T)>> GetEnumerator()
  {
    int startCount = Count;
    Iterator iterator = begin();
    Iterator endIterator = end();

    while (!iterator.IsEqual(endIterator))
    {
      if (Count != startCount)
      {
        throw new System.InvalidOperationException("Collection was modified; enumeration operation may not execute.");
      }

      yield return new global::System.Collections.Generic.KeyValuePair<$typemap(cstype, K), $typemap(cstype, T)>(iterator.GetKey(), iterator.GetValue());
      iterator = iterator.MoveNext();
    }
  }

  global::System.Collections.IEnumerator global::System.Collections.IEnumerable.GetEnumerator()
  {
    return GetEnumerator();
  }
%}

  public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef K key_type;
    typedef T mapped_type;
    typedef std::pair< const K, T > value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;

    unordered_map();
    unordered_map(const unordered_map& other);

    struct iterator {
      %typemap(csclassmodifiers) iterator "private class"
      %extend {
        std::unordered_map< K, T >::iterator MoveNext() {
          return std::next(*$self);
        }

        bool IsEqual(iterator other) const {
          return (*$self == other);
        }

        K GetKey() const {
          return (*$self)->first;
        }

        T GetValue() const {
          return (*$self)->second;
        }

        void SetValue(const T& newValue) {
          (*$self)->second = newValue;
        }
      }
    };

    %rename(Clear) clear;

    size_t size();
    void clear();
    iterator find(const K& key);
    iterator begin();
    iterator end();

    %extend {
      bool ContainsKey(const K& key) {
        return (self->count(key) > 0);
      }

      void InternalSetValue(const K& key, const T& value) {
        (*self)[key] = value;
      }

      void InternalRemove(const std::unordered_map< K, T >::iterator itr) {
        self->erase(itr);
      }
    }
};

}

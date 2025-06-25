

namespace ireclib {
  // Template alias for compatibility with clients using old ireclib::scoped_ptr
  // Old scoped_ptr implementation is removed completely
  // This alias may fail in some reference deduction cases
  
  template <class T, class Deleter = std::default_delete<T> >
  using scoped_ptr = std::unique_ptr<T, Deleter>;

}


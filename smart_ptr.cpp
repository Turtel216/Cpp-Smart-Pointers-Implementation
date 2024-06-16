

namespace dimi
{

// Smart pointer that deletes itself when going out of scope
template<typename T>
class auto_ptr 
{
private:
  T* ptr; // Actual pointer

  explicit auto_ptr(T* given_ptr = nullptr): ptr(given_ptr) {};

  ~auto_ptr() { delete (ptr); }

  T& operator*() {return *ptr; }

  T* operator->() { return ptr; }

  T* operator+(int num) { return ptr + num; }

  void operator++() { ptr = ptr + 1; }
};

}

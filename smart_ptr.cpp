// namespace containing all my smart pointer implementations
#include <cstdio>
namespace dm
{

template <typename T>
class unique_ptr 
{
private:
  T* ptr; // Actual pointer

public:
  explicit unique_ptr(T* given_ptr = nullptr) noexcept
    : ptr(given_ptr) {};

  ~unique_ptr() noexcept { delete ptr; }

  // OPERATOR OVERLOADS
  T& operator*() const noexcept {return *ptr; } // access to the managed object

  T& operator->() const noexcept { return *ptr; } // access to the manged object

  // transfer ownership to another auto_ptr
  unique_ptr& operator=(unique_ptr<T>& r) noexcept 
  {
    delete ptr;
    ptr = r.get(); 
  }

  // transfer ownership to another auto_ptr
  unique_ptr& operator=(const unique_ptr<T>& r) noexcept 
  {
    delete ptr;
    ptr = r.get(); 
  }

  // Checks whether *this owns an object
  explicit operator bool() const noexcept { return ptr != nullptr; }

  // Indexed access to the managed array
  T operator[](int num) { return ptr[num]; }
  
  // METHODS
  // Retruns pointer to the managed object or nullptr
  T* get() const { return ptr; }

  // Releases the ownership of the managed object
  void release() { delete ptr; }

  // Replaces the managed object
  void reset(T* new_ptr) noexcept 
  {
    auto old_ptr = ptr;
    ptr = new_ptr;
    delete old_ptr;

    if (old_ptr) printf("todo"); //TODO delete the previously managed object
  }

  void swap(unique_ptr& other) noexcept
  {
    auto tmp = this;
    this = other;
    other = tmp;
  }
};
}

// namespace containing all my smart pointer implementations
#include <cstdio>
namespace dm
{

// UNIQUE POINTER

template <typename T>
class unique_ptr 
{
private:
  T* ptr = nullptr; // Actual pointer

public:

  explicit unique_ptr(T* given_ptr = nullptr) noexcept
    : ptr(given_ptr) {}

  explicit unique_ptr() noexcept
    : ptr(nullptr){}

  unique_ptr(const unique_ptr&& other) = delete; // Deletes the move constrator

  unique_ptr(unique_ptr&& right) : ptr(right.release()) {} // Move constrator
  
  ~unique_ptr() noexcept { reset(); }

  // OPERATOR OVERLOADS
  T& operator*() const noexcept {return get(); } // access to the managed object

  T* operator->() const noexcept { return get(); } // access to the manged object

  // transfer ownership to another auto_ptr
  unique_ptr& operator=(unique_ptr<T>& r) noexcept 
  {
    delete ptr;
    ptr = r.get(); 
  }

  // Transfer ownership
  unique_ptr& operator=(unique_ptr&& right)
  {
    reset(right.release());
    return *this;
  }

  // Checks whether *this owns an object
  explicit operator bool() const noexcept { return get() != nullptr; }

  // Indexed access to the managed array
  T operator[](int num) { return ptr[num]; }
  
  // METHODS
  // Retruns pointer to the managed object or nullptr
  T* get() const { return ptr; }

  // Releases the ownership of the managed object
  T* release() 
  {
    auto old_ptr = ptr;
    ptr = nullptr;
    return old_ptr;
  }

  // Replaces the managed object
  void reset(T* new_ptr = nullptr) noexcept 
  {
    auto old_ptr = release();
    ptr = new_ptr;
    if (old_ptr != nullptr)
    {
      delete old_ptr;
    }
  }

  void swap(unique_ptr& other) noexcept
  {
    auto tmp = this->ptr;
    this = other.ptr;
    other.ptr = tmp->ptr;
  }
};

// unique_ptr for array type pointers
template<typename T>
class unique_ptr<T[]>
{
private:
  T* ptr = nullptr; // Actual pointer

public:

  explicit unique_ptr(T* given_ptr = nullptr) noexcept
    : ptr(given_ptr) {}

  explicit unique_ptr() noexcept
    : ptr(nullptr){}

  unique_ptr(const unique_ptr&& other) = delete; // Deletes the move constrator

  unique_ptr(unique_ptr&& right) : ptr(right.release()) {} // Move constrator
  
  ~unique_ptr() noexcept { reset(); }

  // OPERATOR OVERLOADS
  T& operator*() const noexcept {return get(); } // access to the managed object

  T* operator->() const noexcept { return get(); } // access to the manged object

  void operator++() noexcept { ptr = ptr + 1; }

  void operator--() noexcept { ptr = ptr - 1; }

  void operator+(int num) noexcept { ptr = ptr + num; }

  void operator-(int num) noexcept { ptr = ptr - num; }

  // transfer ownership to another auto_ptr
  unique_ptr& operator=(unique_ptr<T>& r) noexcept 
  {
    delete[] ptr;
    ptr = r.get(); 
  }

  // Transfer ownership
  unique_ptr& operator=(unique_ptr&& right)
  {
    reset(right.release());
    return *this;
  }

  // Checks whether *this owns an object
  explicit operator bool() const noexcept { return get() != nullptr; }

  // Indexed access to the managed array
  T operator[](int num) { return ptr[num]; }
  
  // METHODS
  // Retruns pointer to the managed object or nullptr
  T* get() const { return ptr; }

  // Releases the ownership of the managed object
  T* release() 
  {
    auto old_ptr = ptr;
    ptr = nullptr;
    return old_ptr;
  }

  // Replaces the managed object
  void reset(T* new_ptr = nullptr) noexcept 
  {
    auto old_ptr = release();
    ptr = new_ptr;
    if (old_ptr != nullptr)
    {
      delete[] old_ptr;
    }
  }

  void swap(unique_ptr& other) noexcept
  {
    auto tmp = this->ptr;
    this = other.ptr;
    other.ptr = tmp->ptr;
  }
};

// SHARED POINTER
}


// namespace containing all my smart pointer implementations
namespace dimi
{

// Smart pointer that deletes itself when going out of scope
template<typename T>
class auto_ptr 
{
private:
  T* ptr; // Actual pointer

  explicit auto_ptr(T* given_ptr = nullptr) noexcept 
    : ptr(given_ptr) {};

  ~auto_ptr() noexcept { delete (ptr); }

  T& operator*() const noexcept {return *ptr; }

  T* operator->() const noexcept { return ptr; }

  T* operator+(int num) noexcept { return ptr + num; }

  T* operator-(int num) noexcept { return ptr - num; }

  void operator++() noexcept { ptr = ptr + 1; }
};

}

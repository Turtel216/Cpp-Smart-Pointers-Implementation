
// namespace containing all my smart pointer implementations
namespace dm
{

// Smart pointer that deletes itself when going out of scope
template<typename T>
class auto_ptr 
{
private:
  T* ptr; // Actual pointer

public:

  explicit auto_ptr(T* given_ptr = nullptr) noexcept 
    : ptr(given_ptr) {};

  ~auto_ptr() noexcept { delete[] ptr; }

  // OPERATOR OVERLOADS
  T& operator*() const noexcept {return *ptr; }

  T& operator->() const noexcept { return *ptr; }

  T* operator+(int num) noexcept { return ptr + num; }

  T* operator-(int num) noexcept { return ptr - num; }

  T& operator[](int num) const noexcept { return ptr[num]; }

  void operator++() noexcept { ptr = ptr + 1; }
  
  void operator--() noexcept { ptr = ptr - 1; }

  // METHODS
  // Returns a pointer to the managed object
  T* get() const noexcept { return ptr; }

  // Replaces the held pointer with a new object
  void reset(T* new_object = 0) noexcept 
  {
    delete[] ptr;
    ptr = new_object;
  }

  // Releases the held pointer
  void release() noexcept { delete[] ptr; }
};

}

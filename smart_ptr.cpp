
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

  ~auto_ptr() noexcept { delete ptr; }

  // OPERATOR OVERLOADS
  T& operator*() const noexcept {return *ptr; } // access to the managed object

  T& operator->() const noexcept { return *ptr; } // access to the manged object

  auto_ptr& operator=(auto_ptr<T>& r) noexcept { ptr = r.get(); } // transfer ownership from another auto_ptr

  // METHODS
  // Returns a pointer to the managed object
  T* get() const noexcept { return ptr; }

  // Replaces the held pointer with a new object
  void reset(T* new_object = 0) noexcept 
  {
    delete ptr;
    ptr = new_object;
  }

  // Releases the held pointer
  void release() noexcept { delete ptr; }
};

}

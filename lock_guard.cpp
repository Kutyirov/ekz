
template <typename _Mutex>
class lock_guard {
 public:
  typedef _Mutex mutex_type;

  explicit lock_guard(mutex_type& __m) : _M_device(__m) { _M_device.lock(); }

  lock_guard(mutex_type& __m, adopt_lock_t)
      : _M_device(__m) {}  // calling thread owns mutex

  ~lock_guard() { _M_device.unlock(); }

  lock_guard(const lock_guard&) = delete;
  lock_guard& operator=(const lock_guard&) = delete;

 private:
  mutex_type& _M_device;
};

#pragma once

namespace templates {
template <class T> class Singleton {
protected:
  Singleton() {}

public:
  Singleton(Singleton &other) = delete;
  void operator=(const Singleton &other) = delete;
  static T& get_instance() {
    static T instance_;
    return instance_;
  };
};
}

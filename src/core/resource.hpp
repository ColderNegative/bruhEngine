#pragma once

#include <map>
#include <string>
#include <typeindex>

#include "src/templates/singleton.hpp"

namespace core {
class Resource {
public:
  std::string *m_file_path;
  int m_id;

  Resource(std::string *file_path);
};

class ResourceManager : public templates::Singleton<ResourceManager> {
public:
  template <typename T> T *get_resource(std::string *file_path);
  template <typename T> void load_resource(Resource *resource);
  template <typename T> void unload_resource(Resource *resource);

private:
  std::map<std::type_index, std::map<int, Resource *>> m_resources;
};
} // namespace core

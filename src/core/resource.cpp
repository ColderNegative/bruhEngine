#include "src/core/resource.hpp"
#include <string>
#include <functional>

namespace core {

template <typename T>
T* ResourceManager::get_resource(std::string* file_path) {
    std::hash<std::string*> hash;
    return m_resources[typeid(T)][hash(file_path)];
}

template <typename T>
void ResourceManager::load_resource(Resource* resource) {
    auto type_dict = m_resources[typeid(T)];
    type_dict.insert_or_assign(resource->m_id, resource);
}

template <typename T>
void ResourceManager::unload_resource(Resource* resource) {
    auto type_dict = m_resources[typeid(T)];
    type_dict.erase(resource->m_id);
    delete resource;
}

Resource::Resource(std::string* file_path) : m_file_path(file_path) {
    std::hash<std::string*> hash;
    m_id = hash(file_path);
}

}
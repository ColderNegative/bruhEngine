#pragma once

#include "../templates/singleton.hpp"
#include <map>
#include <typeindex>

namespace core {
class Resource {
    public:
        Resource();
        ~Resource();
};

class ResouceManager : public templates::Singleton<ResouceManager> {
    public:
        template <typename T> T* get_resource();
        template <typename T> void load_resource(T* resource);
        template <typename T> void unload_resource(T* resource);
    private:
        std::map<std::type_index, std::map<std::string, Resource*>> resources;
};
}

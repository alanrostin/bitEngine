#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#include <map>
#include <memory>
#include <string>

template<typename T>
class ResourceManager
{
    public:
        int addResource(const std::string& filePath)
        {
            auto it = resources.find(filePath);
            if (it != resources.end())
            {
                return it -> second.first;
            }

            std::shared_ptr<T> resource = std::make_shared<T>();
            if (!resource -> loadFromFile(filePath))
            {
                return -1;
            }

            resources.insert(std::make_pair(filePath, 
                std::make_pair(currentId, resource)));

            return currentId++;
        }

        void removeResource(int id)
        {
            for (auto it = resources.begin(); it != resources.end(); ++it)
            {
                if (it -> second.first = id)
                {
                    resources.erase(it -> first);
                }
            }
        }

        std::shared_ptr<T> getResource(int id)
        {
            for (auto it = resources.begin(); it != resources.end(); ++it)
            {
                if (it -> second.first == id)
                {
                    return it -> second.second;
                }
            }

            return nullptr;
        }

        bool hasResource(int id)
        {
            return (getResource(id) != nullptr);
        }

    private:
        int currentId;
        std::map<std::string, std::pair<int, std::shared_ptr<T>>> resources;
};

#endif
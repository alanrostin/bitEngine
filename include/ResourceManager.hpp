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
                return it -> seccond.first;
            }

            std::shared_ptr<T> resources = std::make_shared<T>();
            if (!resources -> loadFromFile(filePath))
            {
                return -1;
            }

            resources.insert(std::make_pair(filePath, 
                std::make_pair(currentId, resource)));

            return currentId;
        }

        void removeResource(int resourceId)
        {
            for (auto it = resources.begin(); it != resources.end(); ++it)
            {
                if (it -> second.first = resourceId)
                {
                    resources.erase(it -> first);
                }
            }
        }

        std::shared_ptr<T> getResource(int resourceId)
        {
            for (auto it = resources.begin(); it != resources.end(); ++it)
            {
                if (it -> second.first == resourceId)
                {
                    return it -> second.second;
                }
            }

            return nullptr;
        }

        bool hasResource(int resourceId)
        {
            return (getResource(resourceId) != nullptr);
        }

    private:
        int currentId;
        std::map<std::string, std::pair<int, std::shared_ptr<t>>> resources;
};

#endif
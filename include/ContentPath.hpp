#ifndef RESOURCE_PATH_HPP
#define RESOURCE_PATH_HPP

#include <string>

class ContentPath
{
    public:
        ContentPath();
        inline const std::string& getPath()
        {
            return path;
        }

    private:
        std::string path;
};

#endif
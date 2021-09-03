#ifndef RESOURCE_PATH_HPP
#define RESOURCE_PATH_HPP

// #include <iostream>
#include <string>
// #include <filesystem>
#include <unistd.h>

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
#ifndef Tile_h
#define Tile_h

#include "ResourceManager.hpp"

// Store common tile data
struct TileInfo
{
    TileInfo() : tileId(-1)
    {

    }

    TileInfo(int textureId, unsigned int tileId, sf::IntRect textureRect) 
        : textureId(textureId), tileId(tileId), textureRect(textureRect)
    {

    }

    int tileId;
    int textureId;
    sf::IntRect textureRect;
};

struct Tile
{
    std::shared_ptr<TileInfo> tileProperties;
    int x;
    int y;
};

#endif

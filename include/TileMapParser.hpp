#ifndef TileMapParser_hpp
#define TileMapParser_hpp

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <map>
#include <sstream>
#include <iostream>

#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "Tile.h"
#include "Utilities.h"
#include "Object.hpp"
#include "SpriteComponent.hpp"

using namespace rapidxml;

struct TileSheetData
{
    int textureId;
    sf::Vector2u imageSize;
    int tileSheetColumns;
    int tileSheetRows;
    sf::Vector2u tileSize;
};

struct TiledLayer
{
    std::vector<std::shared_ptr<Tile>> tiles;
    bool isVisible;
};

// Store layer names
using MapTiles = std::map<std::string, std::shared_ptr<TiledLayer>>;

// Store different tile types that can be used
using TileSet = std::unordered_map<unsigned int, std::shared_ptr<TileInfo>>;
using TileSheets = std::map<int, std::shared_ptr<TileSheetData>>;

class TileMapParser
{
    public:
        TileMapParser(ResourceManager<sf::Texture>& textureManager);
        std::vector<std::shared_ptr<Object>> parse(const std::string& tileMapFile, sf::Vector2i offset);
    
    private:
        std::shared_ptr<TileSheets> buildTileSheetData(xml_node<>* rootNode);
        std::shared_ptr<MapTiles> buildMapTiles(xml_node<>* rootNode);
        std::pair<std::string, std::shared_ptr<TiledLayer>> 
            buildLayer(xml_node<>* layerNode, std::shared_ptr<TileSheets> tileSheets);
        ResourceManager<sf::Texture>& textureManager;
};

#endif
#include "TileMapParser.hpp"

TileMapParser::TileMapParser(ResourceManager<sf::Texture>& textureManager) 
    : textureManager(textureManager)
{

}

std::vector<std::shared_ptr<Object>> TileMapParser::parse(const std::string& tileMapFile, sf::Vector2i offset)
{
    char* fileLocation = new char[tileMapFile.size() + 1];

    rapidxml::file<> xmlFile(fileLocation);
    rapidxml::xml_document<> xmlDoc;
    xmlDoc.parse<0>(xmlFile.data());
    xml_node<>* rootNode = xmlDoc.first_node("map");

    // Loat tile layers from XML
    std::shared_ptr<MapTiles> tiles = buildMapTiles(rootNode);

    // Calculate the tiles position in world space
    int tileSizeX = std::atoi(rootNode -> first_attribute("tilewidth") -> value());
    int tileSizeY = std::atoi(rootNode -> first_attribute("tileheight") -> value());
    int mapSizeX = std::atoi(rootNode -> first_attribute("width") -> value());
    int mapSizeY = std::atoi(rootNode -> first_attribute("height") -> value());

    std::vector<std::shared_ptr<Object>> tileObjects;

    int layerCount = tiles -> size() - 1;

    for (const auto& layer : *tiles)
    {
        for (const auto& tile : *layer.second)
        {
            std::shared_ptr<TileInfo> tileInfo = tile -> tileProperties;
            std::shared_ptr<Object> tileObject = std::make_shared<Object>();

            const unsigned int tileScale = 3;

            // Allocate sprite
            auto sprite = tileObject -> addComponent<SpriteComponent>();
            sprite -> setTextureManager(&textureManager);
            sprite -> load(tileInfo -> textureId);
            sprite -> setTextureRect(tileInfo -> textureRect);
            sprite -> setScale(tileScale, tileScale);
            sprite -> setSortOrder(layerCount);

            // Calculate world position
            float x = tile -> x * tileSizeX * tileScale + offset.x;
            float y = tile -> y * tileSizeY * tileScale + offset.y;
            tileObject -> transform -> setPosition(x, y);

            // Add new tile Object to the collection
            tileObjects.emplace_back(tileObject);
        }

        layerCount--;
    }

    return tileObjects;
}

std::shared_ptr<MapTiles> TileMapParser::buildMapTiles(xml_node<>* rootNode)
{
    std::shared_ptr<TileSheets> tileSheetData = buildTileSheetData(rootNode);
    std::shared_ptr<MapTiles> map = std::make_shared<MapTiles>();

    // Loop through each layer in the XML document.
    for (xml_node<>* node = rootNode -> first_node("layer"); 
        node; node = node -> next_sibling())
    {
        std::pair<std::string, std::shared_ptr<TiledLayer>> mapLayer 
            = buildLayer(node, tileSheetData);
        map -> emplace(mapLayer);
    }

    return map;
}

std::shared_ptr<TileSheets> TileMapParser::buildTileSheetData(xml_node<> *rootNode)
{
    TileSheets tileSheets;

    for (xml_node<>* tilesheetNode = rootNode -> first_node("tileset"); 
        tilesheetNode; tilesheetNode = tilesheetNode -> next_sibling("tileset"))
    {
        TileSheetData tileSheetData;

        // TODO: add error checking to ensure these values actually exist.
        int firstgid = std::atoi(tilesheetNode -> first_attribute("firstgid") -> value());
        tileSheetData.tileSize.x = std::atoi(tilesheetNode -> first_attribute("tilewidth") -> value());
        tileSheetData.tileSize.y = std::atoi(tilesheetNode -> first_attribute("tileheight") -> value());
        int tileCount = std::atoi(tilesheetNode -> first_attribute("tilecount") -> value());
        tileSheetData.tileSheetColumns = std::atoi(tilesheetNode -> first_attribute("columns") -> value());
        tileSheetData.tileSheetRows = tileCount / tileSheetData.tileSheetColumns;

        xml_node<>* imageNode = tilesheetNode -> first_node("image");
        tileSheetData.textureId = textureManager.addResource(
            std::string(imageNode -> first_attribute("source") -> value()));
        
        tileSheetData.imageSize.x = std::atoi(imageNode -> first_attribute("width") -> value());
        tileSheetData.imageSize.y = std::atoi(imageNode -> first_attribute("height") -> value());

        tileSheets.insert(std::make_pair(firstgid, std::make_shared<TileSheetData>(tileSheetData)));
    }

    return std::make_shared<TileSheets>(tileSheets);
}

std::pair<std::string, std::shared_ptr<TiledLayer>> 
    TileMapParser::buildLayer(xml_node<>* layerNode, std::shared_ptr<TileSheets> tileSheets)
{
    TileSet tileSet;
    std::shared_ptr<TiledLayer> layer = std::make_shared<TiledLayer>();

    int width = std::atoi(layerNode -> first_attribute("width") -> value());
    int height = std::atoi(layerNode -> first_attribute("height") -> value());

    xml_node<>* dataNode = layerNode -> first_node("data");
    char* mapIndices = dataNode -> value();
    std::stringstream fileStream(mapIndices);

    int count = 0;
    std::string line;

    while (fileStream.good())
    {
        std::string substr;
        std::getline(fileStream, substr, ',');

        if (!Utilities::isInteger(substr))
        {
            substr.erase(std::remove(substr.begin(), substr.end(), '\r'), substr.end());
            substr.erase(std::remove(substr.begin(), substr.end(), '\n'), substr.end());
        }

        int tileId = std::stoi(substr);

        if (tileId != 0)
        {
            auto itr = tileSet.find(tileId);

            if (itr == tileSet.end())
            {
                std::shared_ptr<TileSheetData> tileSheet;

                for (auto iter = tileSheets -> rbegin(); iter != tileSheets -> rend(); ++iter)
                {
                    if (tileId >= iter -> first)
                    {
                        tileSheet = iter -> second;
                        break;
                    }
                }

                if (!tileSheet)
                {
                    continue;
                }

                int textureX = tileId % tileSheet -> tileSheetColumns - 1;
                int textureY = tileId / tileSheet -> tileSheetColumns;

                std::shared_ptr<TileInfo> tileInfo = std::make_shared<TileInfo>(
                    tileSheet -> textureId, tileId, sf::IntRect(textureX * tileSheet -> tileSize.x, 
                    textureY * tileSheet -> tileSize.y, tileSheet -> tileSize.x, tileSheet -> tileSize.y));
                
                itr = tileSet.insert(std::make_pair(tileId, tileInfo)).first;
            }

            std::shared_ptr<Tile> tile = std::make_shared<Tile>();
            tile -> tileProperties = itr -> second;
            tile -> x = count % width - 1;
            tile -> y = count / width;
            layer -> emplace_back(tile);
        }

        count++;
    }

    const std::string layerName = layerNode -> first_attribute("name") -> value();

    return std::make_pair(layerName, layer);
}
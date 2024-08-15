/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "Map.hpp"

Map::Map(std::shared_ptr<Asio> asio, std::shared_ptr<GameData> gameData) : _asio(asio), _gameData(gameData)
{
    this->_mapModel = LoadModelFromMesh(GenMeshPlane(100.0f, 100.0f, 100, 100));
    this->_mapTexture = LoadTexture("../assets/plateform2.png");
    this->_mapModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->_mapTexture;
}

Map::~Map()
{
    ;
}

void Map::drawMap()
{
    DrawModel(this->_mapModel, (Vector3){0.0f, -3.0f, 0.0f}, 1.0f, WHITE);
    DrawModel(this->_mapModel, (Vector3){-3.0f, 0.0f, 3.0f}, 0.02f, RED);
}
/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "PlayerRender.hpp"
#include "raymath.h"

PlayerRender::PlayerRender(std::shared_ptr<GameData> gameData) : _gameData(gameData)
{
    _playerModel = LoadModel("../assets/Astronaut.iqm");
    _playerModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture("../assets/AstronautColor.png");
    _playerModel.transform = MatrixRotateXYZ((Vector3){-90.0 * (M_PI / 180), 0.0, 0.0});
}

PlayerRender::~PlayerRender()
{
}

void PlayerRender::drawPlayer()
{
    for (auto &player : _gameData->players_online) {
        // DrawModel(_playerModel, (Vector3){player.second.posx, player.second.posy, player.second.posz}, 1.0f, WHITE);
        DrawModelEx(_playerModel, (Vector3){player.second.posx, player.second.posy, player.second.posz}, (Vector3){0.0f, 1.0f, 0.0f}, player.second.rotx, (Vector3){1.0f, 1.0f, 1.0f}, WHITE);
    }
}
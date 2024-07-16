/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "PlayerRender.hpp"

PlayerRender::PlayerRender(std::shared_ptr<GameData> gameData) : _gameData(gameData)
{
    Mesh mesh = GenMeshCube(1.0f, 1.0f, 1.0f);
    _playerModel = LoadModelFromMesh(mesh);
}

PlayerRender::~PlayerRender()
{
}

void PlayerRender::drawPlayer()
{
    for (auto &player : _gameData->players_online) {
        DrawModel(_playerModel, (Vector3){player.second.posx, player.second.posy, player.second.posz}, 1.0f, RED);
    }
}
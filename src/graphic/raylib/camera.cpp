/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "Raylib.hpp"

RenderCamera::RenderCamera(std::shared_ptr<GameData> gameData) : _gameData(gameData)
{
    _camera = std::make_unique<Camera3D>();
    _camera->position.x = _gameData->player.posx;
    _camera->position.y = _gameData->player.posy;
    _camera->position.z = _gameData->player.posz;
    _camera->target = (Vector3){ 10.0f, 0.0f, 0.0f };
    _camera->up = (Vector3){ 0.0f, 1.0f, 0.0f };
    _camera->fovy = 90.0f;
    _camera->projection = CAMERA_PERSPECTIVE;
}

RenderCamera::~RenderCamera()
{
}

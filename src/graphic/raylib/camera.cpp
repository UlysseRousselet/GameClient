/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "Raylib.hpp"

RenderCamera::RenderCamera(std::shared_ptr<GameData> gameData) : _gameData(gameData)
{
    _camera.position = (Vector3){ 0.0f, 0.0f, 10.0f };
    _camera.target = (Vector3){ 10.0f, 0.0f, 0.0f };
    _camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    _camera.fovy = 90.0f;
    _camera.projection = CAMERA_PERSPECTIVE;
}

RenderCamera::~RenderCamera()
{
}
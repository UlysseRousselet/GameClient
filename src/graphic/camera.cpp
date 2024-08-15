/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "Graphic.hpp"

RenderCamera::RenderCamera(std::shared_ptr<GameData> gameData) : _gameData(gameData)
{
    _camera.position.x = _gameData->player.posx;
    _camera.position.y = _gameData->player.posy + 0.5;
    _camera.position.z = _gameData->player.posz;
    _camera.target = (Vector3){ 10.0f, 0.5f, 0.0f };
    _camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    _camera.fovy = 90.0f;
    _camera.projection = CAMERA_PERSPECTIVE;
    HideCursor();
}

RenderCamera::~RenderCamera()
{
}


/*
* Update camera with the position of the player
*/
void RenderCamera::update()
{
    _camera.position.x = _gameData->player.posx;
    _camera.position.y = _gameData->player.posy + 0.5;
    _camera.position.z = _gameData->player.posz;
    _camera.target.x = _gameData->player.posx + cos(_gameData->player.rotx);
    _camera.target.z = _gameData->player.posz + sin(_gameData->player.rotx);
    _camera.target.y = _gameData->player.posy + 0.5;
}
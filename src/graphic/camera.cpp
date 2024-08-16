/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "Graphic.hpp"

RenderCamera::RenderCamera(std::shared_ptr<GameData> gameData) : _gameData(gameData)
{
    _gameData->camera.position.x = _gameData->player.posx;
    _gameData->camera.position.y = _gameData->player.posy + 0.5;
    _gameData->camera.position.z = _gameData->player.posz;
    _gameData->camera.target = (Vector3){ 10.0f, 0.5f, 0.0f };
    _gameData->camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    _gameData->camera.fovy = 90.0f;
    _gameData->camera.projection = CAMERA_PERSPECTIVE;
    //HideCursor();
    //DisableCursor();
}

RenderCamera::~RenderCamera()
{
}


/*
* Update camera with the position of the player
*/
void RenderCamera::update()
{
    _gameData->camera.position.x = _gameData->player.posx;
    _gameData->camera.position.y = _gameData->player.posy + 0.5;
    _gameData->camera.position.z = _gameData->player.posz;
    _gameData->camera.target.x = _gameData->player.posx + cos(_gameData->player.rotx);
    _gameData->camera.target.z = _gameData->player.posz + sin(_gameData->player.rotx);
    _gameData->camera.target.y = _gameData->player.posy + 0.5;
}
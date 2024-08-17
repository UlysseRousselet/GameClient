/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "Graphic.hpp"

RenderCamera::RenderCamera(std::shared_ptr<GameData> gameData)
{
    gameData->camera.position.x = gameData->player.posx;
    gameData->camera.position.y = gameData->player.posy + 0.75f;
    gameData->camera.position.z = gameData->player.posz;
    gameData->camera.target = (Vector3){ 10.0f, 0.75f, 0.0f };
    gameData->camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    gameData->camera.fovy = 90.0f;
    gameData->camera.projection = CAMERA_PERSPECTIVE;
    //HideCursor();
    //DisableCursor();
}

RenderCamera::~RenderCamera()
{
}


/*
* Update camera with the position of the player
*/
void RenderCamera::update(std::shared_ptr<GameData> gameData)
{
    gameData->camera.position.x = gameData->player.posx;
    gameData->camera.position.y = gameData->player.posy + 0.75f;
    gameData->camera.position.z = gameData->player.posz;
    gameData->camera.target.x = gameData->player.posx + cos(gameData->player.rotx);
    gameData->camera.target.z = gameData->player.posz + sin(gameData->player.rotx);
    gameData->camera.target.y = gameData->player.posy + 0.75f;
}
/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "EventHandler.hpp"

void EventHandler::eventFirstPerson()
{
    bool asMoved = false;
    if (IsKeyDown(KEY_W)) {
        // UpdateCameraPro(&camera._camera, (Vector3){GetFrameTime() * 15, 0.0f, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
        _gameData->player.posx += GetFrameTime() * cos(_gameData->player.rotx);
        _gameData->player.posz += GetFrameTime() * sin(_gameData->player.rotx);
        asMoved = true;
    }
    if (IsKeyDown(KEY_S)) {
        _gameData->player.posx -= GetFrameTime() * cos(_gameData->player.rotx);
        _gameData->player.posz -= GetFrameTime() * sin(_gameData->player.rotx);
        asMoved = true;
    }
    if (IsKeyDown(KEY_A)) {
        _gameData->player.posx += GetFrameTime() * cos(_gameData->player.rotx - PI / 2);
        _gameData->player.posz += GetFrameTime() * sin(_gameData->player.rotx - PI / 2);
        asMoved = true;
    }
    if (IsKeyDown(KEY_D)) {
        _gameData->player.posx += GetFrameTime() * cos(_gameData->player.rotx + PI / 2);
        _gameData->player.posz += GetFrameTime() * sin(_gameData->player.rotx + PI / 2);
        asMoved = true;
    }
    // if (IsKeyDown(KEY_SPACE))
    //     UpdateCameraPro(&camera._camera, (Vector3){0.0f, 0.0f, GetFrameTime() * 15}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
    // if (IsKeyDown(KEY_LEFT_SHIFT))
    //     UpdateCameraPro(&camera._camera, (Vector3){0.0f, 0.0f, -GetFrameTime() * 15}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
    if (IsKeyDown(KEY_LEFT)) {
        _gameData->player.rotx -= GetFrameTime();
        asMoved = true;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        _gameData->player.rotx += GetFrameTime();
        asMoved = true;
    }

    // if (IsKeyDown(KEY_UP))
    //     UpdateCameraPro(&camera._camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, -GetFrameTime() * 30, 0.0f}, 0.0f);
    // if (IsKeyDown(KEY_DOWN))
    //     UpdateCameraPro(&camera._camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, GetFrameTime() * 30, 0.0f}, 0.0f);
    //UpdateCameraPro(&camera._camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f}, -GetMouseWheelMove()*2.0f);
    //UpdateCameraPro(&camera._camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){GetMouseDelta().x*0.05f, GetMouseDelta().y*0.05f, 0.0f}, 0.0f);
    if (GetMouseDelta().x != 0) {
        _gameData->player.rotx += GetMouseDelta().x * _gameData->settings.sensitivity;
        asMoved = true;
    }
    
    if (asMoved) {
        RenderCamera::update(_gameData);

        _asio->send_packet({3, {_gameData->player.posx, _gameData->player.posy, _gameData->player.posz, _gameData->player.rotx, 0}});
    }
}

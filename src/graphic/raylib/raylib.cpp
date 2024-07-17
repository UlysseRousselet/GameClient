/*
** EPITECH PROJECT, 2024
** game client
** File description:
** main
*/

#include "Raylib.hpp"

Raylib::Raylib(std::shared_ptr<Asio> asio, std::shared_ptr<GameData> gameData) : asio(asio), gameData(gameData), window(), camera(gameData), playerRender(gameData), map(asio, gameData)
{
    ;
}

Raylib::~Raylib()
{
}

void Raylib::handleKeyEvent()
{
    bool asMoved = false;
    if (IsKeyDown(KEY_W)) {
        UpdateCameraPro(camera._camera.get(), (Vector3){GetFrameTime() * 15, 0.0f, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
        asMoved = true;
    }
    if (IsKeyDown(KEY_S)) {
        UpdateCameraPro(camera._camera.get(), (Vector3){-GetFrameTime() * 15, 0.0f, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
        asMoved = true;
    }
    if (IsKeyDown(KEY_A)) {
        UpdateCameraPro(camera._camera.get(), (Vector3){0.0f, -GetFrameTime() * 15, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
        asMoved = true;
    }
    if (IsKeyDown(KEY_D)) {
        UpdateCameraPro(camera._camera.get(), (Vector3){0.0f, GetFrameTime() * 15, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
        asMoved = true;
    }
    // if (IsKeyDown(KEY_SPACE))
    //     UpdateCameraPro(camera._camera.get(), (Vector3){0.0f, 0.0f, GetFrameTime() * 15}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
    // if (IsKeyDown(KEY_LEFT_SHIFT))
    //     UpdateCameraPro(camera._camera.get(), (Vector3){0.0f, 0.0f, -GetFrameTime() * 15}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
    if (IsKeyDown(KEY_LEFT))
        UpdateCameraPro(camera._camera.get(), (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){-GetFrameTime() * 30, 0.0f, 0.0f}, 0.0f);
    if (IsKeyDown(KEY_RIGHT))
        UpdateCameraPro(camera._camera.get(), (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){GetFrameTime() * 30, 0.0f, 0.0f}, 0.0f);
    if (IsKeyDown(KEY_UP))
        UpdateCameraPro(camera._camera.get(), (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, -GetFrameTime() * 30, 0.0f}, 0.0f);
    if (IsKeyDown(KEY_DOWN))
        UpdateCameraPro(camera._camera.get(), (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, GetFrameTime() * 30, 0.0f}, 0.0f);
    UpdateCameraPro(camera._camera.get(), (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f}, -GetMouseWheelMove()*2.0f);
    UpdateCameraPro(camera._camera.get(), (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){GetMouseDelta().x*0.05f, GetMouseDelta().y*0.05f, 0.0f}, 0.0f);

    if (asMoved) {
        gameData->player.posx = camera._camera->position.x;
        gameData->player.posy = camera._camera->position.y;
        gameData->player.posz = camera._camera->position.z;
        asio->send_packet({3, {camera._camera->position.x, camera._camera->position.y, camera._camera->position.z, 0, 0}});
    }
}

void Raylib::render()
{
    BeginDrawing();
    ClearBackground(BLUE);
    DrawText("test", 190, 200, 20, LIGHTGRAY);

    BeginMode3D(*camera._camera);
    this->playerRender.drawPlayer();
    this->map.drawMap();
    EndMode3D();

    EndDrawing();
    // std::cout << "GameData posx: " << gameData->player.posx << std::endl;
    // std::cout << "Camera posx: " << camera._camera->position.x << std::endl;
}
/*
** EPITECH PROJECT, 2024
** game client
** File description:
** main
*/

#include "Graphic.hpp"

Graphic::Graphic(std::shared_ptr<Asio> asio, std::shared_ptr<GameData> gameData) : asio(asio), gameData(gameData), window(), camera(gameData), playerRender(gameData), map(asio, gameData)
{
    loop();
}

Graphic::~Graphic()
{
}

void Graphic::handleKeyEvent()
{
    bool asMoved = false;
    if (IsKeyDown(KEY_W)) {
        // UpdateCameraPro(&camera._camera, (Vector3){GetFrameTime() * 15, 0.0f, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
        gameData->player.posx += GetFrameTime() * cos(gameData->player.rotx);
        gameData->player.posz += GetFrameTime() * sin(gameData->player.rotx);
        asMoved = true;
    }
    if (IsKeyDown(KEY_S)) {
        gameData->player.posx -= GetFrameTime() * cos(gameData->player.rotx);
        gameData->player.posz -= GetFrameTime() * sin(gameData->player.rotx);
        asMoved = true;
    }
    if (IsKeyDown(KEY_A)) {
        gameData->player.posx += GetFrameTime() * cos(gameData->player.rotx - PI / 2);
        gameData->player.posz += GetFrameTime() * sin(gameData->player.rotx - PI / 2);
        asMoved = true;
    }
    if (IsKeyDown(KEY_D)) {
        gameData->player.posx += GetFrameTime() * cos(gameData->player.rotx + PI / 2);
        gameData->player.posz += GetFrameTime() * sin(gameData->player.rotx + PI / 2);
        asMoved = true;
    }
    // if (IsKeyDown(KEY_SPACE))
    //     UpdateCameraPro(&camera._camera, (Vector3){0.0f, 0.0f, GetFrameTime() * 15}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
    // if (IsKeyDown(KEY_LEFT_SHIFT))
    //     UpdateCameraPro(&camera._camera, (Vector3){0.0f, 0.0f, -GetFrameTime() * 15}, (Vector3){0.0f, 0.0f, 0.0f}, 0.0f);
    if (IsKeyDown(KEY_LEFT)) {
        gameData->player.rotx -= GetFrameTime();
        asMoved = true;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        gameData->player.rotx += GetFrameTime();
        asMoved = true;
    }

    // if (IsKeyDown(KEY_UP))
    //     UpdateCameraPro(&camera._camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, -GetFrameTime() * 30, 0.0f}, 0.0f);
    // if (IsKeyDown(KEY_DOWN))
    //     UpdateCameraPro(&camera._camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, GetFrameTime() * 30, 0.0f}, 0.0f);
    //UpdateCameraPro(&camera._camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f}, -GetMouseWheelMove()*2.0f);
    //UpdateCameraPro(&camera._camera, (Vector3){0.0f, 0.0f, 0.0f}, (Vector3){GetMouseDelta().x*0.05f, GetMouseDelta().y*0.05f, 0.0f}, 0.0f);
    if (GetMouseDelta().x != 0) {
        asMoved = true;
    }
    
    if (asMoved) {
        camera.update();

        asio->send_packet({3, {gameData->player.posx, gameData->player.posy, gameData->player.posz, gameData->player.rotx, 0}});
    }
}

void Graphic::render()
{
    BeginDrawing();
    ClearBackground(Color{0, 0, 255, 255});
    

    BeginMode3D(camera._camera);
    this->playerRender.drawPlayer();
    this->map.drawMap();
    EndMode3D();
    DrawText("test", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
}

void Graphic::loop()
{
    while (!WindowShouldClose())
    {
        handleKeyEvent();

        render();
    }
}
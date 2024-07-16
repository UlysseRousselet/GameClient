/*
** EPITECH PROJECT, 2024
** game client
** File description:
** main
*/

#include "Raylib.hpp"

Raylib::Raylib(std::shared_ptr<Asio> asio, std::shared_ptr<GameData> gameData) : asio(asio), gameData(gameData), window(), camera(gameData), playerRender(gameData)
{
    ;
}

Raylib::~Raylib()
{
}

void Raylib::handleKeyEvent()
{
    ;
}

void Raylib::render()
{
    BeginDrawing();
    ClearBackground(BLUE);
    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

    BeginMode3D(*camera._camera);
    this->playerRender.drawPlayer();
    EndMode3D();

    EndDrawing();
    std::cout << "GameData posx: " << gameData->player.posx << std::endl;
    std::cout << "Camera posx: " << camera._camera->position.x << std::endl;
}
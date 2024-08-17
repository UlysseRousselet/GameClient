/*
** EPITECH PROJECT, 2024
** game client
** File description:
** main
*/

#include "Graphic.hpp"

Graphic::Graphic(std::shared_ptr<Asio> asio, std::shared_ptr<GameData> gameData) : asio(asio), gameData(gameData), window(), camera(gameData), playerRender(gameData), map(asio, gameData), settings(gameData), event(asio, gameData)
{
    loop();
}

Graphic::~Graphic()
{
}

void Graphic::render()
{
    BeginDrawing();
    ClearBackground(Color{0, 0, 255, 255});
    

    BeginMode3D(gameData->camera);
    this->playerRender.drawPlayer();
    this->map.drawMap();
    EndMode3D();
    DrawFPS(10, 10);
    EndDrawing();
}

void Graphic::loop()
{
    while (!WindowShouldClose())
    {
        event.eventGestion();

        render();
    }
}
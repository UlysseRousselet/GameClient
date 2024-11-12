/*
** EPITECH PROJECT, 2024
** game client
** File description:
** main
*/

#include "Graphic.hpp"

Graphic::Graphic(std::shared_ptr<Asio> asio, std::shared_ptr<GameData> gameData) : asio(asio), gameData(gameData), window(), camera(gameData), playerRender(gameData), map(asio, gameData), settings(gameData), event(asio, gameData)
{
    // attend que le client soit connecté. Si après une seconde il ne l'est pas alors le programme s'arrete.
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();

    while (static_cast<std::chrono::duration<double>>(end - start).count() < 2 && gameData->playerState != PlayerState::IN_GAME)
        end = std::chrono::system_clock::now();

    if (gameData->playerState != PlayerState::NOT_CONNECTED)
        this->loop();
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
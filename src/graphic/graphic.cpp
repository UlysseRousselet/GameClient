/*
** EPITECH PROJECT, 2024
** game client
** File description:
** main
*/

#include "Graphic.hpp"

Graphic::Graphic(std::shared_ptr<Asio> asio, std::shared_ptr<GameData> gameData) : asio(asio), gameData(gameData), raylib(asio, gameData)
{
    loop();
}

Graphic::~Graphic()
{
}

void Graphic::loop()
{
    while (!WindowShouldClose())
    {
        raylib.handleKeyEvent();

        raylib.render();
    }
}
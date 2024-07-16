/*
** EPITECH PROJECT, 2024
** game client
** File description:
** main
*/

#include "Graphic.hpp"

Graphic::Graphic(std::shared_ptr<Asio> asio, std::shared_ptr<GameData> gameData) : asio(asio), gameData(gameData), raylib(asio, gameData)
{
    std::thread loop_thread(&Graphic::loop, this);
    loop_thread.join();
}

Graphic::~Graphic()
{
}

void Graphic::loop()
{
    while (true)
    {
        raylib.handleKeyEvent();

        raylib.render();
    }
}
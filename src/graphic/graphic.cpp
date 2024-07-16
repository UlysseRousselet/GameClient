/*
** EPITECH PROJECT, 2024
** game client
** File description:
** main
*/

#include "Graphic.hpp"

Graphic::Graphic(std::shared_ptr<Asio> asio, std::shared_ptr<GameData> gameData) : asio(asio), gameData(gameData)
{
    //mettre dans un thread
    loop();
}

Graphic::~Graphic()
{
}

void Graphic::loop()
{
    while (true)
    {
        ;
    }
}
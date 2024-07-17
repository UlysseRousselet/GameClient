/*
** EPITECH PROJECT, 2024
** Projet perso
** File description:
** main
*/

#include "Command.hpp"

Command::Command(std::shared_ptr<Asio> asio, std::shared_ptr<GameData> gameData)
{
    this->asio = asio;
    this->gameData = gameData;
    _cmdMap.emplace(1, std::bind(&Command::NewConnection, this));
    _cmdMap.emplace(2, std::bind(&Command::OtherPlayerConnection, this));
    _cmdMap.emplace(3, std::bind(&Command::OtherPlayerDisconnection, this));
    _cmdMap.emplace(4, std::bind(&Command::OtherPlayerMove, this));
}

void Command::callCommand()
{
    _cmdMap[asio->answer.id]();
}
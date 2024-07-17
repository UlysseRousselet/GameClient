/*
** EPITECH PROJECT, 2024
** Projet perso
** File description:
** main
*/

#include "Command.hpp"

void Command::OtherPlayerDisconnection()
{
    gameData->players_online.erase(asio->answer.args[0]);
    std::cout << "Other player disconnected" << std::endl;
}
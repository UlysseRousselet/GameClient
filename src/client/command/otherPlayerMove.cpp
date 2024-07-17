/*
** EPITECH PROJECT, 2024
** Projet perso
** File description:
** main
*/

#include "Command.hpp"

void Command::OtherPlayerMove()
{
    gameData->players_online.at(asio->answer.args[0]).posx = asio->answer.args[1];
    gameData->players_online.at(asio->answer.args[0]).posy = asio->answer.args[2];
    gameData->players_online.at(asio->answer.args[0]).posz = asio->answer.args[3];
    std::cout << "Other player moved" << std::endl;
}
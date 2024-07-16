/*
** EPITECH PROJECT, 2024
** Projet perso
** File description:
** main
*/

#include "Command.hpp"

/**
 * Create the client player from the info given by the server
*/
void Command::NewConnection()
{
    gameData->player.id = asio->answer.args[0];
    gameData->player.name = "";
    gameData->player.email = "";
    gameData->player.password = "";
    gameData->player.posx = asio->answer.args[1];
    gameData->player.posy = asio->answer.args[2];
    gameData->player.posz = asio->answer.args[3];
    gameData->player.hp = 100;

    std::cout << "Player client connected" << std::endl;
}
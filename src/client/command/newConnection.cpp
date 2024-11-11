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
    NewConnection_t newConnection;

    memcpy(&newConnection, asio->answer + sizeof(int), sizeof(NewConnection_t));

    gameData->player.id = newConnection.id;
    gameData->player.name = "";
    gameData->player.email = "";
    gameData->player.password = "";
    gameData->player.posx = newConnection.posx;
    gameData->player.posy = newConnection.posy;
    gameData->player.posz = newConnection.posz;
    gameData->player.hp = newConnection.hp;

    std::cout << "Player client connected" << std::endl;
}
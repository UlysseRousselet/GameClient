/*
** EPITECH PROJECT, 2024
** Projet perso
** File description:
** main
*/

#include "Command.hpp"

/**
* Add a new player to the player connected on the scene
*/
void Command::OtherPlayerConnection()
{
    OtherPlayerConnection_t otherPlayer;

    memcpy(&otherPlayer, asio->answer + sizeof(int), sizeof(OtherPlayerConnection_t));

    Player newPlayer;
    newPlayer.id = otherPlayer.id;
    newPlayer.name = "";
    newPlayer.email = "";
    newPlayer.password = "";
    newPlayer.posx = otherPlayer.posx;
    newPlayer.posy = otherPlayer.posy;
    newPlayer.posz = otherPlayer.posz;
    newPlayer.hp = 100;

    gameData->players_online.emplace(newPlayer.id, newPlayer);
    std::cout << "Other player added" << std::endl;
}
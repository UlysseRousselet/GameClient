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
    Player newPlayer;
    newPlayer.id = asio->answer.args[0];
    newPlayer.name = "";
    newPlayer.email = "";
    newPlayer.password = "";
    newPlayer.posx = asio->answer.args[1];
    newPlayer.posy = asio->answer.args[2];
    newPlayer.posz = asio->answer.args[3];
    newPlayer.hp = 100;

    gameData->players_online.emplace(newPlayer.id, newPlayer);
    std::cout << "Other player added" << std::endl;
}
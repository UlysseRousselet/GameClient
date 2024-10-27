/*
** EPITECH PROJECT, 2024
** Projet perso
** File description:
** main
*/

#include "Command.hpp"

void Command::OtherPlayerDisconnection()
{

    OtherPlayerDisconnection_t otherPlayerDisconnection;

    memcpy(&otherPlayerDisconnection, asio->answer + sizeof(int), sizeof(OtherPlayerDisconnection_t));

    gameData->players_online.erase(otherPlayerDisconnection.id);
    std::cout << "Other player disconnected" << std::endl;
}
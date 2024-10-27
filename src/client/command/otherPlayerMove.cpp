/*
** EPITECH PROJECT, 2024
** Projet perso
** File description:
** main
*/

#include "Command.hpp"

void Command::OtherPlayerMove()
{
    OtherPlayerMove_t otherPlayerMove;
    
    memcpy(&otherPlayerMove, asio->answer + sizeof(int), sizeof(OtherPlayerMove_t));

    gameData->players_online.at(otherPlayerMove.id).posx = otherPlayerMove.posx;
    gameData->players_online.at(otherPlayerMove.id).posy = otherPlayerMove.posy;
    gameData->players_online.at(otherPlayerMove.id).posz = otherPlayerMove.posz;
    gameData->players_online.at(otherPlayerMove.id).rotx = otherPlayerMove.rotx;

    std::cout << "Other player moved" << std::endl;
}
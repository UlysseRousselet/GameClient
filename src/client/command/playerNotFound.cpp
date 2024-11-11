/*
** EPITECH PROJECT, 2024
** Projet perso
** File description:
** main
*/

#include "Command.hpp"

void Command::PlayerNotFound()
{
    PlayerNotFound_t playerNotFound;

    memcpy(&playerNotFound, asio->answer + sizeof(int), sizeof(PlayerNotFound_t));

    throw std::runtime_error("Account doesn't exist");
}
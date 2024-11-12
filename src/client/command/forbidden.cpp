/*
** EPITECH PROJECT, 2024
** Projet perso
** File description:
** main
*/

#include "Command.hpp"

void Command::Forbidden()
{
    Forbidden_t playerNotFound;

    memcpy(&playerNotFound, asio->answer + sizeof(int), sizeof(Forbidden_t));

    throw std::runtime_error("A problem occured when connecting to the server");
}
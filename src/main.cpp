/*
** EPITECH PROJECT, 2024
** game client
** File description:
** main
*/

#include "client.hpp"

int main()
{
    Client client("127.0.0.1", "8080");
    try
    {
        client.loop();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
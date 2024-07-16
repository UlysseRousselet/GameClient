/*
** EPITECH PROJECT, 2024
** game client
** File description:
** main
*/

#include "Core.hpp"

int main()
{
    std::shared_ptr<GameData> gameDataPtr = std::make_shared<GameData>();
    std::shared_ptr<Asio> asio_ptr = std::make_shared<Asio>("127.0.0.1", 8080);
    try
    {
        Client client(asio_ptr, gameDataPtr);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
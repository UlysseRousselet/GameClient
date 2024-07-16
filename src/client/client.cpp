/*
** EPITECH PROJECT, 2024
** game client
** File description:
** main
*/

#include "client.hpp"

Client::Client(std::shared_ptr<Asio> asio, std::shared_ptr<GameData> gameData) : asio(asio), gameData(gameData), command(asio, gameData)
{
    //first connection
    asio->send_packet({1, {1.0, 2.0, 3.0, 4.0, 5.0}});

    std::thread loop_thread(&Client::loop, this);
    loop_thread.detach();
}

Client::~Client()
{
}

void Client::loop()
{
    while (true)
    {
        asio->receive_packet();

        //call all the functions
        this->command.callCommand();
    }
}

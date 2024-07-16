/*
** EPITECH PROJECT, 2024
** client
** File description:
** Core
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_

    #include "GameData.hpp"
    #include "Asio.hpp"
    #include <iostream>
    #include <asio.hpp>
    #include <memory>

class Client
{
    public:
        Client(std::shared_ptr<Asio> asio, std::shared_ptr<GameData> gameData);
        ~Client();
        void loop();
    private:
        std::shared_ptr<Asio> asio;
        std::shared_ptr<GameData> gameData;
        
};

#endif /* !CLIENT_HPP_ */
/*
** EPITECH PROJECT, 2024
** server
** File description:
** Core
*/

#ifndef COMMAND_HPP_
    #define COMMAND_HPP_

    #include "GameData.hpp"
    #include "AsioClass.hpp"
    #include <iostream>
    #include <memory>
    #include <map>
    #include <functional>

class Command {
  public:
    Command(std::shared_ptr<Asio> asio, std::shared_ptr<GameData> gameData);
    ~Command() = default;
    void callCommand();
    void NewConnection();
    void OtherPlayerConnection();
    void OtherPlayerDisconnection();
    void OtherPlayerMove();
  private:
    std::map<int, std::function<void()>> _cmdMap;
    std::shared_ptr<Asio> asio;
    std::shared_ptr<GameData> gameData;
};

#endif /* !COMMAND_HPP_ */
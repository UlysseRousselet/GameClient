/*
** EPITECH PROJECT, 2024
** server
** File description:
** Core
*/

#ifndef GAMEDATA_HPP_
    #define GAMEDATA_HPP_

    #include <asio.hpp>
    #include <iostream>
    #include <map>

struct Player {
    int id = 0;
    std::string name;
    std::string email;
    std::string password;
    int hp = 0;
    float posx = 0;
    float posy = 0;
    float posz = 0;
};

struct GameData {
    Player player;                          // The actual player info of the client
    std::map <int, Player> players_online;  // The info of the other players
};

#endif /* !GAMEDATA_HPP_ */
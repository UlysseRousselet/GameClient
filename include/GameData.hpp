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
    int id;
    std::string name;
    std::string email;
    std::string password;
    int hp;
    float posx;
    float posy;
    float posz;
};

struct GameData {
    Player player;                          // The actual player info of the client
    std::map <int, Player> players_online;  // The info of the other players
};

#endif /* !GAMEDATA_HPP_ */
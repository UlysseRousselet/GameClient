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
    std::string name;
    std::string email;
    std::string password;
    int hp;
    float posx;
    float posy;
    float posz;
};

struct GameData {
    std::map <int, Player> players_online;
};

#endif /* !GAMEDATA_HPP_ */
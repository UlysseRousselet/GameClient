/*
** EPITECH PROJECT, 2024
** server
** File description:
** Core
*/

#ifndef GAMEDATA_HPP_
    #define GAMEDATA_HPP_

    #include "raylib.h"

    #include <asio.hpp>
    #include <iostream>
    #include <map>

enum struct PlayerState {
    NOT_CONNECTED,
    IN_GAME,
    IN_MENU
};

//stoque les infos du player client
struct Player {
    int id = 0;
    std::string name;
    std::string email;
    std::string password;
    int hp = 0;
    float posx = 0;
    float posy = 0;
    float posz = 0;
    float rotx = 0;
};

//stoque les parametres
struct Settings {
    float sensitivity;                      // sensi de la souris
    std::map<std::string, int> touchMap;    // mapping des touches
};

struct GameData {
    Player player;                          // The actual player info of the client
    std::map <int, Player> players_online;  // The info of the other players
    Settings settings;                      // Setting like video quality or keybind
    Camera3D camera;                        // The camera of the client player
    PlayerState playerState;                // define if the client is in menu or playing
};

#endif /* !GAMEDATA_HPP_ */
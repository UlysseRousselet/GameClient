/*
** EPITECH PROJECT, 2024
** server
** File description:
** Core
*/

#include <asio.hpp>
#include <variant>

struct Login_t {
    char email[50];
    char password[50];
};

struct Disconnect_t {
    int id;
};

struct Move_t {
    float posx;
    float posy;
    float posz;
    float rotx;
};

struct NewConnection_t {
    int id;
    int hp;
    float posx;
    float posy;
    float posz;
};

struct OtherPlayerConnection_t {
    int id;
    float posx;
    float posy;
    float posz;
};

struct OtherPlayerDisconnection_t {
    int id;
};

struct OtherPlayerMove_t {
    int id;
    float posx;
    float posy;
    float posz;
    float rotx;
};

struct Forbidden_t {
    int id;
};

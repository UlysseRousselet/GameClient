/*
** EPITECH PROJECT, 2024
** server
** File description:
** Core
*/

#ifndef EVENTHANDLER_HPP
    #define EVENTHANDLER_HPP

    #include <raylib.h>

    #include "AsioClass.hpp"
    #include "GameData.hpp"
    #include "Camera.hpp"
    #include "raymath.h"

    #include <iostream>
    #include <memory>

class EventHandler {
    public:
        EventHandler(std::shared_ptr<Asio> asio, std::shared_ptr<GameData> gameData);
        ~EventHandler();
        void eventGestion();
        void eventFirstPerson();
        void eventInMenu();
    protected:
        std::shared_ptr<Asio> _asio;
        std::shared_ptr<GameData> _gameData;
};

#endif /* !EVENTHANDLER_HPP */
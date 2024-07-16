/*
** EPITECH PROJECT, 2024
** server
** File description:
** Core
*/

#ifndef RAYLIB_HPP_
    #define RAYLIB_HPP_

    #include "Asio.hpp"
    #include "GameData.hpp"
    #include "Window.hpp"
    #include <raylib.h>

class Raylib {
    public:
        Raylib(std::shared_ptr<Asio> asio, std::shared_ptr<GameData> gameData);
        ~Raylib();
        void render();
        void handleKeyEvent();
    protected:
        std::shared_ptr<Asio> asio;
        std::shared_ptr<GameData> gameData;
        Window window;
};

#endif /* !RAYLIB_HPP_ */

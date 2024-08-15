/*
** EPITECH PROJECT, 2024
** server
** File description:
** Core
*/

#ifndef RAYLIB_HPP_
    #define RAYLIB_HPP_

    #include "raylib.h"
    #include "raymath.h"

 
    #include "AsioClass.hpp"
    #include "GameData.hpp"
    #include "Window.hpp"
    #include "Camera.hpp"
    #include "PlayerRender.hpp"
    #include "Map.hpp"

class Graphic {
    public:
        Graphic(std::shared_ptr<Asio> asio, std::shared_ptr<GameData> gameData);
        ~Graphic();
        void loop();
        void render();
        void handleKeyEvent();
    protected:
        std::shared_ptr<Asio> asio;
        std::shared_ptr<GameData> gameData;
        Window window;
        RenderCamera camera;
        PlayerRender playerRender;
        Map map;
};

#endif /* !RAYLIB_HPP_ */

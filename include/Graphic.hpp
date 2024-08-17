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
    #include "MapRender.hpp"
    #include "SettingsHandler.hpp"
    #include "EventHandler.hpp"

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
        MapRender map;
        SettingsHandler settings;
        EventHandler event;
};

#endif /* !RAYLIB_HPP_ */

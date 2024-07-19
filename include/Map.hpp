/*
** EPITECH PROJECT, 2024
** server
** File description:
** Core
*/

#ifndef MAP_HPP_
    #define MAP_HPP_

    #include <raylib.h>

    #include "AsioClass.hpp"
    #include "GameData.hpp"
    #include <iostream>
    #include <memory>

class Map {
    public:
        Map(std::shared_ptr<Asio> asio, std::shared_ptr<GameData> gameData);
        ~Map();
        void drawMap();
    protected:
        std::shared_ptr<Asio> _asio;
        std::shared_ptr<GameData> _gameData;
        //pour l'instant
        Model _mapModel;
        Texture2D _mapTexture;
};

#endif /* !MAP_HPP_ */
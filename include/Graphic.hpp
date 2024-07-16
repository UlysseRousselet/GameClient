/*
** EPITECH PROJECT, 2024
** server
** File description:
** Core
*/

#ifndef GRAPHIC_HPP_
    #define GRAPHIC_HPP_

    #include "Asio.hpp"
    #include "GameData.hpp"
    #include "Raylib.hpp"

class Graphic {
    public:
        Graphic(std::shared_ptr<Asio> asio, std::shared_ptr<GameData> gameData);
        ~Graphic();
        void loop();
    protected:
        std::shared_ptr<Asio> asio;
        std::shared_ptr<GameData> gameData;
        Raylib raylib;
};

#endif /* !GRAPHIC_HPP_ */
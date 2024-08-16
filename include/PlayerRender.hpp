/*
** EPITECH PROJECT, 2024
** server
** File description:
** Core
*/

#ifndef PLAYERRENDER_HPP_
    #define PLAYERRENDER_HPP_

    #include <raylib.h>

    #include "GameData.hpp"

class PlayerRender {
    public:
        PlayerRender(std::shared_ptr<GameData> gameData);
        ~PlayerRender();
        void drawPlayer();
    protected:
        std::shared_ptr<GameData> _gameData;
        Model _playerModel;
};

#endif /* !PLAYERRENDER_HPP_ */
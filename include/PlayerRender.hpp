/*
** EPITECH PROJECT, 2024
** server
** File description:
** Core
*/

#ifndef PLAYERDRAWER_HPP_
    #define PLAYERDRAWER_HPP_

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

#endif /* !PLAYERDRAWER_HPP_ */
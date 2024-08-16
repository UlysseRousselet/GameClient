/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** settings
*/

#ifndef SETTINGSHANDLER_HPP
    #define SETTINGSHANDLER_HPP

    #include <iostream>
    #include <map>
    #include <memory>
    #include "GameData.hpp"

class SettingsHandler
{
    public:
        SettingsHandler(std::shared_ptr<GameData> gameData);
        ~SettingsHandler();
    private:
        std::shared_ptr<GameData> _gameData;
};

#endif /* !SETTINGHANDLER_HPP */

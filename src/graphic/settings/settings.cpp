/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "Graphic.hpp"

SettingsHandler::SettingsHandler(std::shared_ptr<GameData> gameData) : _gameData(gameData)
{
    //mettre dans gameData
    _gameData->settings.sensitivity = 0.1f;

    _gameData->settings.touchMap.insert({"FORWARD", KEY_W});
    _gameData->settings.touchMap.insert({"BACKWARD", KEY_S});
    _gameData->settings.touchMap.insert({"RIGHT", KEY_D});
    _gameData->settings.touchMap.insert({"LEFT", KEY_A});
}

SettingsHandler::~SettingsHandler()
{
    ;
}

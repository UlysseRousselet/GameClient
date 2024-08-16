/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "Graphic.hpp"

SettingsHandler::SettingsHandler()
{
    //mettre dans gameData
    sensitivity = 1.0f;

    this->touchMap.at(KEY_W) = "FORWARD";
    this->touchMap.at(KEY_S) = "BACKWARD";
    this->touchMap.at(KEY_D) = "RIGHT";
    this->touchMap.at(KEY_A) = "LEFT";
}

SettingsHandler::~SettingsHandler()
{
    ;
}

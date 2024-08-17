/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "EventHandler.hpp"

EventHandler::EventHandler(std::shared_ptr<Asio> asio, std::shared_ptr<GameData> gameData) : _asio(asio), _gameData(gameData)
{
    ;
}

EventHandler::~EventHandler()
{
    ;
}

void EventHandler::eventGestion()
{
    if (_gameData->playerState == PlayerState::NOT_IN_MENU)
        this->eventFirstPerson();

    if (_gameData->playerState == PlayerState::IN_MENU)
        this->eventInMenu();
}
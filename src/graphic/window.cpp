/*
** EPITECH PROJECT, 2024
** B-YEP-400-PAR-4-1-zappy-thibaud.cathala
** File description:
** graphic_class
*/

#include "Graphic.hpp"

Window::Window()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1920 / 2, 1080 / 2, "Game");
}

Window::~Window()
{
    CloseWindow();
}

/*
** EPITECH PROJECT, 2024
** client
** File description:
** Core
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    #include "GameData.hpp"
    #include <raylib.h>

class RenderCamera {
    public:
        RenderCamera(std::shared_ptr<GameData> gameData);
        ~RenderCamera();
    protected:
        Camera3D _camera;
        std::shared_ptr<GameData> _gameData;
};

#endif /* !CAMERA_HPP_ */
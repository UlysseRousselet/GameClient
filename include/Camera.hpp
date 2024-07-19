/*
** EPITECH PROJECT, 2024
** client
** File description:
** Core
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    #include "GameData.hpp"

class RenderCamera {
    public:
        RenderCamera(std::shared_ptr<GameData> gameData);
        ~RenderCamera();

        std::unique_ptr<Camera3D> _camera;

    protected:
        std::shared_ptr<GameData> _gameData;
};

#endif /* !CAMERA_HPP_ */
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

        static void update(std::shared_ptr<GameData> gameData);

    protected:
};

#endif /* !CAMERA_HPP_ */
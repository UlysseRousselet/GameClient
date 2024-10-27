/*
** EPITECH PROJECT, 2024
** server
** File description:
** Core
*/

#ifndef ASIOCLASS_HPP_
    #define ASIOCLASS_HPP_

    #include "Packet.hpp"
    #include <asio.hpp>
    #include <iostream>

class Asio {
    public:
        Asio(std::string ip, int port);
        ~Asio();

        template <typename T>
        void send_packet(int id, T packet)
        {
            int size = sizeof(int) + sizeof(T);
            char buffer[size];

            std::memcpy(buffer, &id, sizeof(int));

            std::memcpy(buffer + sizeof(int), &packet, sizeof(T));

            _socket.send_to(asio::buffer(&buffer, size), _server_endpoint);
        }

        void receive_packet();
    public:
        asio::io_context _io_context;
        asio::ip::udp::resolver _resolver;
        asio::ip::udp::resolver::query _query;
        asio::ip::udp::endpoint _server_endpoint;
        asio::ip::udp::socket _socket;
        char answer[1024];
};

#endif /* !ASIOCLASS_HPP_ */

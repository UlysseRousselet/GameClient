/*
** EPITECH PROJECT, 2024
** server
** File description:
** Core
*/

#ifndef ASIOCLASS_HPP_
    #define ASIOCLASS_HPP_

    #include <asio.hpp>
    #include <iostream>

struct Packet {
    int id;
    float args[5];
};

class Asio {
    public:
        Asio(std::string ip, int port);
        ~Asio();
        void send_packet(Packet packet);
        void receive_packet();
    public:
        asio::io_context _io_context;
        asio::ip::udp::resolver _resolver;
        asio::ip::udp::resolver::query _query;
        asio::ip::udp::endpoint _server_endpoint;
        asio::ip::udp::socket _socket;
        Packet answer;
};

#endif /* !ASIOCLASS_HPP_ */

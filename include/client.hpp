/*
** EPITECH PROJECT, 2024
** client
** File description:
** Core
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_

    #include <iostream>
    #include <asio.hpp>

struct Packet {
    int id;
    float args[5];
};

class Client
{
    public:
        Client(std::string ip, std::string port);
        ~Client();
        void loop();
        void send_packet(Packet packet);
    private:
        asio::io_context _io_context;
        asio::ip::udp::resolver _resolver;
        asio::ip::udp::resolver::query _query;
        asio::ip::udp::endpoint _server_endpoint;
        asio::ip::udp::socket _socket;
};

#endif /* !CLIENT_HPP_ */
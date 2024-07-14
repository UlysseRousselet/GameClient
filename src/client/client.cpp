/*
** EPITECH PROJECT, 2024
** game client
** File description:
** main
*/

#include "client.hpp"

Client::Client(std::string ip, std::string port) : _io_context(), _resolver(_io_context), _query(asio::ip::udp::v4(), ip, port), _server_endpoint(*_resolver.resolve(_query)), _socket(_io_context)
{
    _socket.open(asio::ip::udp::v4());
}

Client::~Client()
{
    send_packet({2, {1.0, 2.0, 3.0, 4.0, 5.0}});
    _socket.close();
}

void Client::send_packet(Packet packet)
{
    _socket.send_to(asio::buffer(&packet, sizeof(Packet)), _server_endpoint);
}

void Client::loop()
{
    send_packet({1, {1.0, 2.0, 3.0, 4.0, 5.0}});

    while (true)
    {
        char recv_buf[2000];
        std::cout << "Waiting for data..." << std::endl;
        size_t len = _socket.receive_from(asio::buffer(recv_buf), _server_endpoint);
        std::cout << "Received: ";
        std::cout.write(recv_buf, len);
    }
}

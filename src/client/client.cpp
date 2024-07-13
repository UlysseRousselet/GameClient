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

void Client::loop()
{
    std::array<float, 5> send_buf = {1.0, 2.0, 3.0, 4.0, 5.0};
    _socket.send_to(asio::buffer(send_buf), _server_endpoint);
    while (true)
    {
        char recv_buf[2000];
        std::cout << "Waiting for data..." << std::endl;
        size_t len = _socket.receive_from(asio::buffer(recv_buf), _server_endpoint);
        std::cout << "Received: ";
        std::cout.write(recv_buf, len);
    }
}

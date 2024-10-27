/*
** EPITECH PROJECT, 2024
** Projet perso
** File description:
** main
*/

#include "AsioClass.hpp"

Asio::Asio(std::string ip, int port) : _io_context(), _resolver(_io_context), _query(asio::ip::udp::resolver::query(asio::ip::udp::v4(), ip, std::to_string(port))), _server_endpoint(*_resolver.resolve(_query)), _socket(_io_context)
{
    _socket.open(asio::ip::udp::v4());
}

Asio::~Asio()
{
    send_packet(2, Disconnect_t{1});
    _socket.close();
}

void Asio::receive_packet()
{
    _socket.receive_from(asio::buffer(&answer, 1024), _server_endpoint);
    std::cout << "Received: " << answer << std::endl;
}

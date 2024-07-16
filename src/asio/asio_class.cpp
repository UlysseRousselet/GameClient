/*
** EPITECH PROJECT, 2024
** Projet perso
** File description:
** main
*/

#include "Asio.hpp"

Asio::Asio(std::string ip, int port) : _io_context(), _resolver(_io_context), _query(asio::ip::udp::resolver::query(asio::ip::udp::v4(), ip, std::to_string(port))), _server_endpoint(*_resolver.resolve(_query)), _socket(_io_context)
{
    _socket.open(asio::ip::udp::v4());
}

Asio::~Asio()
{
    send_packet({2, {1.0, 2.0, 3.0, 4.0, 5.0}});
    _socket.close();
}

void Asio::receive_packet()
{
  _socket.receive_from(asio::buffer(&answer, sizeof(Packet)), _server_endpoint);
  std::cout << "Received: " << answer.id << " " << answer.args[0] << " " << answer.args[1] << " " << answer.args[2] << " " << answer.args[3] << " " << answer.args[4] << std::endl;
}

void Asio::send_packet(Packet packet)
{
    _socket.send_to(asio::buffer(&packet, sizeof(Packet)), _server_endpoint);
}

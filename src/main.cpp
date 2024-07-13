/*
** EPITECH PROJECT, 2024
** game client
** File description:
** main
*/

#include "client.hpp"

int main()
{
    try
    {
        asio::io_context io_context;
        asio::ip::udp::resolver resolver(io_context);
        std::string ip = "88.125.120.73";
        std::cout << "Server listening on " << ip << std::endl;

        asio::ip::udp::resolver::query query(asio::ip::udp::v4(), ip, "35000");

        asio::ip::udp::endpoint endpoints = *resolver.resolve(query);
        asio::ip::udp::socket socket(io_context);
        socket.open(asio::ip::udp::v4());

        char send_buf[2000] = "Hello, world!";
        socket.send_to(asio::buffer(send_buf), endpoints);

        char recv_buf[2000];
        asio::ip::udp::endpoint sender_endpoint;
        size_t len = socket.receive_from(asio::buffer(recv_buf), sender_endpoint);
        std::cout.write(recv_buf, len);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
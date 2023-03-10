/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "PlayerbotCommandServer.h"
#include "IoContext.h"
#include "Playerbots.h"

#include <cstdlib>
#include <iostream>

#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>

using boost::asio::ip::tcp;
typedef boost::shared_ptr<tcp::socket> socket_ptr;

bool ReadLine(socket_ptr sock, std::string *buffer, std::string *line)
{
    // Do the real reading from fd until buffer has '\n'.
    std::string::iterator pos;
    while ((pos = find(buffer->begin(), buffer->end(), '\n')) == buffer->end())
    {
        char buf[1025];
        boost::system::error_code error;
        size_t n = sock->read_some(boost::asio::buffer(buf), error);
        if (n == -1 || error == boost::asio::error::eof)
            return false;
        else if (error)
            throw boost::system::system_error(error); // Some other error.

        buf[n] = 0;
        *buffer += buf;
    }

    *line = std::string(buffer->begin(), pos);
    *buffer = std::string(pos + 1, buffer->end());
    return true;
}

void session(socket_ptr sock)
{
    try
    {
        std::string buffer, request;
        while (ReadLine(sock, &buffer, &request))
        {
            std::string const response = sRandomPlayerbotMgr->HandleRemoteCommand(request) + "\n";
            boost::asio::write(*sock, boost::asio::buffer(response.c_str(), response.size()));
            request = "";
        }
    }
    catch (std::exception &e)
    {
        LOG_ERROR("playerbots", "{}", e.what());
    }
}

void server(Acore::Asio::IoContext &io_service, short port)
{
    tcp::acceptor a(io_service, tcp::endpoint(tcp::v4(), port));
    for (;;)
    {
        socket_ptr sock(new tcp::socket(io_service));
        a.accept(*sock);
        boost::thread t(boost::bind(session, sock));
    }
}

void Run()
{
    if (!sPlayerbotAIConfig->commandServerPort)
    {
        return;
    }

    std::ostringstream s;
    s << "Starting Playerbots Command Server on port " << sPlayerbotAIConfig->commandServerPort;
    LOG_INFO("playerbots", "{}", s.str().c_str());

    try
    {
        Acore::Asio::IoContext io_service;
        server(io_service, sPlayerbotAIConfig->commandServerPort);
    }

    catch (std::exception &e)
    {
        LOG_ERROR("playerbots", "{}", e.what());
    }
}

void PlayerbotCommandServer::Start()
{
    std::thread serverThread(Run);
    serverThread.detach();
}

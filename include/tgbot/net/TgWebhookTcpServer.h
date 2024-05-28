#ifndef TGBOT_TGWEBHOOKTCPSERVER_H
#define TGBOT_TGWEBHOOKTCPSERVER_H

#include "tgbot/net/TgWebhookServer.h"

#include <string>

namespace TgBot {

/**
 * This class setups HTTP server for receiving Telegram Update objects from tcp connections.
 * @ingroup net
 */
class TgWebhookTcpServer : public TgWebhookServer<asio::ip::tcp> {

public:
    TgWebhookTcpServer(unsigned short port, const std::string& path, const EventHandler& eventHandler)
            : TgWebhookServer<asio::ip::tcp>(asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port),
                                                    path, eventHandler)
    {
    }

    TgWebhookTcpServer(unsigned short port, const Bot& bot)
            : TgWebhookServer<asio::ip::tcp>(asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port),
                                                    bot)
    {
    }
};

}

#endif //TGBOT_TGWEBHOOKTCPSERVER_H

#pragma once

#include "HashMap.h"
#include <string>

template<typename K, typename V>
class RedisServer
{
private:
    HashMap<K, V> database;

    // Socket Information
    int serverSocket;
    int port;

    // Server State
    bool running;

private:

    // Networking
    bool createSocket();
    bool bindSocket();
    bool startListening();
    void acceptClients();
    void handleClient(int clientSocket);

    // Communication
    std::string receiveCommand(int clientSocket);
    bool sendResponse(int clientSocket,
                      const std::string& response);

    // Command Execution
    std::string execute(const std::string& command);
    std::string parseCommand(const std::string& command);

    // Database Commands
    std::string set(const K&, const V&);
    std::string get(const K&);
    std::string exists(const K&);
    std::string del(const K&);
    std::string clear();
    std::string dbsize();

    // Utilities
    std::string toLower(std::string);

public:

    RedisServer(int port = 6379);

    ~RedisServer();

    void start();
    
    void stop();
};
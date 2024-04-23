/*
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <SFML/System/Thread.hpp>
#include "DataHandler.hpp"

using std::cout;
using std::endl;

// A very basic version of a socket implimentation, while not actually
// being used this is our attempt at it.
// used https://www.sfml-dev.org/tutorials/2.6/network-socket.php and TA
// assistance to help put this together

class Network
{
public:

	// enum type
	enum netType
	{
		Server, Client
	};

	// constructor
	Network(sf::IpAddress newIp, unsigned int newPort, netType t, DataHandler handler);

	// methoids
	void connect();
	void listen();
	void send(const char* nData, std::size_t nSize);

	// destructor
	~Network();

private:

	sf::TcpSocket socket;
	sf::TcpListener listener;
	sf::TcpSocket client;
	sf::Thread clientT;
	sf::Thread serverT;
	sf::IpAddress ip;
	unsigned int port;
	DataHandler dataRecieved;

	// private methoids
	void receive();

};
*/
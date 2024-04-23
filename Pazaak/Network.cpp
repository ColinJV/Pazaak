//#include "Network.hpp"
//
//// A very basic version of a socket implimentation, while not actually
//// being used this is what we did as our attempt at it.
//// used https://www.sfml-dev.org/tutorials/2.6/network-socket.php and TA
//// assistance to help put this together
//
//
///********************************************************************************************************
//* Function: Network
//* Date Created: 4/18/2024 
//* Date Last Modified: 4/21/24
//* Programmer: Joshua Allard
//* Description: constructs a network object 
//* Input parameters: ip address, a computer port
//* Returns: void
//* Preconditions: None
//* Postconditions: None
//********************************************************************************************************/
//Network::Network(sf::IpAddress newIp, unsigned int newPort, netType t, DataHandler handler)
//{
//	// no things to set
//}
//
///********************************************************************************************************
//* Function: connect
//* Date Created: 4/18/2024
//* Date Last Modified: 4/21/24
//* Programmer: Joshua Allard
//* Description: establishes a connection to another socket
//* Input parameters: void
//* Returns: void
//* Preconditions: None
//* Postconditions: None
//********************************************************************************************************/
//void Network::connect()
//{
//	// creates the var cStatus and gives it a socket
//	sf::Socket::Status cStatus = socket.connect(ip, port);
//	// check cStatus
//	if (cStatus != sf::Socket::Done)
//	{
//		cout << "connect error" << endl;
//	}
//}
//
///********************************************************************************************************
//* Function: listen
//* Date Created: 4/18/2024
//* Date Last Modified: 4/22/24
//* Programmer: Joshua Allard
//* Description: listens for connections from another socket
//* Input parameters: void
//* Returns: void
//* Preconditions: None
//* Postconditions: None
//********************************************************************************************************/
//void Network::listen()
//{
//	// put listen to a port
//	if (listener.listen(6000) != sf::Socket::Done)
//	{
//		cout << "listen error" << endl;
//	}
//	// accept connection
//	if (listener.accept(client) != sf::Socket::Done)
//	{
//		cout << "listen error" << endl;
//	}
//	// communicate with connected socket
//	serverT = sf::Thread(&Network::receive, this);
//	serverT.launch();
//}
//
///********************************************************************************************************
//* Function: send
//* Date Created: 4/18/2024
//* Date Last Modified: 4/21/24
//* Programmer: Joshua Allard
//* Description: sends data to another connected socket
//* Input parameters: void
//* Returns: void
//* Preconditions: None
//* Postconditions: None
//********************************************************************************************************/
//void Network::send(const char* nData, std::size_t nSize)
//{
//	// data type in param char used
//	if (socket.send(nData, nSize) != sf::Socket::Done)
//	{
//		cout << "send error" << endl;
//	}
//}
//
///********************************************************************************************************
//* Function: ~Network
//* Date Created: 4/18/2024
//* Date Last Modified: 4/22/24
//* Programmer: Joshua Allard
//* Description: closes all connections when called
//* Input parameters: void
//* Returns: void
//* Preconditions: None
//* Postconditions: None
//********************************************************************************************************/
//Network::~Network()
//{
//	// void
//}
//
///********************************************************************************************************
//* Function: receive
//* Date Created: 4/18/2024
//* Date Last Modified: 4/22/24
//* Programmer: Joshua Allard
//* Description: receives data from a connected socket
//* Input parameters: void
//* Returns: void
//* Preconditions: None
//* Postconditions: None
//********************************************************************************************************/
//void Network::receive()
//{
//	// char used 
//	char nData[5000];
//	// newly recieved
//	std::size_t nReceived;
//	if (socket.receive(nData, 5000, nReceived) != sf::Socket::Done)
//	{
//		cout << "receive error" << endl;
//	}
//	else
//	{
//		// received data
//		DataHandler(nData, static_cast<int>(nReceived));
//	}
//
//
//}

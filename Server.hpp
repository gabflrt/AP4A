#ifndef SERVER_HPP
#define SERVER_HPP
#include <string>
using namespace std;
#include "Sensors.hpp"

class Server
{
private:
	// Atributs
	Sensors listOfSensors;
	int interTemp;
	int interHum;
	int interSon;
	int interLum;

	// Méthodes privées
	void ConsoleWrite(string);
	void fileWrite(string, int);

public:
	// Constructeurs
	Server();
	Server(const Server &);
	Server(Sensors, int, int, int, int);
	// Destructeur
	~Server();

	// Surcharge d'opérateurs
	void operator=(Server &);
	void operator<<(int);
	// Méthode publique
	void dataRcv(string, int, int);

	friend class Scheduler;
};

#endif

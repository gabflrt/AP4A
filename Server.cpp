#include "Server.hpp"
#include "Scheduler.hpp"

#include <cstdio>
#include <iostream>
#include <fstream>

// FORME CANONIQUE DE COPLIEN
// Constructeur par défaut
Server::Server()
{
	listOfSensors = Sensors(0, 0, 0, 0);
	interTemp = 10;
	interHum = 10;
	interSon = 10;
	interLum = 10;
}

// Constructeur par recopie
Server::Server(const Server &s)
{
	listOfSensors = s.listOfSensors;
	interTemp = s.interTemp;
	interHum = s.interHum;
	interSon = s.interSon;
	interLum = s.interLum;
}

// Constructeur avec valeurs
Server::Server(Sensors sensors, int T, int H, int S, int L)
{
	listOfSensors = sensors;
	interTemp = T;
	interHum = H;
	interSon = S;
	interLum = L;
}

// Destructeur
Server::~Server()
{
}

// SURCHARGES D'OPERATEURS
// Opérateur d'affectation
void Server::operator=(Server &s)
{
	if (this != &s)
	{
		listOfSensors = s.listOfSensors;
		interTemp = s.interTemp;
		interHum = s.interHum;
		interSon = s.interSon;
		interLum = s.interLum;
	}
}
// Opérateur de sortie standard
void Server::operator<<(int mode)
{
	Scheduler s;
	s.transfert(*this, mode);
}

// Affichage
void Server::ConsoleWrite(string data)
{
	cout << data << endl;
}

// Ecriture dans le bon fichier en fonction du canal pris en paramètre
void Server::fileWrite(string data, int canal)
{
	if (canal == 0)
	{
		ofstream LogTemperature;
		LogTemperature.open("./data/temperature.txt", ios::app);
		if (LogTemperature.is_open())
		{
			LogTemperature << data << endl;
		}
		else
		{
			cout << "Impossible d'ouvrir le fichier" << endl;
		}
	}
	else if (canal == 1)
	{
		ofstream LogHumidite("./data/humidite.txt", ios::app);
		if (LogHumidite)
		{
			LogHumidite << data << endl;
		}
		else
		{
			cout << "Impossible d'ouvrir le fichier" << endl;
		}
	}
	else if (canal == 2)
	{
		ofstream LogLumiere("./data/lumiere.txt", ios::app);
		if (LogLumiere)
		{
			LogLumiere << data << endl;
		}
		else
		{
			cout << "Impossible d'ouvrir le fichier" << endl;
		}
	}
	else
	{
		ofstream logSon("./data/son.txt", ios::app);
		if (logSon)
		{
			logSon << data << endl;
		}
		else
		{
			cout << "Impossible d'ouvrir le fichier" << endl;
		}
	}
}

// Réception des données, du canal et du mode d'affichage
void Server::dataRcv(string data, int canal, int mode)
{
	if (mode == 1 || mode == 3)
	{
		ConsoleWrite(data);
	}
	if (mode == 2 || mode == 3)
	{
		fileWrite(data, canal);
	}
}

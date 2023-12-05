#include <cstdio>
#include <iostream>
#include <time.h>
#include "Scheduler.hpp"

void Scheduler::transfert(Server server, int mode)
{
    time_t t1, t2;
    bool stop = false;
    string data;
    int temps = 0;

    t1 = time(NULL);

    while (!stop)
    {

        t2 = time(NULL);
        // Rentre dans le if toutes les secondes et envoie les données ou non les données en fonction des interval donnés par l'utilisateur
        // La variable temps est incrémentée à chaqaue passage et on vérifie que temps modulo l'intervalle est égal à 0
        if (difftime(t2, t1) == 1)
        {
            cout << "===================================================" << endl;
            cout << "transfert en cours : Appuyer son Echap pour arreter" << endl;
            cout << "===================================================" << endl;

            temps++;
            if (temps % server.interTemp == 0)
                for (size_t i = 0; i < server.listOfSensors.temperature.size(); i++)
                {
                    t1 = t2;
                    float data_brut = server.listOfSensors.temperature[i].sendDataFloat();
                    ostringstream oss;
                    oss << "Capteur temperature numero " << i << " : " << data_brut;
                    string data = oss.str();
                    server.dataRcv(data, 0, mode);
                }

            if (temps % server.interHum == 0)
                for (size_t i = 0; i < server.listOfSensors.humidity.size(); i++)
                {
                    t1 = t2;
                    float data_brut = server.listOfSensors.humidity[i].sendDataFloat();
                    ostringstream oss;
                    oss << "Capteur d'humidite numero " << i << " : " << data_brut;
                    string data = oss.str();
                    server.dataRcv(data, 1, mode);
                }

            if (temps % server.interSon == 0)
                for (size_t i = 0; i < server.listOfSensors.sound.size(); i++)
                {
                    t1 = t2;
                    int data_brut = server.listOfSensors.sound[i].sendDataInt();
                    ostringstream oss;
                    oss << "Capteur de son numero " << i << " : " << data_brut;
                    string data = oss.str();
                    server.dataRcv(data, 2, mode);
                }

            if (temps % server.interLum == 0)
                for (size_t i = 0; i < server.listOfSensors.light.size(); i++)
                {
                    t1 = t2;
                    bool data_brut = server.listOfSensors.light[i].sendDataBool();
                    ostringstream oss;
                    oss << "Capteur de luminosite numero " << i << " : " << data_brut;
                    string data = oss.str();
                    server.dataRcv(data, 3, mode);
                }

            t1 = time(NULL);
        }
        // Quitte la boucle si la touche Echap est appuyée
        // Vérifie si une touche à été appuyée
        if (kbhit())
        {
            // Récupère la touche appuyée
            int touche = getch();
            // Vérifie qu'il s'agit de la touche Echap
            if (touche == 27)
            {
                stop = true;
            }
        }
    }
}
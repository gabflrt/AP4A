#ifndef SENSORS_HPP
#define SENSORS_HPP
#include "Sensor.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Sensors
{
private:
    // Un tableau pour chaque type de capteur
    vector<Sensor<float>> temperature;
    vector<Sensor<float>> humidity;
    vector<Sensor<int>> sound;
    vector<Sensor<bool>> light;

public:
    // Constructeur par défaut
    Sensors()
    {
    }

    // Constructeur à partir du nombre de capteurs de chaque type
    Sensors(int, int, int, int);

    // Permet à la class Scheduler d'accéder aux tableaux de capteurs
    friend class Scheduler;
};

#endif

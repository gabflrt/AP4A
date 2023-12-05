#include "Sensors.hpp"

// Crée le nombre de capteur demandés puis les insèrent dans leur liste pour chaque type de capteur
Sensors::Sensors(int nbTe, int nbHu, int nbSo, int nbLi)
{
    for (int i = 0; i < nbTe; i++)
    {
        Sensor<float> newCap;
        this->temperature.push_back(newCap);
    }
    for (int i = 0; i < nbHu; i++)
    {
        Sensor<float> newCap;
        this->humidity.push_back(newCap);
    }
    for (int i = 0; i < nbSo; i++)
    {
        Sensor<int> newCap;
        this->sound.push_back(newCap);
    }
    for (int i = 0; i < nbLi; i++)
    {
        Sensor<bool> newCap;
        this->light.push_back(newCap);
    }
}


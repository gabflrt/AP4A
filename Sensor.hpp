#ifndef SENSOR_HPP
#define SENSOR_HPP
#include <string>
#include <random>
#include <iostream>
using namespace std;

template <typename T>
class Sensor
{
private:
    // Attribut
    T valSense;

    // Méthode pour générer des nombres aléatoires
    int aleaGenVal(int min, int max)
    {
        // Initialisation de la graine pour le générateur de nombres aléatoires
        random_device rd;

        // Création d'un générateur de nombres aléatoires
        mt19937 gen(rd());

        // Création d'une distribution uniforme entre min et max
        uniform_int_distribution<> dis(min, max);

        // Génération d'un nombre aléatoire
        int random_number = (T)dis(gen);

        return random_number;
    };

public:
    // Constructeurs
    Sensor() : valSense(0){};
    Sensor(const Sensor &sensor) : valSense(sensor.valSense){};
    Sensor(int valRCV) : valSense(valRCV){};

    // Destructeur
    ~Sensor(){};

    // Méthodes pour renvoyer le nombre généré aléatoirement en fonction du type de capteur en utilisant la méthode aleaGenVal()
    int sendDataInt()
    {
        return this->aleaGenVal(0, 50);
    };

    float sendDataFloat()
    {
        return (this->aleaGenVal(0, 500)) / 10.;
    }

    bool sendDataBool()
    {
        return (this->aleaGenVal(0, 1));
    }
};

#endif

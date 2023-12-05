#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP
#include <string>
#include <sstream>
#include <conio.h>
#include "Server.hpp"
using namespace std;

class Scheduler
{
public:
    // Fonction qui gère tout le transfert des données et l'intervalle de temps entre chaque type de capteur
    void transfert(Server, int);
}

;

#endif

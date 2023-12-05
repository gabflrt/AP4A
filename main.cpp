#include <iostream>
#include <string>

#include "main.hpp"

int main()
{
    bool stop = false;
    while (!stop)
    {
        /* Création de l'instance capteurs de la classe Sensors,
        qui contient les listes de tous les capteurs par type,
        en laissant le choix à l'utilisateur du nombre de chaque type de capteur */
        int nbT, nbH, nbS, nbL, itT, itH, itS, itL, mode;
        cout << "Combien voulez vous de capteur de temperature ?" << endl;
        cin >> nbT;

        cout << "Combien voulez vous de capteur d'humidite ?" << endl;
        cin >> nbH;
        cout << "Combien voulez vous de capteur de son ?" << endl;
        cin >> nbS;
        cout << "Combien voulez vous de capteur de luminosite ?" << endl;
        cin >> nbL;
        Sensors capteurs(nbT, nbH, nbS, nbL);

        /* L'utilisateur choisit l'intervalle de temps de récupération
        pour chaque type de capteur, puis l'instance monServeur de la classe Server est créé */
        cout << "Quel intervalle de temps voulez vous entre chaque capteur de temperature ?" << endl;
        cin >> itT;
        cout << "Quel intervalle de temps voulez vous entre chaque capteur d'humidite ?" << endl;
        cin >> itH;
        cout << "Quel intervalle de temps voulez vous entre chaque capteur de son ?" << endl;
        cin >> itS;
        cout << "Quel intervalle de temps voulez vous entre chaque capteur de luminosite ?" << endl;
        cin >> itL;
        Server monServeur(capteurs, itT, itH, itS, itL);

        /* Enfin, l'utilisateur peut choisir le mode d'affichage des données,
        et le lancement du processus de récupération de données est lancé */
        cout << "Quel mode de recuperation de donnees voulez vous ?" << endl;
        cout << "[0:pas d'affichage, 1:console seul, 2:fichiers seuls, 3:tous]" << endl;
        cin >> mode;
        monServeur << mode;
    }
}
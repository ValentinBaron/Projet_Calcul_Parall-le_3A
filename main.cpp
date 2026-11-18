#include <mpi.h>
#include <iostream>
#include "parametres.h"
#include "fonctions.h"
#include "bicgstab.h"

using namespace std;

int main(int argc, char *argv[]){

    cout << " -- Début du programme -- " << endl;
    cout << "--------------------------" << endl;
    // Récupération des paramètres
    double Lx   = 0.0;      // Initialisation à 0 
    double Ly   = 0.0;
    double D    = 0.0;

    lireParametres(Lx, Ly, D);

    if ((Lx == 0.0) or (Ly == 0.0)){
        cout << "| - Erreur de lecture du domaine !" << endl;
        return 1;
    }

    cout << "| - Choix des paramètres : " << endl;
    cout << "| Lx = " << Lx << " ; Ly = " << Ly << endl;
    cout << "| D = " << D << endl;

    return 0;
}
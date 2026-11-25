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
    int cas     = 0;
    int Nx      = 0;
    int Ny      = 0;

    lireParametres(Lx, Ly, Nx, Ny, D, cas);

    if ((Lx == 0.0) or (Ly == 0.0)){
        cout << "| - Erreur de lecture du domaine !" << endl;
        return 1;
    }

    if (cas == 0){
        cout << "| - Erreur : aucun cas lu !" << endl;
        return 1;
    }

    cout << "| - Choix des paramètres : " << endl;
    cout << "| Lx = " << Lx << " ; Ly = " << Ly << endl;
    cout << "| D = " << D << endl;

    if (cas == 1){
        cout << "| - Solution choisie : solution stationnaire avec g et h nulle" << endl;
    }
    if (cas == 2){
        cout << "| - Solution choisie : solution stationnaire avec g = h = sin(x)+cos(y)" << endl;
    }
    if (cas == 3){
        cout << "| - Solution choisie : solution instationnaire périodique" << endl;
    }

    return 0;
}
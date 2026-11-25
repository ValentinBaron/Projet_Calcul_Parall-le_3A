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
    parametres Param;
    lireParametres(Param);

    if ((Param.Lx == 0.0) or (Param.Ly == 0.0)){
        cout << "| - Erreur de lecture du domaine !" << endl;
        return 1;
    }

    if (Param.cas == 0){
        cout << "| - Erreur : aucun cas lu !" << endl;
        return 1;
    }

    cout << "| - Choix des paramètres : " << endl;
    cout << "| Lx = " << Param.Lx << " ; Ly = " << Param.Ly << endl;
    cout << "| D = " << Param.D << endl;
    cout << "| Nx = " << Param.Nx << " ; Ny = " << Param.Ny << endl;

    if (Param.cas == 1){
        cout << "| - Solution choisie : solution stationnaire avec g et h nulle" << endl;
    }
    if (Param.cas == 2){
        cout << "| - Solution choisie : solution stationnaire avec g = h = sin(x)+cos(y)" << endl;
    }
    if (Param.cas == 3){
        cout << "| - Solution choisie : solution instationnaire périodique" << endl;
    }

    return 0;
}
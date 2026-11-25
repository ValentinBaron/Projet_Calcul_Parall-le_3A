#include "parametres.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void lireParametres(double& Lx, double& Ly, int& Nx, int& Ny, double& D, int& cas){   

    ifstream fichier("parametres.dat");

    if (!fichier){
        cerr << "| - Erreur d'ouverture du fichier parametres.dat ! - \n";
    }

    string ligne;
    double valeurs[3];
    int n = 0;

    while (n < 3 && std::getline(fichier, ligne)) {
        if (ligne.empty() || ligne[0] == '#') continue;
        valeurs[n++] = stod(ligne);
    }

    Lx = valeurs[0];
    Ly = valeurs[1];
    D  = valeurs[2];
    cas = valeurs[3];
    Nx = valeurs[4];
    Ny = valeurs[5];
}

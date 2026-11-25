#include "parametres.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void lireParametres(parametres& Param){   

    ifstream fichier("parametres.dat");

    if (!fichier){
        cerr << "| - Erreur d'ouverture du fichier parametres.dat ! - \n";
    }

    string ligne;
    double valeurs[9];
    int n = 0;

    while (n < 9 && std::getline(fichier, ligne)) {
        if (ligne.empty() || ligne[0] == '#') continue;
        valeurs[n++] = stod(ligne);
    }

    Param.Lx = valeurs[0];
    Param.Ly = valeurs[1];
    Param.D  = valeurs[2];
    Param.cas = int(valeurs[3]);
    Param.Nx = int(valeurs[4]);
    Param.Ny = int(valeurs[5]);
    Param.dt = valeurs[6];
    Param.h_case = int(valeurs[7]);
    Param.g_case = int(valeurs[8]);
}

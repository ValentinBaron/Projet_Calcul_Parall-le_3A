#include <mpi.h>
#include <iostream>
#include "parametres.h"
#include "fonctions.h"
#include "bicgstab.h"

using namespace std;

int main(int argc, char *argv[]){

    // Récupération des paramètres

    cout << " -- Début du programme -- " << endl;
    cout << "--------------------------" << endl;
    
    parametres Param;
    lireParametres(Param);

    int Nx = Param.Nx;
    int Ny = Param.Ny;
    double D = Param.D;
    double dt = Param.dt;
    double dx = Param.Lx / (Nx+1);
    double dy = Param.Ly / (Ny+1);
    double Lx = Param.Lx;
    double Ly = Param.Ly;

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
    cout << "| Nx = " << Nx << " ; Ny = " << Ny << endl;

    if (cas == 1){
        cout << "| - Solution choisie : solution stationnaire avec g et h nulle" << endl;
    }
    if (cas == 2){
        cout << "| - Solution choisie : solution stationnaire avec g = h = sin(x)+cos(y)" << endl;
    }
    if (cas == 3){
        cout << "| - Solution choisie : solution instationnaire périodique" << endl;
    }

    double *U = (double*)malloc(Nx * Ny * sizeof(double));
    double *U0 = (double*)malloc(Nx * Ny * sizeof(double));
    double *B = (double*)malloc(Nx * Ny * sizeof(double));

    // Initialisation à t = 0
    double t = 0.0;
    for (int k = 0; k < Nx * Ny; k++) {
        int j = k / Nx;
        int i = k % Nx;
        double x = xmin + i * dx;
        double y = ymin + j * dy;
        U0[k] = 0.0;
        U[k] = U0[k];
        B[k] = 0.0;
    }

    // Boucle en temps
    for (int iter = 1; iter <= nb_iter; iter++) {
        
        t += dt;
        int kmax = 1000;
        double eps = 1e-6;
        
        // Initialisation de la solution
        for (int k = 0; k < Nx * Ny; k++) U[k] = U0[k];
        
        // Mise à jour du second membre
        second_membre(U0, B, t, Param);
        
        // Résolution par BiCGStab
        bicgstab(N, B, U, kmax, eps, Nx, Ny, dx, dy, dt, D);

        // Échange des pointeurs
        double *temp = U0;
        U0 = U;
        U = temp;
    }

    return 0;
}
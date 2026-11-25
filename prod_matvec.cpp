#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "fonctions.h"
#include "parametres.h"

void prod_matvec(double *U0, double *U)
{
    double dt = 0.01;
    double dx = 0.1;
    double dy = 0.1;
    int Nx = 1000;
    int Ny = 1000;
    
    // Coefficients de la matrice
    double alpha = 1.0/dt + 2.0*D/(dx*dx) + 2.0*D/(dy*dy);
    double beta  = -D/(dx*dx);   // voisins en x (est / ouest)
    double gam   = -D/(dy*dy);   // voisins en y (nord / sud)

    for (int k=0; k<Nx*Ny; k++)
    {
        int j = k/Nx;
        int i = k%Nx;

        // Diagonale
        U[k] = alpha*U0[k];

        // Voisins
        if (i > 0)    U[k] += beta*U0[k-1];    // ouest
        if (i < Nx-1) U[k] += beta*U0[k+1];    // est
        if (j > 0)    U[k] += gam *U0[k-Nx];   // sud
        if (j < Ny-1) U[k] += gam *U0[k+Nx];   // nord
    }
}
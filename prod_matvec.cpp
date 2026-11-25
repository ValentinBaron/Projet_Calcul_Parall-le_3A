#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "parametres.h"
#include "fonctions.h"

void prod_matvec(double *U0, double *U, parametres Param)
{
    int Nx = Param.Nx;
    int Ny = Param.Ny;
    double D = Param.D;
    double dt = Param.dt;
    double dx = Param.Lx / Nx;
    double dy = Param.Ly / Ny;
    
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

void second_membre(double *B, double *Un, double t, parametres Param)
{
    int Nx = Param.Nx;
    int Ny = Param.Ny;
    double D = Param.D;
    double dt = Param.dt;
    double dx = Param.Lx / Nx;
    double dy = Param.Ly / Ny;
    double Lx = Param.Lx;
    double Ly = Param.Ly;
    
    for (int k = 0; k < Nx*Ny; k++)
    {
        int j = k / Nx;
        int i = k % Nx;
        double x = (i+1)*dx;
        double y = (j+1)*dy;

        B[k] = Un[k]/dt + f(x, y, t, Param);

        if (i == 0)    B[k] += D/(dx*dx) * h(0.0, y, Param);   // bord gauche
        if (i == Nx-1) B[k] += D/(dx*dx) * h(Lx,  y, Param);   // bord droit
        if (j == 0)    B[k] += D/(dy*dy) * g(x, 0.0, Param);   // bord bas
        if (j == Ny-1) B[k] += D/(dy*dy) * g(x, Ly,  Param);   // bord haut
    }
}
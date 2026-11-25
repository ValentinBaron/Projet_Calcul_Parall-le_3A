#ifndef _PARAMETRES_H
#define _PARAMETRES_H

struct parametres{
    double Lx       = 0.0;
    double Ly       = 0.0;
    double D        = 0.0;
    double dt       = 0.0;
    int    Nx       = 0;
    int    Ny       = 0;
    int    cas      = 0;
    int    h_case   = -1;
    int    g_case   = -1;
};

void lireParametres(parametres& Param);

#endif

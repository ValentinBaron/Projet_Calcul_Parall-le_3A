#include <cmath>
#include "fonctions.h"
#include "parametres.h"

double f_stat_1(double x, double y){        // f = 2(x-x²+y-y²)
    return 2.0*(x - x*x + y - y*y);
}

double f_stat_2(double x, double y){        // f = sin(x) + cos(y)
    return sin(x) + cos(y);
}

double f_instat(double x, double y, double Lx, double Ly, double t){                // f instationnaire périodique
    return exp(-((x - (Lx/2.0))*(x - (Lx/2.0)))) * exp(-((y - (Ly/2.0))*(y - (Ly/2.0)))) * cos(M_PI/2.0 * t);
}

double f(int cas, double x, double y, double Lx, double Ly, double t){
// Retourne la solution en fonction des différents cas de l'énoncé
    
    if (cas == 1){                          // Cas stationnaire avec g et h nulle
        return f_stat_1(x,y);
    }

    if (cas == 2){
        return f_stat_2(x,y);               // Cas stationnaire avec g = h = sin(x) + cos(y)
    }

    if (cas == 3){
        return f_instat(x,y,Lx,Ly,t);       // Cas instationnaire périodique
    }
}
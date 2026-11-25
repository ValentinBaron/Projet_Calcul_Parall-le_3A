#include <cmath>
#include "parametres.h"
#include "fonctions.h"

double f_stat_1(double x, double y){        // f = 2(x-x²+y-y²)
    return 2.0*(x - x*x + y - y*y);
}

double f_stat_2(double x, double y){        // f = sin(x) + cos(y)
    return sin(x) + cos(y);
}

double f_instat(double x, double y, double t, parametres Param){                // f instationnaire périodique
    double Lx = Param.Lx;
    double Ly = Param.Ly;

    return exp(-((x - (Lx/2.0))*(x - (Lx/2.0)))) * exp(-((y - (Ly/2.0))*(y - (Ly/2.0)))) * cos(M_PI/2.0 * t);
}

double f(double x, double y, double t, parametres Param){
// Retourne la solution en fonction des différents cas de l'énoncé
    
    if (Param.cas == 1){                          // Cas stationnaire avec g et h nulle
        return f_stat_1(x,y);
    }

    if (Param.cas == 2){
        return f_stat_2(x,y);               // Cas stationnaire avec g = h = sin(x) + cos(y)
    }

    if (Param.cas == 3){
        return f_instat(x,y,t,Param);       // Cas instationnaire périodique
    }

    return 0.0;
}

double hg(double x, double y, parametres Param){

    if (Param.g_case == 0){
        return 0.0;
    }

    if (Param.g_case == 1){
        return 1.0;
    }

    if (Param.g_case == 2){
        return sin(x) + cos(y);
    }

    return 0.0;
}
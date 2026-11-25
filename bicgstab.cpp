#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "parametres.h"
#include "prod_matvec.h"

// Fonction pour calculer le produit scalaire entre deux vecteurs
double prod_scal(int n, double *a, double *b) {
    double somme = 0.0;
    for (int i = 0; i < n; i++) {
        somme += a[i] * b[i];
    }
    return somme;
}

// Fonction pour calculer la norme d'un vecteur
double norme(int taille, double *v) {
    double somme = 0.0;
    
    for (int i = 0; i < taille; i++) {
        somme += v[i] * v[i];
    }
    
    return sqrt(somme);
}

void bicgstab(
    int taille,                     // taille du système
    double *b,                      // vecteur b
    double *x,                      // vecteur x
    int kmax,                       // max itérations
    double eps,                     // critère d'arrêt
    parametres Param                // paramètres d'entrée
    )   {

    // Allocation des vecteurs
    double *r = (double*)malloc(taille * sizeof(double));
    double *r_chapeau = (double*)malloc(taille * sizeof(double));
    double *p = (double*)malloc(taille * sizeof(double));
    double *v = (double*)malloc(taille * sizeof(double));
    double *s = (double*)malloc(taille * sizeof(double));
    double *l = (double*)malloc(taille * sizeof(double));

    for (int i = 0; i < taille; i++){
        p[i] = 0.0;
        v[i] = 0.0;
    }

    double alpha = 1.0, omega = 1.0;
    double rho = 1.0, rho0 = 1.0;

    //int indice_sortie = 0;

    // r = A*x
    prod_matvec(x, r, Param);

    // r = b - A*x ou r = b - r
    for (int i = 0; i < taille; i++)
        r[i] = b[i] - r[i];

    // r_chapeau = r
    for (int i = 0; i < taille; i++)
        r_chapeau[i] = r[i];

    for (int k = 0; k < kmax; k++) {

        //indice_sortie = k;

        rho = prod_scal(taille, r_chapeau, r);
        if (fabs(rho) < 1e-20) break;

        double beta = (rho / rho0) * (alpha / omega);

        for (int i = 0; i < taille; i++)
            p[i] = r[i] + beta * (p[i] - omega * v[i]);

        // v = A*p
        prod_matvec(p, v, Param);

        double denom = prod_scal(taille, r_chapeau, v);
        if (fabs(denom) < 1e-20) break;

        alpha = rho / denom;

        for (int i = 0; i < taille; i++)
            s[i] = r[i] - alpha * v[i];

        if (norme(taille, s) < eps) {
            for (int i = 0; i < taille; i++)
                x[i] += alpha * p[i];
            break;
        }

        // l = A*s
        prod_matvec(s, l, Param);

        double l_l = prod_scal(taille, l, l);
        if (fabs(l_l) < 1e-20) break;

        omega = prod_scal(taille, l, s) / l_l;

        for (int i = 0; i < taille; i++)
            x[i] += alpha * p[i] + omega * s[i];

        for (int i = 0; i < taille; i++)
            r[i] = s[i] - omega * l[i];

        if (norme(taille, r) < eps) break;

        rho0 = rho;
    }
    
    // Vérification de la sortie du BiCGStab
    // printf("Indice sortie = %d\n",indice_sortie);
    // printf("Norme de x = %f \n",norme(taille,x));

    free(r);
    free(r_chapeau);
    free(p);
    free(v);
    free(s);
    free(l);
}
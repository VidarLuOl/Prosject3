#include "monte_carlo.h"
#include "integration_function.h"
#include <stdio.h>
#include <random>
#include <iostream>

using namespace std;

double monte_carlo(double lambda, int N){
    // For å lage random tall mellom 0.0 - 1.0
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    double X_1 = 0;
    double X_2 = 0;
    double Y_1 = 0;
    double Y_2 = 0;
    double Z_1 = 0;
    double Z_2 = 0;
    double jacobi = pow(2*lambda, 6);

    double sum = 0;
    double variance = 0;
    double f;
    for(int i=0; i < N; i++){
        X_1 = dis(gen)*(2*lambda)-lambda;
        X_2 = dis(gen)*(2*lambda)-lambda;
        Y_1 = dis(gen)*(2*lambda)-lambda;
        Y_2 = dis(gen)*(2*lambda)-lambda;
        Z_1 = dis(gen)*(2*lambda)-lambda;
        Z_2 = dis(gen)*(2*lambda)-lambda;
        f = integration_legendre(X_1, X_2, Y_1, Y_2, Z_1, Z_2, 2);
        sum += f;
        variance += pow(f, 2);
    }

    sum = sum/N;
    variance = variance/N;

    double variance2 = (variance - pow(sum, 2))*jacobi;

    //cout << "The variance is = " << variance2 << endl;

    return sum*jacobi;
}






double p(double r){
    return 1-4*exp(-4*r);
}


double monte_carlo_improved(double lambda){
    double      const  pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609;

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    uniform_real_distribution<> theta(0.0, pi);
    uniform_real_distribution<> phi(0.0, 2*pi);

    double r_1 = 0;
    double r_2 = 0;
    double theta_1 = 0;
    double theta_2 = 0;
    double phi_1 = 0;
    double phi_2 = 0;
    double jac = 4*pi*pi*pi*pi;

    double sum = 0;
    double variance = 0;
    double f;
    for(int i=0; i < lambda; i++){
        r_1 = -log(1-dis(gen))/4;
        r_2 = -log(1-dis(gen))/4;
        theta_1 = theta(gen);
        theta_2 = theta(gen);
        phi_1 = phi(gen);
        phi_2 = phi(gen);
        f = r_1*r_2*(sin(theta_1)+sin(theta_2))*integration_laguerre(r_1, r_2, theta_1, theta_2, phi_1, phi_2)/(p(r_1)*p(r_2));

        sum += f;
        variance += pow(f, 2);
    }

    sum = (jac*sum)/lambda;

    double variance2 = (variance - pow(sum, 2))*jac;

    cout << variance2 << endl;

    return sum;
}

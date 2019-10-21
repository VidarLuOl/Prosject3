#include "integration_function.h"
#include <cmath>
#include <iostream>

using namespace std;

double integration_legendre(double x1, double y1, double z1, double x2, double y2, double z2, int alpha){
    double r_1 = sqrt(x1*x1 + y1*y1 + z1*z1);
    double r_2 = sqrt(x2*x2 + y2*y2 + z2*z2);

    double r = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));


    if(r < 0.0001){
        return 0;
    }
    else{
        return exp(-2*alpha*(r_1 + r_2))/r;
    }
}

double integration_laguerre(double r1, double r2, double theta1, double theta2, double phi1, double phi2){
    double circle = sin(theta1)*sin(theta2)*r1*r2;

    double calculate = sqrt(r1*r1 + r2*r2 - 2.0*r1*r2*(cos(theta1)*cos(theta2) + sin(theta1)*sin(theta2)*cos(phi1-phi2)));

    if(calculate < 1E-10){
        return 0;
    }
    else{
        return circle/(double(1024)*calculate);
    }
}

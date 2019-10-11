#include "integration_function.h"
#include <cmath>
#include <iostream>

using namespace std;

double integration_function(double x1, double y1, double z1, double x2, double y2, double z2, int alpha){
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

#include "catch.hpp"
#include "../main_function/gauss_legendre.h"
#include "../main_function/gauss_laguerre.h"
#include "../main_function/integration_function.h"

using namespace std;

TEST_CASE("Test Gauss_Quadrature"){
    double      const  pi = 3.14159265359;
    double exact = 5*pi*pi/(16*16);

    double lambda = 2.3;
    int N = 19;
    int alpha = 2;

    double* X = new double[N];
    double* W = new double[N];

    gauleg(-lambda, lambda, X, W, 19);
    double gauss = gaulegcalc(X, W, N, alpha);



    REQUIRE(exact == Approx(gauss).epsilon(0.01));
}



TEST_CASE("Test Gauss_Improved"){
    double      const  pi = 3.14159265359;
    double exact = 5*pi*pi/(16*16);

    int N = 19;
    int alpha = 2;

    double* X = new double[N+1]; //Value
    double* W = new double[N+1]; //Weight

    double* phi_w = new double[N];
    double* phi_x = new double[N];

    double* theta_w = new double[N];
    double* theta_x = new double[N];

    gauleg(0, 2*pi, theta_x, theta_w, N);
    gauleg(0, pi, phi_x, phi_w, N);
    gauss_laguerre(X, W, N, alpha); //Gauss Laguerre

    double gauss = gaulagcalc(X, W, theta_x, theta_w, phi_x, phi_w, N);



    REQUIRE(exact == Approx(gauss).epsilon(0.01));
}

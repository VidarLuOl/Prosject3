#include "catch.hpp"
#include "../main_function/gauss_legendre.h"
#include "../main_function/integration_function.h"

using namespace std;

TEST_CASE("Test gauss_legendre"){
    double      const  pi = 3.14159265359;
    double exact = 5*pi*pi/(16*16);

    int N = 19;
    int alpha = 2;

    double* X = new double[N];
    double* W = new double[N];

    gauleg(-2.3, 2.3, X, W, 19);
    double gauss = gaulegcalc(X, W, N, alpha);



    REQUIRE(exact == Approx(gauss).epsilon(0.01));
}

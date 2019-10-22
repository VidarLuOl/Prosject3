#include "catch.hpp"
#include "../main_function/gauss_legendre.h"
#include "../main_function/gauss_laguerre.h"
#include "../main_function/integration_function.h"
#include "../main_function/monte_carlo.h"
#include <random>

using namespace std;

TEST_CASE("Test monte_carlo"){
    double      const  pi = 3.14159265359;
    double exact = 5*pi*pi/(16*16);


    double gauss = monte_carlo(2.3, 1000000);


    REQUIRE(exact == Approx(gauss).epsilon(0.01));
}

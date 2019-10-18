#include <iostream>
#include <armadillo>
#include <chrono>
#include "mpi/mpi.h"
#include "gauss_legendre.h"
#include "gauss_laguerre.h"
#include "integration_function.h"

using namespace std;

int main(int nargs, char *args[])
{
    double      const  pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609;
    double lamda;
    double gauss;
    int N;
    int alpha = 2;

    lamda = 2.8478437; N = 23;

    double* X = new double[N+1]; //Value
    double* W = new double[N+1]; //Weight

    double* phi_w = new double[N];
    double* phi_x = new double[N];

    double* theta_w = new double[N];
    double* theta_x = new double[N];


    /*
    gauleg(-lamda, lamda, X, W, N); //Gauss Legendre

    gauss = gaulegcalc(X, W, N, alpha); //Finding Gauss
    */


    gauleg(0, 2*pi, theta_x, theta_w, N);
    gauleg(0, pi, phi_x, phi_w, N);
    gauss_laguerre(X, W, N, alpha); //Gauss Laguerre

    /*
    int numprocs, my_rank;
    MPI_Init(&nargs, &args);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    cout << my_rank << endl;
    */

    auto start = chrono::high_resolution_clock::now();

    gauss = gaulagcalc(X, W, theta_x, theta_w, phi_x, phi_w, N);


    auto finish = chrono::high_resolution_clock::now();


    chrono::duration<double> elapsed = (finish - start);
    cout << "Time = " << elapsed.count() << " s " << endl;
    cout << gauss  << endl;
    cout << 5*pi*pi/(16*16) << endl;
    cout << gauss - 5*pi*pi/(16*16) << endl;

    return 0;
}

// Gå inn på build-Prosject3 tingen også helt inn også høyreklikk, åpne i terminal
// mpirun -n 4 ./main_function

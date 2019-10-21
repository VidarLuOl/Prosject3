#include <iostream>
#include <armadillo>
#include <chrono>
#include "mpi/mpi.h"
#include "gauss_legendre.h"
#include "gauss_laguerre.h"
#include "integration_function.h"
#include "monte_carlo.h"

using namespace std;

int main(int nargs, char *args[])
{
    double      const  pi = 3.141592653589793;
    double lamda;
    double gauss = 0;
    double MC = 0;
    int N;
    int alpha = 2;
    int my_rank = 0;

    lamda = 2.8478437; N = 19;

    double* X = new double[N+1]; //Value
    double* W = new double[N+1]; //Weight

    double* phi_w = new double[N];
    double* phi_x = new double[N];

    double* theta_w = new double[N];
    double* theta_x = new double[N];

    auto start = chrono::high_resolution_clock::now();

    // Opg.3a)
    /*
    gauleg(-lamda, lamda, X, W, N); //Gauss Legendre
    gauss = gaulegcalc(X, W, N, alpha); //Finding Gauss
    */


    // Opg.3b)
    /*
    gauleg(0, 2*pi, theta_x, theta_w, N);
    gauleg(0, pi, phi_x, phi_w, N);
    gauss_laguerre(X, W, N, alpha); //Gauss Laguerre

    gauss = gaulagcalc(X, W, theta_x, theta_w, phi_x, phi_w, N);
    */


    // Opg.3c)
    //gauss = monte_carlo(2.3);

    // Opg.3d) & 3e)

    int numprocs;
    MPI_Init(&nargs, &args);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    gauss = monte_carlo_improved(1000000);
    //gauss = 4*pi*pi/(16*16);

    cout << "my_rank = " << my_rank << " Gauss = " << gauss << endl;

    MPI_Barrier(MPI_COMM_WORLD);

    MPI_Reduce(&gauss, &MC, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    MPI_Finalize();



    auto finish = chrono::high_resolution_clock::now();

    if(my_rank == 0){
        chrono::duration<double> elapsed = (finish - start);
        cout << "Time = " << elapsed.count() << " s " << endl;
        cout << MC  << endl;
        cout << 5*pi*pi/(16*16) << endl;
        cout << gauss - 5*pi*pi/(16*16) << endl;

    }


    delete [] X;
    delete [] W;
    delete [] phi_x;
    delete [] phi_w;
    delete [] theta_x;
    delete [] theta_w;

    return 0;
}

// Gå inn på build-Prosject3 tingen også helt inn også høyreklikk, åpne i terminal
// mpirun -n 4 ./main_function

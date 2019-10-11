#include <iostream>
#include <armadillo>
#include "mpi/mpi.h"
#include "gauss_legendre.h"

using namespace std;

int main(int nargs, char *args[])
{
    /*
    int numprocs, my_rank;
    MPI_Init(&nargs, &args);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    cout << my_rank << endl;
    */

    double lamda;
    int N;

    lamda = 1.0; N = 10;

    double* X = new double[N];
    double* W = new double[N]; //Weight

    cout << X[2] << endl;

    gauleg(-lamda, lamda, X, W, N); //Gauss Legendre

    cout << X[2] << endl;



    return 0;
}

// Gå inn på build-Prosject3 tingen også helt inn også høyreklikk, åpne i terminal
// mpirun -n 4 ./main_function

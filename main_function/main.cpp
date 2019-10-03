#include <iostream>
#include <armadillo>
#include "mpi/mpi.h"

using namespace std;

int main(int nargs, char *args[])
{
    int numprocs, my_rank;
    MPI_Init(&nargs, &args);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    cout << my_rank << endl;

    return 0;
}

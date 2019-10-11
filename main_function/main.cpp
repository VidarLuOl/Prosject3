#include <iostream>
#include <armadillo>
#include <chrono>
#include "mpi/mpi.h"
#include "gauss_legendre.h"
#include "integration_function.h"
#include "gauss_laguerre.h"

using namespace std;

int main(int nargs, char *args[])
{


    double      const  pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609;
    double lamda;
    int N;
    int alpha = 2;

    lamda = 2.3; N = 17;

    double* X = new double[N];
    double* W = new double[N]; //Weight

    int numprocs, my_rank;
    MPI_Init(&nargs, &args);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    cout << my_rank << endl;

    auto start = chrono::high_resolution_clock::now();

    //gauleg(-lamda, lamda, X, W, N); //Gauss Legendre
    gauss_laguerre(X, W, N, 0); //Gauss Laguerre
    double gauss = 0;
    for(int i1 = my_rank; i1 < N; i1+=numprocs){
        for(int i2 = 0; i2 < N; i2++){
            for(int i3 = 0; i3 < N; i3++){
                for(int i4 = 0; i4 < N; i4++){
                    for(int i5 = 0; i5 < N; i5++){
                        for(int i6 = 0; i6 < N; i6++){
                            gauss += W[i1]*W[i2]*W[i3]*W[i4]*W[i5]*W[i6]*integration_function(X[i1],X[i2],X[i3],X[i4],X[i5],X[i6], alpha);
                        }
                    }
                }
            }
        }
    }

    auto finish = chrono::high_resolution_clock::now();


    chrono::duration<double> elapsed = (finish - start);
    cout << "Time = " << elapsed.count() << " s " << endl;
    cout << gauss << endl;
    cout << 5*pi*pi/(16*16) << endl;

    return 0;
}

// Gå inn på build-Prosject3 tingen også helt inn også høyreklikk, åpne i terminal
// mpirun -n 4 ./main_function

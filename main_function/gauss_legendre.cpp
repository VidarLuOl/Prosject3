#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#define EPS 3.0e-14
#define MAXIT 10
#define   ZERO       1.0E-10
#include "integration_function.h"

using namespace std;

void gauleg(double x1, double x2, double x[], double w[], int n)
{
   int         m,j,i;
   double      z1,z,xm,xl,pp,p3,p2,p1;
   double      const  pi = 3.14159265359;
   double      *x_low, *x_high, *w_low, *w_high;

   m  = (n + 1)/2;                             // roots are symmetric in the interval
   xm = 0.5 * (x2 + x1);
   xl = 0.5 * (x2 - x1);

   x_low  = x;                                       // pointer initialization
   x_high = x + n - 1;
   w_low  = w;
   w_high = w + n - 1;

   for(i = 1; i <= m; i++) {                             // loops over desired roots
      z = cos(pi * (i - 0.25)/(n + 0.5));

           /*
       ** Starting with the above approximation to the ith root
           ** we enter the mani loop of refinement bt Newtons method.
           */

      do {
         p1 =1.0;
     p2 =0.0;

       /*
       ** loop up recurrence relation to get the
           ** Legendre polynomial evaluated at x
           */

     for(j = 1; j <= n; j++) {
        p3 = p2;
        p2 = p1;
        p1 = ((2.0 * j - 1.0) * z * p2 - (j - 1.0) * p3)/j;
     }

       /*
       ** p1 is now the desired Legrendre polynomial. Next compute
           ** ppp its derivative by standard relation involving also p2,
           ** polynomial of one lower order.
           */

     pp = n * (z * p1 - p2)/(z * z - 1.0);
     z1 = z;
     z  = z1 - p1/pp;                   // Newton's method
      } while(fabs(z - z1) > ZERO);

          /*
      ** Scale the root to the desired interval and put in its symmetric
          ** counterpart. Compute the weight and its symmetric counterpart
          */

      *(x_low++)  = xm - xl * z;
      *(x_high--) = xm + xl * z;
      *w_low      = 2.0 * xl/((1.0 - z * z) * pp * pp);
      *(w_high--) = *(w_low++);
   }
}

double gaulegcalc(double X[], double W[], int N, int alpha){
    double gauss = 0;
    for(int i1 = 0; i1 < N; i1++){
        for(int i2 = 0; i2 < N; i2++){
            for(int i3 = 0; i3 < N; i3++){
                for(int i4 = 0; i4 < N; i4++){
                    for(int i5 = 0; i5 < N; i5++){
                        for(int i6 = 0; i6 < N; i6++){
                            gauss += W[i1]*W[i2]*W[i3]*W[i4]*W[i5]*W[i6]
                                    *integration_legendre(X[i1],X[i2],X[i3],X[i4],X[i5],X[i6], alpha);
                        }
                    }
                }
            }
        }
    }

    return gauss;
}

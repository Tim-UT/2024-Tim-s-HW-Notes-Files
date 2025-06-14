/*
Part 1: Estimating the Square Root


double randDouble() {
    return (double)rand() / ((double)RAND_MAX);
  }

bool inBounds(double x, double y) {

  }
*/

// Pi = 4 * (number of points in circle) / (number of points in square)

#include <stdio.h>
//#include <math.h>
#include <stdbool.h>
#include <stdlib.h>


//first function, generate random value
double randDouble() {
    
  return (double)rand() / ((double)RAND_MAX);
}


//second function, check circle boundary
bool inBounds(double x, double y) {
    if (x*x + y*y <= 1) {
        return true;
    }
    else {
      return false;
    }
}



//main body function
int main(void) {

    int input;
    printf("Number of monte carlo iterations: ");   // input the number of iterations
    scanf("%d", &input);

    int incircle_count = 0;   //initial count
    srand(42);    //sand 42

    for (int count = 1; count <= input; count++) {
        double x_scale = randDouble();    //get x,y value randomly
        double y_scale = randDouble();
//printf("%lf, %lf\n", x_scale,y_scale);      //for test check
        bool incircle;
        incircle = inBounds(x_scale,y_scale);
//printf("%d\n",incircle);      //test return value
        incircle_count += incircle;

    }

    double Pi;
    Pi = 4 * (incircle_count / (double) input);   //calcu Pi

    printf("Pi: %.4lf\n", Pi);

return 0;

}
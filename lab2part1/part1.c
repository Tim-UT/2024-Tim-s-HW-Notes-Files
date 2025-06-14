//input the Circumference and Acceleration

/*
Planet radius: 6047.9 km
Planet mass: 5372.0 x 10^21 kg
Escape velocity: 10.9 km/s

v = sqrt((2*G*m)/r)
a = (G*m) / r^2

*/
#include <stdio.h>
#include <math.h>

    int main(void) {

        double circum, acceleration;
        const double G = 6.6726e-11;        //state constant
        const double PI = 3.14159265;

        double scaled_cir, radius, mass, velocity;

        printf("Circumference (km) of planet: ");       //input
        scanf("%lf", &circum);
        printf("Acceleration due to gravity (m/s^2) on planet: ");
        scanf("%lf", &acceleration);

        if (circum > 0) {       //judge vaild value
            
            if (acceleration > 0) {

                scaled_cir = circum * 1000;     //calculate
                radius = (scaled_cir/PI)/2;
                mass = ((acceleration * pow(radius, 2)) /1e15)/ G;
                velocity = sqrt(2 * acceleration * radius);

                printf("\n");
                printf("Calculating the escape velocity...\n");     //output

                printf("Planet radius: %.1lf km\n", radius/1000);       //calculate and print
                printf("Planet mass: %.1lf x 10^21 kg\n", mass/1e6);
                printf("Escape velocity: %.1lf km/s\n", velocity/1000);

            }

            else {

                printf("Please enter correct gravity\n");       //case1

            }
        }
        else {
            
            printf("Please enter correct circumference\n");     //case2

        }


    return 0;


    }



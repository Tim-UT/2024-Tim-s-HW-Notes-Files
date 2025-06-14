//String ?

#include <stdio.h>
#include <math.h>

 int main(void) {

    char input_1, input_2;
    double q_1, q_2, r;
    const double k = 8.9875;


    printf("Enter the value of the two charges separated by a space: ");        //input
    
    scanf("%lf%c%*c %lf%c%*c", &q_1, &input_1, &q_2, &input_2);

    printf("Enter distance between charges in metres: ");       //input

    scanf("%lf", &r);

if (r <= 0) {
    printf("Please enter correct value\n");     //case5
}
else {


    int unit_1, unit_2;

    unit_1 = (int)input_1;
    unit_2 = (int)input_2;

    //digit = 0;

   if (unit_1 == 117) {         //reoriganize units
        //digit += -9;
        
    }
    else {
        //digit += -9;
        q_1 /= 1000;
    }

    if (unit_2 == 117) {
        //digit += -9;
        
    }
    else {
        //digit += -9;
        q_2 /= 1000;
    }


    //digit +=9;


    double force;

    force = (k * fabs(q_1 * q_2))/pow(r, 2);        //calc force


    
    if (force <= 1e-3) {
        printf("The force between charges is %.2lfnN (less than 1uN)\n",force*1e6);     //case1
        
    }
    else {
        if (force <= 1) {
            printf("The force between charges is %.2lfuN (less than 1mN)\n",force*1000);        //case2

            }
            else {
                if (force <= 1000) {
                printf("The force between charges is %.2lfmN (less than 1N)\n",force);      //case3
                
                }
                else {
                    printf("The force between charges is %.2lfN (1N or greater)\n",force/1000);//case4
                    
                }
            }
        }
    
}


//printf("%lf,%lf, %c, %d\n",q_1, force,input_1, digit);
return 0;
}


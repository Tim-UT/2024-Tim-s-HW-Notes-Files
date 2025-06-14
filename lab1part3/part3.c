//Convert Centimeters to Feet and Inches
//2025/1/10

//1 foot = 12 inches
//1 inch = 2.54 cm

/*
1 ft = 30.48 cm
1 inch = 2.54 cm

1 cm = 0.3937 inch = 0.0328084 ft
*/


#include <stdio.h>

int main(void) {

    double input_cm, input, in_divide;
    int ft, inch;

    printf("Enter the length in centimeters (cm)\n");
    scanf("%lf", &input_cm);

    if (input_cm < 0) {
        printf("Please enter vaild number\n");
    }
    else {
    input = input_cm;

    in_divide = input / 2.54;
    ft = in_divide / 12;
    inch = in_divide - ft * 12;

    printf("The length is %dft %din\n",ft, inch);
    }
 
    return 0;

}
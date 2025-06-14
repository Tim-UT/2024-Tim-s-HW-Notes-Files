//iDonuts Shop
//2025/1/10

//buy 3 get 1 free
//13% Tax
//judge sign of input

//what's the hidden case???

#include <stdio.h>

int main(void) {

    int num_input, num_discount;
    double price_input, price, nontax_price;

    num_input = 0;

    printf("Enter the price per donut in CAD\n");
    scanf("%lf", &price_input);
    printf("Enter the number of donuts\n");
    scanf("%d", &num_input);

    if (price_input <= 0) {
        
        if (num_input <= 0) {
            printf("Please enter vaild price and number\n");

        }
        else {
            printf("Please enter vaild price\n");
        }
    }

    else if (num_input <= 0) {
        printf("Please enter vaild number\n");
    }

    else {

    num_discount = num_input / 4;
    nontax_price = (num_input - num_discount) * price_input;
    price = 1.13 * nontax_price;
    
    printf("You are getting %d free donut(s)\n", num_discount);
    printf("You should pay $%.2lf\n", price);
    }


return 0;
}

//ATM Machine
//100, 50, 20, 10, 5
//input must be a multiple of $5

#include <stdio.h>

int main(void) {

    int input;

    printf("Please enter an amount in dollars ($): ");      //input
    scanf("%d",&input);

    while (!(input % 5 == 0) || input <0 ) {
        printf("The amount should be a multiple of $5: ");      //check and get new input
        scanf("%d",&input);

    }

    //printf("%d",input);

    int v_100, v_50, v_20, v_10, v_5;           //varibles for calculation



    v_100 = input / 100;            //extract 100,50,20,10,5 in input
    input %= 100;
    v_50 = input /50;
    input %= 50;
    v_20 = input /20;
    input %= 20;
    v_10 = input /10;
    input %= 10;
    v_5 = input /5;

    //printf("%d,%d,%d,%d,%d\n",v_100,v_50,v_20,v_10, v_5);     TEST


if (!(v_100 == 0)) {                            //judge whether to print or not
    printf("$100: %d\n", v_100);
}
if (!(v_50 == 0)) {
    printf("$50: %d\n", v_50);
}
if (!(v_20 == 0)) {
    printf("$20: %d\n", v_20);
}
if (!(v_10 == 0)) {
    printf("$10: %d\n", v_10);
}
if (!(v_5 == 0)) {
    printf("$5: %d\n", v_5);
}

return 0;

}

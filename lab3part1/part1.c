// Substance Test
// Water        100
// Mercury      357
// Copper       1187
// Silver       2193
// Gold         2660
//f the data input is not within C of any of the boiling points in the table, the program should output the message: Substance unknown

#include <stdio.h>

int main(void) {

    double t, upper, down;                  //defi varibles
    int boil;
    printf("Enter the threshold in Celsius: ");       //input threshold and boiling point in Celsius
    scanf("%lf", &t);
    printf("Enter the observed boiling point in Celsius: ");      //input boiling point in Celsius
    scanf("%d", &boil);

    upper = boil + t;           //defi upper and downward boundaries
    down = boil - t;

        //printf("%lf, %lf",upper, down);


    if (upper >= 100 && down <= 100) {          //whether value in the scale or not? and print Water
      printf("The substance you tested is: Water\n");

    } 
        else if (upper >= 357 && down <= 357) {
            printf("The substance you tested is: Mercury\n");     //print the Mercury
        }
        else if (upper >= 1187 && down <= 1187) {
          printf("The substance you tested is: Copper\n");        //print the Copper 
        }
        else if (upper >= 2193 && down <= 2193) {
          printf("The substance you tested is: Sliver\n");        //print the Silver

        }
        else if (upper >= 2660 && down <= 2660) {
          printf("The substance you tested is: Gold\n");          //print the Gold
        }
        else {
          printf("Substance unknown.\n");     //print the unknown
        }

return 0;

}


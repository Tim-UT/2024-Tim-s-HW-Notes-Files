// abcd --> d(9-b)(9-c)a

#include <stdio.h>

    int main(void) {
        
        int input;
        //int judge;
        int first_digit, second_digit, third_digit, fourth_digit;
        //int final;

        //char input_c[10];       //input string to prevent over 4 digits input


        printf("Enter an encrypted 4-digit combination: \n");
        scanf("%d", &input);
/*

        first_digit = (int)input_c[0];          //get value
        second_digit = (int)input_c[1];
        third_digit = (int)input_c[2];
        fourth_digit = (int)input_c[3];
        extra = (int)input_c[4];



            first_digit -= 48;      //convert to number
            second_digit -= 48;
            third_digit -= 48;
            fourth_digit -= 48;
            //sum = 1000 * first_digit +100 * second_digit + 10 * third_digit + fourth_digit;
            judge = 1000 * fourth_digit +100 * third_digit + 10 * second_digit + first_digit;   //if the digits less than 4,the jugde will less than 0


        if (extra > 0) {        //judge whether digits more than 4

            printf("Please enter 4-digit combination\n");

        }
        else {

            //if (sum <1000)
            if (judge < 0) {        //judge whether digits less than 4
            printf("Please enter 4-digit combination\n");
            }
            else {
    
            printf("The real combination is: %d%d%d%d\n", fourth_digit, (9-second_digit), (9-third_digit),first_digit);     //print each digit
            }
        }
*/

        if (input < 10000) {

            first_digit = input % 10;       //using modulo to get digits
            input /=10;
            second_digit = input % 10;
            input /=10;
            third_digit = input % 10;
            input /=10;
            fourth_digit = input % 10;

            //final = first_digit * 1000 + (9 - third_digit) * 100 + (9 - second_digit) * 10 + fourth_digit;



            printf("The real combination is: %d%d%d%d\n", first_digit, (9-third_digit), (9-second_digit),fourth_digit);     //reorganized digits
            
            //printf("%d, %d, %c\n",first_digit, extra, input_c[0]);
            //printf("%d, %d, %d, %d", first_digit, second_digit, third_digit, fourth_digit);
        }

        //else {

            //printf("Please enter 4-digit combination\n");

        //}
        
    return 0;


    }

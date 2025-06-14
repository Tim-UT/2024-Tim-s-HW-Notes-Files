/*
Cellular Automaton

input: alive cell, rule number, # of iterations

loop to get new array and print previous
UNTIL loop iteration gone


*/

//declaim library
#include <stdio.h>


//FUNCTIONS
    //printArray function
        void printArray(int array[]) {
            for (int i = 0; i <= 20; i++){          //judge the condition and print
                if (array[i] == 1) {
                    printf("*");

                }
                else {
                    printf(" ");
                }
            }
        printf("\n");
        }


    //initializeArray function
        void initializeArray(int aliveIndex, int array[]){      //go through every cells
            for (int i = 0; i <= 20; i++){
                if (i == aliveIndex) {
                    array[i] = 1;

                }
                else {
                    array[i] = 0;
                }
            }
        }


    //getRuleOutcome function
        int getRuleOutcome(int rule, int left, int center, int right){
            int decimal = left * 100 + center * 10 + right;     //form three digits identify

            int bin[8] = {0};                       // get value in binary array
                for(int i = 0; i <= 7; i++){
                bin[i] = rule % 2;
                rule /= 2;
                }

            if (decimal == 0) {             //case judgement
                center = bin[0];
            }
            else if (decimal == 1) {
                center = bin[1];
            }
            else if (decimal == 10) {
                center = bin[2];
            }
            else if (decimal == 11) {
                center = bin[3];
            }
            else if (decimal == 100) {
                center = bin[4];
                
            }
            else if (decimal == 101) {
                center = bin[5];
            }
            else if (decimal == 110) {
                center = bin[6];
            }
            else if (decimal == 111) {
                center = bin[7];
            }
            return center;      //return center value to array
        }


//calculateNextState function
        void calculateNextState(int currentArray[], int nextArray[], int rule){
            int left = 0;
            int center = 0;
            int right = 0;
            

            for (int i = 0; i <= 20; i++) {     // loop for for cells in array
                left = 0;       //initialize
                center = 0;
                right = 0;
                

                if (i == 0) {       //first digits case
                    left = currentArray[20];
                    center = currentArray[0];
                    right = currentArray[1];

                }
                else if (i == 20) {     //last digits case
                    left = currentArray[19];
                    center = currentArray[20];
                    right = currentArray[0];
                    

                }
                else {              //normal case
                    left = currentArray[i-1];
                    center = currentArray[i];
                    right = currentArray[i+1];

                }
                
                nextArray[i] = getRuleOutcome(rule, left, center, right);       // to another function
                
            }

        }


        void simulateGenerations(int iterations, int array[], int rule) {
            
            for (int i = 0; i < iterations; i ++) {     // loop #
                printArray(array);      //print current array
                int nextarray[21] = {0};        //initialize array
                calculateNextState(array, nextarray, rule);     // to another function
                for (int j = 0; j <= 20; j++) {     // copy value from nextarray to array
                        array[j] = nextarray[j];
                }
            }

        }





//MAIN FUNCTION
    int main(void) {
        int Alive, Rule, Iteration;
        printf("Enter input: ");
        scanf("%d%d%d", &Alive, &Rule, &Iteration);     //get input


        int Array[21];      
        initializeArray(Alive, Array);      //initial array

        simulateGenerations(Iteration, Array, Rule);        //doing operations and print

    }

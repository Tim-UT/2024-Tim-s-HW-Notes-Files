/*
Connect Four
horizontally (left to right), vertically (top to bottom) and/or diagonally (both directions).

Yellow, please enter a valid column number (0-5): 
Red, please enter a valid column number (0-5):



*/

//defi
#include <complex.h>
#define ROWS 6
#define COLS 6
#define EMPTY '-'
#define RED 'R'
#define YELLOW 'Y'


//library
#include <stdio.h>
#include <stdbool.h>

//functions


//Print Function
void printBoard(char gameBoard[][COLS]) {
    for (int row = 0; row <ROWS; row ++) {              //Row, Col Loop
        for (int col = 0; col < COLS; col++) {      

                printf("%c",gameBoard[row][col]);       //print character
            
        }       


        printf("\n");
    }
}

//Get Input Function
int getInput(char gameBoard[][COLS], char turn) {   
    int input;                                //Variable Declaration
    int valid = 1;
    int full = 0;

    do {                            //Do While Loop to check if the input is valid
        valid = 1;
        if (turn == RED) {
            printf("Red, please enter a valid column number (0-5): ");
        }
        else {
            printf("Yellow, please enter a valid column number (0-5): ");
        }
        scanf("%d", &input);

        if (input > 5 || input < 0) {       //Check if the input is within the range
            valid = 0;

        }
       
            if (gameBoard[0][input] != EMPTY) {     //Check if the col is full
                valid = 0;
            }


            full =0;
            int count=0;
            int empty_col = 0;
            for (int col = 0; col < COLS; col++) {      //Check if the first row is full
                
                
                if (gameBoard[0][col] == EMPTY) {
                    
                        count += 1;         //Count the number of empty columns
                        empty_col= col;     //Store the empty column for further judgement

                }
                
            }
            if (count == 1 && gameBoard[1][empty_col] != EMPTY) {           //If there is only one empty column and only has one space, the game is a tie

                full = 1;       //Set full to 1
            }
        
        
        

    } while (valid == 0 && full == 0);      //Loop until the input is valid
    
    if (full == 1) {        //If the game is a tie, return the input + 10 (it will store the input and help to judge the fulfill situation)
        input = input+10;
    }
    
    return input;

}


//Insert Piece Function
void insertPiece(char gameBoard[][COLS], int columnEntered, char turn) {
    int count = 0;
    for (int row = 5; row >=0 && count == 0; row--) {       //search from the bottom to the top
        if (gameBoard[row][columnEntered]== EMPTY) {
            gameBoard[row][columnEntered] = turn;
            count = 1;      //avoid insert more than once
        }
    }

}


//Switch Turn Function
void switchTurn(char* turn){
    if (*turn == RED) {     //if the turn is red, switch to yellow
        *turn = YELLOW;
    }
    else {
        *turn = RED;        //if the turn is yellow, switch to red
    }

}


//Same for Four Function
bool sameforfour(char gameBoard[][COLS], bool win, int row, int col, int rowDir, int colDir) {
    char firstposition = gameBoard[row][col];       //Store the first position to compare
    if (firstposition == EMPTY) {       //avoid comparing with empty
        firstposition = 'F';
    }
    win=true;
                for (int i = 1; i <= 3 && win == 1; i++) {      //check the rest of three positions
                    if (gameBoard[row-i*rowDir][col +i*colDir] != firstposition){
                        win = false;
                    }
                }   
return win;
}

//Check One Direction Function
bool checkOneDirection(char gameBoard[][COLS], int row, int col, int rowDir, int colDir) {
    bool win=false;     //Set win to false
        if (rowDir ==0) {
            if (colDir ==1 && col+3 < 6) {      //Check if the column is within the range

                win=sameforfour(gameBoard, win, row, col, rowDir, colDir);      //judge the four positions
                /*true;
                for (int i = 1; i <= 3 && win == 1; i++) {
                    if (gameBoard[row-i*rowDir][col +i*colDir] != firstposition){
                        win = false;
                    }
                }   */


            }
            else if (colDir == -1 && col -3 >-1) {      //Check if the column is within the range
                win=sameforfour(gameBoard, win, row, col, rowDir, colDir);

            }
            
            
        }
        else if (rowDir ==1 && row -3 > -1) {       //Check if the row is within the range
            if (colDir ==1 && col+3 < 6) {      //Check if the column is within the range

                win=sameforfour(gameBoard, win, row, col, rowDir, colDir);

            }
            else if (colDir == -1 && col -3 >-1) {      //Check if the column is within the range

                win=sameforfour(gameBoard, win, row, col, rowDir, colDir);

            }
            else if (colDir == 0) {

                win=sameforfour(gameBoard, win, row, col, rowDir, colDir);

            }
            
            
        }
        else if (rowDir == -1 && row + 3 < 6) {     //Check if the row is within the range
            if (colDir ==1 && col+3 < 6) {      //Check if the column is within the range

                win=sameforfour(gameBoard, win, row, col, rowDir, colDir);

            }
            else if (colDir == -1 && col -3 >-1) {      //Check if the column is within the range

                win=sameforfour(gameBoard, win, row, col, rowDir, colDir);

            }
            else if (colDir == 0) {

                win=sameforfour(gameBoard, win, row, col, rowDir, colDir);
                //if (win) {printf("local %d,%d\n",row,col);
                //}   
            }
            
        }    
    return win;
}


//Check Winner Function
bool checkWinner(char gameBoard[][COLS]) {
    bool win = false;       //Set win to false
    
    for (int row = 0; row < ROWS && win == false; row++) {     //Row, Col Loop
        for (int col = 0; col < COLS && win == false; col++) {
            for (int rowDir = -1; rowDir <= 1 && win == false; rowDir++) {      //Check all the directions
                for (int colDir = -1; colDir <= 1 && win == false; colDir++) {
                    //printf("%d, %d\n",rowDir, colDir);
                    win = checkOneDirection(gameBoard, row, col, rowDir, colDir);       //Check if there is a winner
                    
                    
        
                }
            }
            

        }
    }
    return win;
}







//Main Function
    int main(void) {
        char gameBoard[ROWS][COLS] = {      //empty board
        { '-', '-', '-', '-', '-', '-' },
        { '-', '-', '-', '-', '-', '-' },
        { '-', '-', '-', '-', '-', '-' },
        { '-', '-', '-', '-', '-', '-' },
        { '-', '-', '-', '-', '-', '-' },
        { '-', '-', '-', '-', '-', '-' }};
        int columnEntered = 1;
        char turn = RED;        //initialise the turn to red
        bool win = false;       //initialise win to false
        int out = 0;           
        while (win == false && out < 9) {
            
            printBoard(gameBoard);
            columnEntered = getInput(gameBoard, turn);
            //printf("input: %d\n",columnEntered);
            if (columnEntered >10) {
                out = columnEntered;        //if it's over 10, it means the game is a tie, and break the loop
                columnEntered = columnEntered -10;

                printf("It's a tie\nFinal board: \n");      //print it's a tie
                
            
            }
            
            insertPiece(gameBoard, columnEntered, turn);        //insert the piece
            switchTurn(&turn);                                  //switch the turn
            win = checkWinner(gameBoard);                       //check if there is a winner    
               
        }
            

            if (win) {
                if (turn == RED) {          //if the turn is red, yellow wins
                    printf("Yellow wins!\nFinal board: \n");        
                    
                
                }
                if (turn == YELLOW) {       //if the turn is yellow, red wins
                    printf("Red wins!\nFinal board: \n");
                    
                
                }
            }
            
            printBoard(gameBoard);      //print the final board
            

        return 0;

    }
        //printf("out");
       
    
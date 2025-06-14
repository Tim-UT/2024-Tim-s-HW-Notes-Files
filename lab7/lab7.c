//library declare
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "reversi.h"

//function declare
void printBoard(char board[][26], int n);

bool positionInBounds(int n, int row, int col);

bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
                        
void InitializeBoard(char board[][26], int n);                  

bool checkLegalInDirection_return(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);


//-------------------------------------------------------------------------------------------------------------------------------
//main function
int main(void) {
  char board[26][26] = {
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'},
    {'U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U','U'}
};


//get the board dimension
  int n;
  printf("Enter the board dimension: ");
  scanf("%d", &n);


  //initialize
  InitializeBoard(board, n);
  printBoard(board, n);

  //Vaild Movement
  printf("Available moves for W:\n");   //check vaild for white
  for (int row_check = 0; row_check < n; row_check++) {       //board point loop to check every point
    for (int col_check = 0; col_check < n; col_check++) {
      bool valid = false;
        for (int delta_row = -1; delta_row <= 1 && valid == false; delta_row++) {     //direction loop
          for (int delta_col = -1; delta_col <= 1 && valid == false; delta_col++){
            if (delta_row != 0 || delta_col != 0) {

                valid = checkLegalInDirection(board, n, row_check, col_check, 'W', delta_row, delta_col);   //check whether the point is vaild
              }
            }
          }
          if (valid) {
            printf("%c%c\n", row_check+97,col_check+97);    //print the vaild point (+97 to 'a)
          }
      }
    }


  printf("Available moves for B:\n");   //check vaild for black
  for (int row_check = 0; row_check < n; row_check++) {     //board point loop to check every point
    for (int col_check = 0; col_check < n; col_check++) {
      bool valid = false;
        for (int delta_row = -1; delta_row <= 1 && valid == false; delta_row++) {   //direction loop
          for (int delta_col = -1; delta_col <= 1 && valid == false; delta_col++){
            if (delta_row != 0 || delta_col != 0) {

              valid = checkLegalInDirection(board, n, row_check, col_check, 'B', delta_row, delta_col);   //check whether the point is vaild
            }
          }
        }
        if (valid) {
          printf("%c%c\n", row_check+97,col_check+97);  //print the vaild point
          }
      }
    }

//Movement
  char row, col;
  char color;
  int row_value, col_value;
  printf("Enter a move:\n");
  bool valid_move = false;
  
    scanf(" %c%c%c", &color, &row, &col);   //input the movement
    //int current_row=0, current_col=0;
    row_value = row - 'a';
    col_value = col - 'a';
    int out_index=0;
    for (int delta_row = -1; delta_row <= 1 ; delta_row++) {
      for (int delta_col = -1; delta_col <= 1 ; delta_col++){
        valid_move = false;
        if (delta_row != 0 || delta_col != 0) {
          //current_row=0, current_col=0;

          //int index = 0;
  
          valid_move = checkLegalInDirection_return(board, n, row_value, col_value, color, delta_row, delta_col);     //a modified function to check the vaild movement and change the board
          if (valid_move) {
            /*
            current_row = delta_row;
            current_col = delta_col;
            board[row_value+current_row][col_value+current_col] = color;
            */
            out_index++;    //record the status of vaild movement
          }
        }
      }
    }
    if (out_index != 0) {   //if there is a vaild movement
      printf("Valid move.\n");
      board[row_value][col_value] = color;    //put the original point to its color
      

      printBoard(board, n);   //print the board
      
    }
    else {
      printf("Invalid move.\n");

      printBoard(board, n);
      //valid_move = true;
      
    }

/*
  bool Inbound = positionInBounds(n, row, col);
  printf("%d\n", Inbound);
  int delta_row = 1;
  int delta_col = 1;
  printf("%d\n", checkLegalInDirection( board, n, row, col, 'B', delta_row,delta_col));

  
*/

  return 0;
}


//-------------------------------------------------------------------------------------------------------------------------------


//function define
void InitializeBoard(char board[][26], int n) {                                     //initialize the board and configue the board
  int middle = n/2;   //find the middle of the board
  board[middle][middle] = 'W';      //initialize the middle pattern of the board
  board[middle-1][middle-1] = 'W';
  board[middle-1][middle] = 'B';
  board[middle][middle-1] = 'B';
  printBoard(board, n);     //print the initialize board
  printf("Enter board configuration:\n");


  char color = 'B', rowLocation = 'a', colLocation = 'a';
  int rowValue, colValue;

  do {

    scanf(" %c%c%c", &color, &rowLocation, &colLocation);   //configure the board
    rowValue = rowLocation - 'a';   //get location of rows and columns

    colValue = colLocation - 'a';
    //printf("%c,%c,%c\n",color,rowLocation,colLocation);
    //printf("%d,%d\n",rowValue,colValue);
    board[rowValue][colValue] = color;

    } while (color != '!' && rowLocation != '!' && colLocation != '!');   //end the configuration  

}

void printBoard(char board[][26], int n) {                                  //print the board
  printf("  ");        //Align Coordinates
  for (int letter = 'a';letter - 'a' < n; letter++) {   //print horizontal coordinates
    printf("%c",letter);
  }
  printf("\n");
  for (int row = 0; row < n; row++) {
    printf("%c ",row+97);         //print vertical coordinates

    for (int col = 0; col < n; col++) {
      printf("%c", board[row][col]);      //print color of each point
    }
    printf("\n");
  }
}

bool positionInBounds(int n, int row, int col) {                            //check the position is in the board
  bool inbound = true;
  if (row >= n || col >= n) {       //have to satisfy both conditions at the same time
    inbound = false;
  }
  return inbound;
}

/*
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) {
  bool legal = false;
  
  if (positionInBounds(n, row+2*deltaRow, col+2*deltaCol) && legal == false && board[row][col] == 'U') {

  if (board[row+2*deltaRow][col+2*deltaCol]==colour) {
    char reversedColor;
    if (colour == 'B'){
      reversedColor = 'W';
    }
    else {
      reversedColor = 'B';
    }
    if (board[row+deltaRow][col+deltaCol] == reversedColor) {
      legal = true;

    }
  }
}
  return legal;

}
  */




bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) {                    //check the movement is vaild
  bool legal = false;
  char reversedColor;
  if (colour == 'B'){       //get reversed color
    reversedColor = 'W';
  }
  else {
    reversedColor = 'B';
  }

  for (int index = 2; index <= n && legal==false; index++) {

    if (positionInBounds(n, row+index*deltaRow, col+index*deltaCol) && legal == false && board[row][col] == 'U') {      //check the point is in the board to avoid memory leak and not occupied

      if (board[row+index*deltaRow][col+index*deltaCol]==colour) {      //check the point is occupied by the same color in this direction
        
        bool innervaild = true;
        for (int inner_index = 1; inner_index < index && legal == false && innervaild; inner_index++) {   //between the point and the same color point is occupied by the reversed color
          
          if (board[row+inner_index*deltaRow][col+inner_index*deltaCol] != reversedColor && innervaild) {
            innervaild = false;
      
          }         

        }
        if (innervaild) {
          legal=true;
        }
               
      }
    }

  }
  
  return legal;

}

bool checkLegalInDirection_return(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) {         //it's a modified function to check the vaild movement and change the board
  //int index_return= 0;
  bool legal = false;
  char reversedColor;
  if (colour == 'B'){
    reversedColor = 'W';
  }
  else {
    reversedColor = 'B';
  }

  /*
  int horizontal, vertical;
  if (deltaRow == 1) {
    if (deltaCol == 1) {
      horizontal = n - row;
      vertical = n - row;
      if (horizontal> vertical) {
        index_return = &vertical;

      }
      else {
        index_return = &horizontal;
      }


    }
    if (deltaCol == 0) {

    }
  }
*/
  for (int index = 2; index <= n; index++) {

    if (positionInBounds(n, row+index*deltaRow, col+index*deltaCol) && legal == false && board[row][col] == 'U') {

      if (board[row+index*deltaRow][col+index*deltaCol]==colour) {

        bool innervaild = true;
        for (int inner_index = 1; inner_index < index && legal == false && innervaild; inner_index++) {
          
          if (board[row+inner_index*deltaRow][col+inner_index*deltaCol] != reversedColor && innervaild) {         //same with the function above so far
            innervaild = false;
            
      
          }
          
        }
        if (innervaild) {
          for (int index_change = 1; board[row+index_change*deltaRow][col+index_change*deltaCol] == reversedColor; index_change++) {      //the loop to change the board
            board[row+index_change*deltaRow][col+index_change*deltaCol] = colour;
            
          }

          legal=true;
        }
          
      }
    }

  }

  return legal;

}

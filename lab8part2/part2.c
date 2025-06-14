//library declare
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "lab8part2.h"
#include "liblab8part2.h"

//function declare
void printBoard(char board[][26], int n);

bool positionInBounds(int n, int row, int col);

bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
                        
void InitializeBoard(char board[][26], int n);                  

bool checkLegalInDirection_return(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);

int checkScoreInDirection(const char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
void InitializeScoreBoard(const char board[][26],int score_board[][26], int n, char computer);
//bool checkforWin(char board[][26], int n, char colour);
bool checkforFull(char board[][26], int n);
bool checkforValid(char board[][26], int n, int score_board[][26], char color);
void initializeWeightedBoard (int board[][26], int n);
//void findSmarterMove(const char board[][26], int n, char turn, int *row, int *col);
int valid_count (char board[][26], int n, char color);


//-------------------------------------------------------------------------------------------------------------------------------
//main function
/*int main(void) {
  int score_board[26][26];
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
  //printBoard(board, n);

  char computer_color;

  printf("Computer plays (B/W) : ");
  scanf(" %c",&computer_color);
  //printf("%c", computer_color);
  printBoard(board, n);
  char reversedColor;
  if (computer_color == 'B'){       //get reversed color
    reversedColor = 'W';
  }
  else {
    reversedColor = 'B';
  }




  char human_row, human_col;
  int last = 0;
  int first_to_run=0;

  while (checkforFull(board, n)==false) {               //run the main process while the board isn't full
    //printf("%c", computer_color);
    


    if (computer_color == 'B'&&first_to_run==0) {               //black goes first
      first_to_run++;
      //printf("detect");

      InitializeScoreBoard(board, score_board, n, computer_color);
    int biggest_row = n, biggest_col = n;
    int biggest = 0;
  
    for (int row_index = n-1; row_index >=0; row_index--) {
      for (int col_index = n-1; col_index >=0; col_index--) {
        if (score_board[row_index][col_index] >= biggest) {
          biggest = score_board[row_index][col_index];
          biggest_row = row_index;
          biggest_col = col_index;
        }
        


      }
    }
    //printf("location%d%d\n",biggest_row, biggest_col);
    printf("Computer places %c at %c%c.\n",computer_color, (char)(biggest_row+97), (char)(biggest_col+97));
    //board[biggest_row][biggest_col] = computer_color;



    int out_index=0;
    for (int delta_row = -1; delta_row <= 1 ; delta_row++) {
      for (int delta_col = -1; delta_col <= 1 ; delta_col++){
        bool valid_move = false;
        if (delta_row != 0 || delta_col != 0) {
          
  
          valid_move = checkLegalInDirection_return(board, n, biggest_row, biggest_col, computer_color, delta_row, delta_col);     //a modified function to check the vaild movement and change the board
          if (valid_move) {
            
            out_index++;    //record the status of vaild movement
          }
        }
      }
    }
    board[biggest_row][biggest_col] = computer_color;
    printBoard(board, n);

    }
    

    
    if (checkforValid(board, n, score_board, reversedColor)==false) {         //only have valid next step then the next bet continue
      if (checkforFull(board, n)==false) {
        printf("%c player has no valid move.\n", reversedColor);            //if the board is not full, than print unvalid
      

      }
      last = 1;   //mark human
      
    }

    if (last ==0||last==-1) {
      last=0;
      //int smart_row, smart_col;
      //char smart_color;
      //findSmarterMove(board, n, smart_color, &smart_row, &smart_col);
      //printf("Testing AI move (row, col): %c%c\n", smart_row + 'a', smart_col + 'a');
      printf("Enter move for colour %c (RowCol): ",reversedColor);      //human input
      scanf(" %c%c", &human_row, &human_col);
    int row_value, col_value;
    bool valid_move = false;
    row_value = human_row - 'a';
    col_value = human_col - 'a';
    int out_index=0;
    for (int delta_row = -1; delta_row <= 1 ; delta_row++) {
      for (int delta_col = -1; delta_col <= 1 ; delta_col++){
        valid_move = false;
        if (delta_row != 0 || delta_col != 0) {
          //current_row=0, current_col=0;

          //int index = 0;
  
          valid_move = checkLegalInDirection_return(board, n, row_value, col_value, reversedColor, delta_row, delta_col);     //a modified function to check the vaild movement and change the board
          if (valid_move) {
            
            out_index++;    //record the status of vaild movement

          }
          
        }
      }
    }
    if (out_index != 0) {   //if there is a vaild movement
      //printf("Valid move.\n");
      board[row_value][col_value] = reversedColor;    //put the original point to its color
      

      printBoard(board, n);   //print the board
      
    }
    else if (checkforFull(board, n)==false) { 
      printf("Invalid move.\n%c player wins.\n", computer_color);
      return 0;

      //printBoard(board, n);
      //valid_move = true;
      
    }
    
    }
    


    if (checkforValid(board, n, score_board, computer_color)==false) {
      if (checkforFull(board, n)==false) {
        printf("%c player has no valid move.\n", computer_color);
      

      }
      last = -1;      //mark as computer
    }



    if (last==0||last==1) {
      last=0;
      InitializeScoreBoard(board, score_board, n, computer_color);        //generate score board to select best bet
    int biggest_row = n, biggest_col = n;
    int biggest = 0;
  
    for (int row_index = n-1; row_index >=0; row_index--) {
      for (int col_index = n-1; col_index >=0; col_index--) {
        if (score_board[row_index][col_index] >= biggest) {
          biggest = score_board[row_index][col_index];
          biggest_row = row_index;
          biggest_col = col_index;                                        //find best point
        }
        


      }
    }
    //printf("location%d%d\n",biggest_row, biggest_col);
    printf("Computer places %c at %c%c.\n",computer_color, (char)(biggest_row+97), (char)(biggest_col+97));
    //board[biggest_row][biggest_col] = computer_color;



    int out_index=0;
    for (int delta_row = -1; delta_row <= 1 ; delta_row++) {
      for (int delta_col = -1; delta_col <= 1 ; delta_col++){
        bool valid_move = false;
        if (delta_row != 0 || delta_col != 0) {
          
  
          valid_move = checkLegalInDirection_return(board, n, biggest_row, biggest_col, computer_color, delta_row, delta_col);     //a modified function to check the vaild movement and change the board
          if (valid_move) {
            
            out_index++;    //record the status of vaild movement
          }
        }
      }
    }
    board[biggest_row][biggest_col] = computer_color;
    printBoard(board, n);
    //printf("%d",last);
    

    }
    
  }


  


  //printf("detect\n\n\n");
  if (checkforFull(board, n)){      //judge full board situation
    
    int count_B=0, count_W=0;
    for (int row = 0; row < n; row++) {
      for (int col = 0; col < n; col++) {
        if (board[row][col]=='B') {
          count_B++;
          
  
        }
        else if (board[row][col]=='W') {
          count_W++;
        }


  
      }
    }
    if (count_B > count_W) {                      //if the point of black more than white, then black win
      printf("B player wins.\n");


    }
    else if (count_B <= count_W) {                  //white win
      printf("W player wins.\n");
      
      
    }


  }
  else if (last!=0) {
    printf("%c player wins.\n", reversedColor);
    
    
  }

  



  return 0;
}
*/

//-------------------------------------------------------------------------------------------------------------------------------

void InitializeScoreBoard(const char board[][26],int score_board[][26], int n, char computer) {
  int Score;



  for (int row_check = 0; row_check < n; row_check++) {     //board point loop to check every point
    for (int col_check = 0; col_check < n; col_check++) {
      Score = 0;
      bool valid = false;
        for (int delta_row = -1; delta_row <= 1 && valid == false; delta_row++) {   //direction loop
          for (int delta_col = -1; delta_col <= 1 && valid == false; delta_col++){
            if (delta_row != 0 || delta_col != 0) {
              //char color = board[row_check][col_check];

              Score += checkScoreInDirection(board, n, row_check, col_check, computer, delta_row, delta_col);
            }
          }
        }
        score_board[row_check][col_check] = Score;
        //printf("%d\n",Score);
      }
    }

} 


int checkScoreInDirection(const char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) {                    //check the movement is vaild
  bool legal = false;
  int count_score;
  char reversedColor;
  if (colour == 'B'){       //get reversed color
    reversedColor = 'W';
  }
  else {
    reversedColor = 'B';
  }
  count_score=0;
  for (int index = 1; index <=n && positionInBounds(n, row+index*deltaRow, col+index*deltaCol) && board[row][col] == 'U' && board[row+index*deltaRow][col+index*deltaCol] == reversedColor; index++) {
    count_score++;

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
  if (legal==false) {
    count_score = 0;
  } 

  return count_score;
  
  //return legal;

}


//function define
void InitializeBoard(char board[][26], int n) {                                     //initialize the board and configue the board
  int middle = n/2;   //find the middle of the board
  board[middle][middle] = 'W';      //initialize the middle pattern of the board
  board[middle-1][middle-1] = 'W';
  board[middle-1][middle] = 'B';
  board[middle][middle-1] = 'B';
  //printBoard(board, n);     //print the initialize board
  

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


//not used, error function
bool checkforWin(char board[][26], int n, char colour) {                    //check the movement is vaild
  //char colour = board[row][col];
  bool legal = false;
  /*char reversedColor;
  if (colour == 'B'){       //get reversed color
    reversedColor = 'W';
  }
  else {
    reversedColor = 'B';
  }
  */

  for (int row_check = 0; row_check < n; row_check++) {       //board point loop to check every point
    for (int col_check = 0; col_check < n; col_check++) {
      bool valid = false;
        for (int delta_row = -1; delta_row <= 1 && valid == false; delta_row++) {     //direction loop
          for (int delta_col = -1; delta_col <= 1 && valid == false; delta_col++){
            if (delta_row != 0 || delta_col != 0) {



              for (int index = 1; index <= 3 && legal==true; index++) {
                legal= true;
            
                  if (board[row_check+index*delta_row][col_check+index*delta_col] == colour && positionInBounds(n, row_check+3*delta_row, col_check+3*delta_col) && legal == true) {
                    
                  }
                  else {
                    legal = false;
                  }
            
            
              }




              }
            }
          }
          if (legal) {
            printf("%c%c\n", row_check+97,col_check+97);    //print the vaild point (+97 to 'a)
          }
      }
    }

  
  return legal;

}

//check whether the board is full or not
bool checkforFull(char board[][26], int n) {
  bool full = false;
  int countempty = 0;
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (board[row][col]=='U') {
        countempty++;

      }

    }
  }
  if (countempty < 1) {
    full = true;
  }
  return full;

}


//check whether next bet has any possible position
bool checkforValid(char board[][26], int n, int score_board[][26], char color) {
  bool valid = true;
  InitializeScoreBoard(board, score_board, n, color);
  
    //int biggest_row = n, biggest_col = n;
    int biggest = 0;
  
    for (int row_index = n-1; row_index >=0; row_index--) {
      for (int col_index = n-1; col_index >=0; col_index--) {
        if (score_board[row_index][col_index] >= biggest) {
          biggest = score_board[row_index][col_index];
          //biggest_row = row_index;
          //biggest_col = col_index;
        }
        


      }
    }
    if (biggest==0) {       //if the scoreboard is all zero, then it's invalid
      valid = false;
    }
    return valid;



}



int makeMove(const char board[][26], int n, char turn, int *row, int *col) {
  int score_board_1[26][26];
  int Weighted_scoce_board[26][26];
  initializeWeightedBoard (Weighted_scoce_board, n);
 
  
  InitializeScoreBoard(board, score_board_1, n, turn);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      score_board_1[i][j] = score_board_1[i][j] * Weighted_scoce_board[i][j];
    }
  }




  char reversedColor;
  if (turn == 'B'){
    reversedColor = 'W';
  }
  else {
    reversedColor = 'B';
  }


  int mytrun=valid_count (board,  n, turn);
  char board_copy[26][26];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      board_copy[i][j] = board[i][j];
    }
  }





  int difference_step = -100;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {



    //char row, col;
    //row = i;
    //col = j;
    //char color;
    int row_value, col_value;
    //printf("Enter a move:\n");
    bool valid_move = false;
  
    //scanf(" %c%c%c", &color, &row, &col);   //input the movement
    //int current_row=0, current_col=0;
    row_value = i;
    col_value = j;
    int out_index=0;
    for (int delta_row = -1; delta_row <= 1 ; delta_row++) {
      for (int delta_col = -1; delta_col <= 1 ; delta_col++) {
        valid_move = false;
        if (delta_row != 0 || delta_col != 0) {
          //current_row=0, current_col=0;

          //int index = 0;
  
          valid_move = checkLegalInDirection(board_copy, n, row_value, col_value, reversedColor, delta_row, delta_col);     //a function to check the vaild movement of user
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
      //printf("Valid move.\n");
      board_copy[row_value][col_value] = reversedColor;    //put the original point to its color
      

      //printBoard(board, n);   //print the board
      
    }
    else {
      //printf("Invalid move.\n");

      //printBoard(board, n);
      //valid_move = true;
      
    }

    int youtrun=valid_count (board_copy,  n, reversedColor);    //check the opposite's board valid count

    difference_step = mytrun- youtrun+5;      //find the different of each position, the 5 is experimental value, but it's must over 1 to aviod time 0 in next step
    //printf("%d",difference_step);
    //printf("\n%d\n",n);


    
  

      

    score_board_1[i][j] *= difference_step;   //time the index of step difference, make sure the step we do is most efficient



    }
  }


  
    int biggest = -100000;    //get a pretty low initilal value help to compare in next step
  
    for (int row_index = n-1; row_index >=0; row_index--) {
      for (int col_index = n-1; col_index >=0; col_index--) {
        if (score_board_1[row_index][col_index] >= biggest &&score_board_1[row_index][col_index]!=0) {
          biggest = score_board_1[row_index][col_index];
          *row = row_index;   //asign row to the best
          *col = col_index;   //same 
        }
        


      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
          //printf("%3.d",score_board[i][j]);

      }
      //printf("\n");
    }






    if (biggest==-100000) {
      return false;
    }
    else {
      return true;
    };

    

  
}

void initializeWeightedBoard (int board[][26], int n) {             //reference: https://reversiworld.wordpress.com/
  //the website provide a basic concept of weight distribution
  //based on this statagy is suitable my code, because I used score board previously
  //the weight is based on personal experience and been trained by myself

  for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
          board[i][j]=0;
      }
  }






  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {



      if (i==0||i==n-1) {
        if (j==0||j==n-1) {
          board[i][j] = 12;    //corner

        }

      }





      if ((i==1||i==n-2) &&board[i][j] ==0) {
        if (j==0||j==n-1) {
          board[i][j] = -2;    //subcorner

        }
        
      }
      if ((j==1||j==n-2)&&board[i][j] ==0) {
        if (i==0||i==n-1) {
          board[i][j] = -2;    //subcorner

        }
        
      }





      if ((i==1||i==n-2) &&board[i][j] ==0) {
        if ((j==1||j==n-2)&&board[i][j] ==0) {
          board[i][j] = -4;    //diagonal subcorner

        }

      }




      if ((i==2||i==n-3) &&board[i][j] ==0) {
        if ((j==2||j==n-3)&&board[i][j] ==0) {
          board[i][j] = 2;    //diagonal sub-subcorner

        }

      }





      if ((i==2||i==n-3) &&board[i][j] ==0) {
        if (j==0||j==n-1) {
          board[i][j] = 2;    //sub-subcorner

        }
        
      }
      if ((j==2||j==n-3)&&board[i][j] ==0) {
        if (i==0||i==n-1) {
          board[i][j] = 2;    //sub-subcorner

        }
      }




      if ((i==0||i==n-1||j==0||j==n-1)&&board[i][j] ==0) {
        board[i][j] = 1;    //sidelines


      }



      if ((i==1||i==n-2||j==1||j==n-2)&&board[i][j] ==0) {
        board[i][j] = -1;    //sub-sidelines


      }

      if (board[i][j] ==0) {
        board[i][j] = 1;    //middle

      }


      



    }


  }
/*
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
          printf("%3.d",board[i][j]);

      }
      printf("\n");
  }
*/
  


}

int valid_count (char board[][26], int n, char color) {
  int count=0;
  for (int row_check = 0; row_check < n; row_check++) {     //board point loop to check every point
    for (int col_check = 0; col_check < n; col_check++) {
      bool valid = false;
        for (int delta_row = -1; delta_row <= 1 && valid == false; delta_row++) {   //direction loop
          for (int delta_col = -1; delta_col <= 1 && valid == false; delta_col++){
            if (delta_row != 0 || delta_col != 0) {

              valid = checkLegalInDirection(board, n, row_check, col_check, color, delta_row, delta_col);   //check whether the point is vaild
            }
          }
        }
        if (valid) {
          count++;

          //printf("%c%c\n", row_check+97,col_check+97);  //print the vaild point
          }
      }
    }
    return count;
}
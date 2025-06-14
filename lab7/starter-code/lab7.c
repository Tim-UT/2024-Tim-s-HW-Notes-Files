#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "reversi.h"

int main(void) {
  char board[26][26];
  int n;

  printf("Enter the board dimension: ");
  scanf("%d", &n);

  return 0;
}

void printBoard(char board[][26], int n) {}

bool positionInBounds(int n, int row, int col) {}

bool checkLegalInDirection(char board[][26], int n, int row, int col,
                           char colour, int deltaRow, int deltaCol) {}
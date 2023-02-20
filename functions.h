/*************************
*Yash Patel                      *
*CPSC 2311 Sprint 23 Section 005 *
*yjpatel                         *
*Instructor: Dr. Yvon Feaster     *
*************************/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//prototypes
int** readFile(FILE* fp, int *size);
void printMatrix (int** mat, int num);
int calculateVal(int **mat, int size);
bool isRightDiagonal(int size, int row, int col);
bool isLeftDiagonal(int row, int col);
#endif

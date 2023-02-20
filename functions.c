/*************************
 *Yash Patel                      *
 *CPSC 2311 Sprint 23 Section 005 *
 *yjpatel                         *
 Instructor: Dr. Yvon Feaster     *
 *************************/
#include "functions.h"

//This function will read the file and return a 2D array. It will be called
//from the driver.c file.
int** readFile(FILE* fp, int *size)
{
    //read file
    fscanf(fp, "%d", size);
    int num = *size;
    int index = 0;


    //allocate memory
    int** mat = (int**)malloc(num * sizeof(int*));

    //check if memory allocated
    for(index = 0; index < num; index++)
        mat[index] = (int*)malloc(num * sizeof(int));

    //read file
    int row = 0; 
    int col = 0;
    //nested for loop to read file
    for(row = 0; row < num; row++)
    {
        for(col = 0; col < num; col++)
        {
            fscanf(fp, "%d", &mat[row][col]);
        }
    }
    //return matrix
    return mat;
}

//This function will print the matrix. It will be called from the driver.c
//file.
void printMatrix (int** mat, int num)
{
    //print matrix
    int row = 0; 
    int col = 0;

    //nested for loop to print matrix
    for(row = 0; row < num; row++)
    {
        for(col = 0; col < num; col++)
        {
            printf("%.2d\t", mat[row][col]);
        }
        printf("\n");
    }
    
}

/*int calculateVal(int** mat, int size); - This function will return a sum of 
all values of the matrix except those that are located on the left and right
diagonals. As an example, consider the following 5 X 5 matrix: The values in
red, highlighted in blue are the left diagonal and the values in red
highlighted in yellow are the right diagonal. The value 2 in the middle,
highlighted in purple, is in both categories. This function will calculate
the values of all the remaining numbers in the matrix. (32 for this matrix).
The function calculateVal will call functions isRightDiagonal and 
isLeftDiagonal.*/
int calculateVal(int **mat, int size)
{
    //calculate sum
    int row = 0; 
    int col = 0;
    int sum = 0;
    //nested for loop to calculate sum
    for(row = 0; row < size; row++)
    {
        for(col = 0; col < size; col++)
        {
            //if the element is not on the left or right diagonal, 
            //add it to the sum
            if (isRightDiagonal(size, row, col) == false && 
            isLeftDiagonal(row, col) == false)
                sum += mat[row][col];
        }
    }
    //return sum
    return sum;
}

/*bool isRightDiagonal(int size, int row, int col); - This function 
returns true if a given element in the defined 2D array is part of the
right diagonal. This can be written with one line of code using a ternary
operator. Whether you write this function in 1 line of code or
not, you must use a ternary operator in this function.*/
bool isRightDiagonal(int size, int row, int col)
{
    //if the element is on the right diagonal, return true
    if (row + col == size - 1)
        return true;
    else
        return false;
}

/*bool isLeftDiagonal(int row, int col); - Like the function above,
this function returns true if a given element in the defined 2D array is part
of the left diagonal. Also like the function above, it can be written with one
line of code using a ternary operator. Whether you write this function in 1
line of code or not, you must use a ternary operator in this function. */
bool isLeftDiagonal(int row, int col)
{
    //if the element is on the left diagonal, return true
    if (row == col)
        return true;
    else
        return false;
}

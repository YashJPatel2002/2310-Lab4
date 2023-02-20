/*************************
 *Yash Patel                      *
 *CPSC 2311 Sprint 23 Section 005 *
 *yjpatel                         *
 Instructor: Dr. Yvon Feaster     *
 *************************/
#include "functions.h"

int main(int argc, char** argv)
{
    //makes the autograder freak out
    //printf("cheking command line arguments\n");

    //check command line arguments
    if (argc < 2) 
    { 
        printf("not enought argument: ./exe filename\n"); 
        exit(-1);
    }

    //open file
    FILE* fp = fopen(argv[1], "r");

    //check if file opened
    if(fp==NULL)
    {
        printf("fp did not open\n"); 
        exit(-1);
    }

    //read file
    int size = 0;
    int **mat = readFile(fp, &size);

    //print matrix
    printMatrix(mat, size);
    
    //calculate sum
    printf("Total = %d \n", calculateVal(mat, size));

    //close file
    fclose(fp);


    return 0;
}
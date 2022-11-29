#include <stdio.h>
#include <math.h>
#include "my_mat.h"



int mat[SIZE][SIZE]; //Define as global 

//Make the mat
void creatMat()
{
    int temp;
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            scanf("%d", &temp);
            mat[i][j] = temp;
        }
    }
    FloydWarshallAlgorithm();
}


//Make the algorithem of FloydWarshall 
void FloydWarshallAlgorithm()
{
   int temp = 0;
    for(int k=0; k<SIZE; k++)
    {
        for(int i=0; i<SIZE; i++)
        {
            for(int j=0; j<SIZE; j++)
            {
                if(i!=j && i!=temp && j!=temp )
                {
                    if((fmin(mat[i][j], mat[i][k]+mat[k][j]))!=0)
                    {
                        mat[i][j] = fmin(mat[i][j], mat[i][k]+mat[k][j]);
                    }
                }
       temp++;
    }
    }
}
}

//Return if exist path between two verteks
int isPath(int i, int j)
{
    if(mat[i][j]!=0)
        return 1;
    return 0;
}

//Return the shortest path if exist 
int shortestpath(int i, int j)
{
    if(mat[i][j] != 0)
        return mat[i][j];
    return -1;
}

void printMat()
{
    int temp;
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
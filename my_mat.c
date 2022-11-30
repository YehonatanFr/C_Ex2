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
    for(int k=0; k<SIZE; k++)
    {
        for(int i=0; i<SIZE; i++)
        {
            for(int j=0; j<SIZE; j++)
            {
                if(i!=j && mat[i][k] != 0 && mat[k][j])
                {

                        if (mat[i][j] == 0)
                        {
                            mat[i][j] = mat[i][k] + mat[k][j];
                         }

                        else 
                        {
                            mat[i][j] = minimum(mat[i][j], mat[i][k]+mat[k][j]);
                         }
                    
                }
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

//Return the minimun between two numbers
int minimum(int num1, int num2)
{
    if(num1 == 0)
        return num2;
    if(num2 == 0)
        return num1;
    if(num1 > num2)
        return num2;
    return num1;
}


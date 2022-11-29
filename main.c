#include <stdio.h>
#include "my_mat.h"

int main()
{
char ch =' ';
while(scanf("%c",&ch) != EOF && ch !='D')
{
    if(ch == 'A')
    { 
        creatMat();
    }

    if(ch == 'B')
     {
         int i,j;
         scanf("%d%d", &i, &j);
         if(isPath(i,j) != 0)
             printf("True\n");
         else
            printf("False\n");
      }

    if(ch == 'C')
    {
         int i,j;
         scanf("%d%d", &i, &j);
         if(shortestpath(i,j) != -1)
            printf("%d" , shortestpath(i,j));
        else
            printf("-1\n");
    }
    return 0;
}
}


#include <stdio.h>
#include "my_mat.h"

int main()
{
char ch = 0;
while(scanf("%c",&ch) != EOF && ch !='D')
{
    if(ch == 'A')
    { 
        creatMat();
    }

    if(ch == 'B')
     {
         int i,j;
         if(scanf("%d%d", &i, &j) != EOF)
         {
            if(isPath(i,j) != 0)
               printf("True\n");
            else
             printf("False\n");
      }
     }

    if(ch == 'C')
    {
         int i,j;
         if(scanf("%d%d", &i, &j) != EOF)
         {
         if(shortestpath(i,j) != -1)
            printf("%d\n" , shortestpath(i,j));
         else
            printf("-1\n");
         }
    }
}
return 0;
}


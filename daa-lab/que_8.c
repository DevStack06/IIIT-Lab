#include<stdio.h>
int main()
       {
      int m[20][20],p[20],i,j,k,s,n;
      printf("enter the size of array\n");
      scanf("%d",&n);
      printf("enter the diminsion\n");
      for(i=0;i<n;i++)
         {
          scanf("%d",&p[i]);
         }
      printf("entered values\n");
         for(i=0;i<n;i++)
            {
             printf("%d \t",p[i]);
            }
      for(i=0;i<n;i++)
         {
         m[i][i] = 0;
       }
int min;
int r;
     r=2;
      printf("\noptimum values\n");
      for(s=1;s<n;s++)
         {
         i=1;
           for(j=r;j<n;j++)
              {
           min = 9999999;
              for(k=i;k<j;k++)
                 {
          m[i][j]=(m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1]);
  
		 if(m[i][j]<=min)            
	         min=m[i][j];

       m[i][j]=min;
		
       }
   printf("%d\n",m[i][j]);
    i++;		 
    }
    r++;
  }
}

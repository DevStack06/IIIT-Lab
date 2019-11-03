#include<stdio.h>
int main()
{
int w,f,c;
int i=1,j=1,k=1;
printf("Enter window size\n");
scanf("%d",&w);
printf("Enter number of frames to transmit\n");
scanf("%d",&f);
int df[f],tf[2*f];
printf("Enter %d frames\n",f);
for(i=1;i<=f;i++)
scanf("%d",&df[i]);
i=1;

while(i<=f)
{
printf("Current window is\n");
for(j=i;j<=f&&j<=i+w-1;j++)
printf("%d",df[j]);
printf("\n");

printf("AK receive-1 or not-0\n");
scanf("%d",&c);
if(c==1)
{
tf[k]=df[i];
k++;
i++;
}
else
{
for(j=i;j<=f&&j<=i+w-1;j++)
{
tf[k]=df[j];
k++;
}	
}
}

printf("Frames sequence are\n");
for(i=1;i<k;i++)
printf("%d\t",i);
printf("\n");
for(i=1;i<k;i++)
printf("%d\t",tf[i]);
printf("\n");
return 0;
}

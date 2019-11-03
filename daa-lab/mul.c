#include<stdio.h>
int main(){
	
	int m[10][10];
	int p[10];
	int i,n,j,k,t;
	
	printf("enetr how many element you ant to multiply");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		printf("enetr element you ");
	scanf("%d",&p[i]);
	
	}
	printf("eneted elements");
	for(i=1;i<=n;i++){
	 printf("%d\n",p[i]);
}
	for(i=1;i<=n;i++){
	
		m[i][i]=0;
	
	
}
int min;
int r;
	r=2;
		for(t=1;t<n;t++){                  ///run up to n cycle down
			i=1;                             ///  alway start from 1
		for(j=r;j<n;j++){
		
			min=999999;                      //// to find min among all value of k
			for(k=i;k<j;k++){
 
 		m[i][j]=(m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1]);  
				
				 
				 if(m[i][j]<=min)               //// //// to find min among all value of k
				 min=m[i][j];
				 
				 
		m[i][j]=min;
		
 
}
printf("%d\n",m[i][j]);
			i++;		 

	}
	r++;
	
	
	
}
	
	
	
	
	
}

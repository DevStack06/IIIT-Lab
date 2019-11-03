#include<iostream>
#include<math.h>
using namespace std;
char out_hex[100];
 void binary_to_hex(char b[],int n)
 {
 	int c=0;
 	for(int i=0;i<n;i=i+4)
 	{
 		int a[4];
 		for(int j=0;j<4;j++)
 		{
           int t=b[i+j];
           t=t-48;
           a[j]=t;
          // cout<<a[j];
        }
        //cout<<"\n\n";
        int k=0;
        int l=0;
        for(int j=3;j>=0;j--)
        {
        	k=k+a[j]*pow(2,l);
        	l=l+1;
        }
        if(k<=9)
        	k=k+48;
        else
        	k=k+87;
        char v=k;
        out_hex[c]=v;
        c++;
       //cout<<v<<" ";
 	}

 	/*for(int i=0;i<c;i++)
 	{
 		cout<<out_hex[i]<<"\n";
 	}*/

 }
int main()
{
	char a[100];
	for(int i=0;i<12;i++)
		cin>>a[i];
	binary_to_hex(a,12);
}

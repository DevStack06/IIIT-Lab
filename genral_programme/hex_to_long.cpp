#include<iostream>
#include<math.h>
using namespace std;
unsigned long long key;
void hex_tolong(char a[],int n)
{
	int g=0;
	unsigned long long j=0;
	char hex_text[100];
	for(int i=0;i<n;i++)
	{
		hex_text[n-1-i]=a[i];
	}

	for(int i=0;i<n;i++)
	{
		unsigned long long g=0;
		unsigned long long one=1;;
		if(hex_text[i]=='a' ||  hex_text[i]=='b' || hex_text[i]=='c' || hex_text[i]=='d' || hex_text[i]=='e' || hex_text[i]=='f')
		{
			g=hex_text[i];
			g=g-87;
			j=j+g*(one<<4*i);
		}
		else if(hex_text[i]=='A' ||  hex_text[i]=='B' || hex_text[i]=='C' || hex_text[i]=='D' || hex_text[i]=='E' || hex_text[i]=='F')
		{
			g=hex_text[i];
			g=g-55;
			j=j+g*(one<<4*i);
		}
		else
		{
			g=hex_text[i];
			g=g-'0';
			j=j+g*(one<<4*i);
		}
	}
	key=j;

	cout<<j<<"\n";

}

int main()
{
	char a[100];
	int n;
	cout<<"enter the size of hexa";
	cin>>n;
	cout<<"\n"<<"enter hexa  "<<"\n";
	for(int i = 0;i<n;i++)
	 cin>>a[i];
	hex_tolong(a,n);
}
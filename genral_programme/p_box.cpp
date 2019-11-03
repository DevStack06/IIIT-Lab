#include<iostream>

using namespace std;
int expand_p_text[48];

void p_box(int right_part[])
{
 int a[]={32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,01};
 for(int i=0;i<48;i++)
 {
   expand_p_text[i]=right_part[a[i]-1];
 }
 for(int i=0;i<48;i++)
 {
 	cout<<expand_p_text[i]<<" ";
 }
 cout<<"\n";
}

int main()
{
	int a[32];
	for(int i=0;i<32;i++)
		cin>>a[i];
	p_box(a);
}
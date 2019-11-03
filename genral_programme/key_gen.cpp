#include<iostream>
using namespace std;
int key_bit[64];
int key_bit_no[56];
int left_key[28];
int right_key[28];
int real_key[16][48];
int long_to_binary(long long key)
{
  int key_bit1[64];
  long long s=1;
  for(int i=0;i<64;i++)
  {
     
     if((key&s<<i)>0)
     {
        key_bit1[i]=1;
     }
     else
        key_bit1[i]=0;
   }
   for(int i=0;i<64;i++)
   {
     key_bit[i]=key_bit1[63-i];
    }
    
   for(int i=0;i<64;i++)
   {
     cout<<key_bit[i]<<" ";
    }
    cout<<"\n";
 }
void paraty_drop(int key_bit[64])
{
   int j=0;
   int a[]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,61,53,45,37,29,21,13,5,28,20,12,4};
  for(int i=0;i<56;i++)
  {
    key_bit_no[i]=key_bit[a[i]-1];
  }
}
    
void display(int a[],int l)
{
  for(int i=0;i<l;i++)
  {
    cout<<a[i]<<" ";
  }
  cout<<"\n\n";

}
int right_shift(int b)
{
  for(int j=0;j<b;j++)
  {
    int x=right_key[0];
    for(int i=0;i<27;i++)
    {
      
        right_key[i]=right_key[i+1];

    }
    right_key[27]=x;

  }
   
}

int left_shift1(int b)
{
  for(int j=0;j<b;j++)
  {
    int x=left_key[0];
    for(int i=0;i<27;i++)
    {
      
        left_key[i]=left_key[i+1];

    }
    left_key[27]=x;

  }
   
}

void comprat(int j)
{
  int a[]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
  int ab[58],g=0;
  for(int i=0;i<28;i++)
  {
    ab[g]=left_key[i];
    g++;
  }
  for(int i=0;i<28;i++)
  {
    ab[g]=right_key[i];
    g++;
  }

  for(int i=0;i<48;i++)
  {
    real_key[j-1][i]=ab[a[i]-1];
  }
}
     
void key_gen(long long key)
{

 int l=0,r=0;
 long_to_binary(key);
 paraty_drop(key_bit);

 for(int i=0;i<58;i++)
 {
  if(i<28)
  {
    left_key[l]=key_bit_no[i];
    l++;
  }
  else
  {
    right_key[r]=key_bit_no[i];
    r++;
  }
 }
 //display(left_key,28);
 //display(right_key,28);
 for(int i=1;i<=16;i++)
 {
  if(i==1&&i==2&&i==9&&i==16)
  {
    left_shift1(1);
    right_shift(1);
    comprat(i);
  }
  else
  {
    left_shift1(2);
    right_shift(2);
    comprat(i);
  }
  }
 /**for(int i=0;i<16;i++)
 {
  for(int j=0;j<48;j++)
  {
    cout<<real_key[i][j]<<" ";
  }
  cout<<"\n\n";
 }*/
 }

 int main()
 {
  long long key;
  cin>>key;
  key_gen(key);
 }

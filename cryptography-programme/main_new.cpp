#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <math.h>
using namespace std;
//function declaration
void printIntArray(int* ,int );
void enc();
void dec();
string roundDES(string,int);
string f(string,int *);

//conversions
string xorBitStr(string, string);
string stringToBin(string);
string intArrayToBinStr(int *, int );
int* bitStrToIntArray(string );
long long hex_tolong(string );
string binary_to_hex(string );
string HexToBin(string hexdec);
string binToHex(string );


//permutaions
string finalpermutation(int *);
string initialpermutation(int *);
string bstrswapr(string);

//key_gen
int long_to_binary(long long key);
void paraty_drop(int key_bit[64]);
void display(int a[], int l);
int right_shift(int b);
void comprat(int j);
void to_do(unsigned long long key);
int left_shift1(int b);

//sbox
int F1(int i);
int ToBits(int );
string SBox(int *);
string straightp(int *);
string pExpension(int *);
int XORtext[48];
int X[8][6];
int X2[32];
int key_bit[64];
int key_bit_no[56];
int left_key[28];
int right_key[28];
int real_key[16][48];
int intrmBtxt[64];
int roundKey[16][64];
string d="";
int main(){
	enc();
	dec();
}

void enc(){
	int blockChrSz=16,
		nuOfRounds=16;
	string pt="",enkey="",hexkey="";
	unsigned long long lngkey; 
	cout<<"enter the encryption key in hex"<<endl;
	//hexkey = "133457799bbcdff1";
	cin>>hexkey;
	lngkey = hex_tolong(hexkey);
	//key_gen(yet);
	to_do(lngkey);
	cout<<"enter string to be encrypted in hex"<<endl;
	//pt = "0123456789abcdef";
	cin>>pt;


	for(int i=pt.size()%blockChrSz;i%blockChrSz;){
		i++;
		//cout<<"hey";
		pt=pt+"0";
	}
	cout<<"padding complete after padding pt:\n\t"<<pt<<endl;

	//string d="";
	//cout<<pt.size()/blockChrSz;	
	for(int i=0;i<pt.size()/blockChrSz;i++){
		int pre=i*blockChrSz;
		int past = (i + 1) *blockChrSz;
		string s = pt.substr(pre,past);
		//d=s;
		s=HexToBin(s);
		//cout << i << "th:" << s << endl;
		//cout<<"\nhey\t"<<s.size();
		cout<<"\nbinary value of "<<i<<"th block:"<<s<<endl;
		s=initialpermutation(bitStrToIntArray(s));
		cout<<"\ninitial permutaion:"<<s<<endl;
		for(int j=0;j<nuOfRounds;j++)
		{
			s = roundDES(s,j);
			cout<<j+1<<"th round encrypted L"<<j+1<<"R"<<j+1<<":"<<s<<endl<<endl<<endl;
		}
		s=bstrswapr(s);
		s=finalpermutation(bitStrToIntArray(s));
		cout << "final permutaion:"<<s<<endl<<"encryption completed"<<endl<<"encrypted hexa:"<<binToHex(s)<<endl<<endl<<endl;
		d=binToHex(s);
	}
}
	
void dec()
	{
	int blockChrSz=16,
		nuOfRounds=16;
	for(int i=d.size()%blockChrSz;i%blockChrSz;){
		i++;
		
		d=d+"0";
	}
	cout<<"CIPHER TEXT : "<<d<<"\n";
	cout<<"\nDECRYPTION STARTS\n"<<"\n";	
	for(int i=0;i<d.size()/blockChrSz;i++)
	{		
		//string mn=d;
			int pre=i*blockChrSz;
		int past = (i + 1) *blockChrSz;
		string b = d.substr(pre,past);
		b=HexToBin(b);
		//cout << i << "th:" << s << endl;
		cout<<"\nhey\t"<<b.size();
		cout<<"\nbinary value of "<<i<<"th block:"<<b<<endl;
		b=initialpermutation(bitStrToIntArray(b));
		cout<<"\ninitial permutaion:"<<b<<endl;
		for(int j=15;j>=0;j--)
		{
			b = roundDES(b,j);
			cout<<j+1<<"th round decrypted L"<<j+1<<"R"<<j+1<<":"<<b<<endl<<endl<<endl;
		}
		b=bstrswapr(b);
		b=finalpermutation(bitStrToIntArray(b));
		
		//cout<<"\nhey\t"<<b.size()<<"\n";
		string w=binToHex(b);
		cout << "final permutaion:"<<b<<endl<<"decryption completed"<<endl<<"decrypted hexa:"<<binToHex(b)<<endl<<endl<<endl;
	}
	
}


string stringToBin(string t){
	string s;
	for(int i=0;i<t.size();i++){
		char c=t[i];
		for(int j=7;j>=0;j++)
			{
				char c1=c&1<<i?'1':'0';
				s=s+c1;
			}
	}
	cout<<s;
	return s;
}

string roundDES(string s,int i){
	string l,r,fval;
	l=s.substr(0,s.size()/2);
	r=s.substr(s.size()/2,s.size());
	
		cout << "r:" << r << endl;
		cout << "l:" << l << endl;
	cout<<"key"<<i<<":";
	for(int j=0;j<48;j++)
		cout<<real_key[i][j];
	cout<<endl;

	fval=f(r,real_key[i]);
	cout<<"f(r,K"<<i<<"):"<<fval<<endl;
	l=xorBitStr(l,fval);
	cout<<"R"<<i+1<<":"<<l<<endl;
	/*if(i==0){
		cout<<"fval"<<fval<<endl;
		cout<<"r:"<<r<<endl;
		cout << "l:" << l<< endl;
	}*/
	return  (r+l);
}


string f(string r,int *rkey){
	int rkeysize = 48;
	//cout<<"expension input"<<r<<endl;
	r=pExpension(bitStrToIntArray(r));
	cout<<"E(R):"<<r<<endl;
	//cout<<"expension out:"<<r<<endl;
	
	
	string keybstr=intArrayToBinStr(rkey,rkeysize);
	
	r=xorBitStr(r,keybstr);
	cout<<"K+E(R):"<<r<<endl;
	r=SBox(bitStrToIntArray(r));
	cout<<"Si(Bi):"<<r<<endl;
	r=straightp(bitStrToIntArray(r));
	return r;

}



int* bitStrToIntArray(string s){
	int* a=(int *)malloc(sizeof(int)*s.size());
	for(int i=0;i<s.size();i++)
		a[i]=s[i]-'0';
	return a;
}

string xorBitStr(string s1,string s2){
	if(s1.size()!=s2.size()){
		cout<<"zorBitsize error differnt length stirng passed";
		return "error";
	}
	for(int i=0;i<s2.size();i++){
		char c='0'+((s1[i]-'0')^(s2[i]-'0'));
		s1[i]=c;
	}
	//cout<<s1<<endl;
	return s1;
}

string intArrayToBinStr(int *a ,int n){
	string s="";
	for(int i=0;i<n;i++)
	{
		s=s+(a[i]==0?'0':'1');
	}
	//cout<<s;
	return s;
}

string pExpension(int right_part[])
{
	int expand_p_text[48];

	int a[] = {32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 01};
	for (int i = 0; i < 48; i++)
	{
		expand_p_text[i] = right_part[a[i] - 1];
	}
	/*for (int i = 0; i < 48; i++)
	{
		cout << expand_p_text[i] << " ";
	}
	cout << "\n";
	*/
	int exp_sz=48; 
	return intArrayToBinStr(expand_p_text,exp_sz);
}

void printIntArray(int *a,int size){
	for(int i=0;i<size;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
unsigned long long getLong4(string s){
	unsigned long long tmp=0;
	return 0;
}

int S1[4][16] =
	{
		14,
		4,
		13,
		1,
		2,
		15,
		11,
		8,
		3,
		10,
		6,
		12,
		5,
		9,
		0,
		7,
		0,
		15,
		7,
		4,
		14,
		2,
		13,
		1,
		10,
		6,
		12,
		11,
		9,
		5,
		3,
		8,
		4,
		1,
		14,
		8,
		13,
		6,
		2,
		11,
		15,
		12,
		9,
		7,
		3,
		10,
		5,
		0,
		15,
		12,
		8,
		2,
		4,
		9,
		1,
		7,
		5,
		11,
		3,
		14,
		10,
		0,
		6,
		13,
};
int S2[4][16] =
	{
		15,
		1,
		8,
		14,
		6,
		11,
		3,
		4,
		9,
		7,
		2,
		13,
		12,
		0,
		5,
		10,
		3,
		13,
		4,
		7,
		15,
		2,
		8,
		14,
		12,
		0,
		1,
		10,
		6,
		9,
		11,
		5,
		0,
		14,
		7,
		11,
		10,
		4,
		13,
		1,
		5,
		8,
		12,
		6,
		9,
		3,
		2,
		15,
		13,
		8,
		10,
		1,
		3,
		15,
		4,
		2,
		11,
		6,
		7,
		12,
		0,
		5,
		14,
		9,
};
int S3[4][16] =
	{
		10,
		0,
		9,
		14,
		6,
		3,
		15,
		5,
		1,
		13,
		12,
		7,
		11,
		4,
		2,
		8,
		13,
		7,
		0,
		9,
		3,
		4,
		6,
		10,
		2,
		8,
		5,
		14,
		12,
		11,
		15,
		1,
		13,
		6,
		4,
		9,
		8,
		15,
		3,
		0,
		11,
		1,
		2,
		12,
		5,
		10,
		14,
		7,
		1,
		10,
		13,
		0,
		6,
		9,
		8,
		7,
		4,
		15,
		14,
		3,
		11,
		5,
		2,
		12,
};
int S4[4][16] =
	{
		7,
		13,
		14,
		3,
		0,
		6,
		9,
		10,
		1,
		2,
		8,
		5,
		11,
		12,
		4,
		15,
		13,
		8,
		11,
		5,
		6,
		15,
		0,
		3,
		4,
		7,
		2,
		12,
		1,
		10,
		14,
		9,
		10,
		6,
		9,
		0,
		12,
		11,
		7,
		13,
		15,
		1,
		3,
		14,
		5,
		2,
		8,
		4,
		3,
		15,
		0,
		6,
		10,
		1,
		13,
		8,
		9,
		4,
		5,
		11,
		12,
		7,
		2,
		14,
};
int S5[4][16] =
	{
		2,
		12,
		4,
		1,
		7,
		10,
		11,
		6,
		8,
		5,
		3,
		15,
		13,
		0,
		14,
		9,
		14,
		11,
		2,
		12,
		4,
		7,
		13,
		1,
		5,
		0,
		15,
		10,
		3,
		9,
		8,
		6,
		4,
		2,
		1,
		11,
		10,
		13,
		7,
		8,
		15,
		9,
		12,
		5,
		6,
		3,
		0,
		14,
		11,
		8,
		12,
		7,
		1,
		14,
		2,
		13,
		6,
		15,
		0,
		9,
		10,
		4,
		5,
		3,
};
int S6[4][16] =
	{
		12,
		1,
		10,
		15,
		9,
		2,
		6,
		8,
		0,
		13,
		3,
		4,
		14,
		7,
		5,
		11,
		10,
		15,
		4,
		2,
		7,
		12,
		9,
		5,
		6,
		1,
		13,
		14,
		0,
		11,
		3,
		8,
		9,
		14,
		15,
		5,
		2,
		8,
		12,
		3,
		7,
		0,
		4,
		10,
		1,
		13,
		11,
		6,
		4,
		3,
		2,
		12,
		9,
		5,
		15,
		10,
		11,
		14,
		1,
		7,
		6,
		0,
		8,
		13,
};
int S7[4][16] =
	{
		4,
		11,
		2,
		14,
		15,
		0,
		8,
		13,
		3,
		12,
		9,
		7,
		5,
		10,
		6,
		1,
		13,
		0,
		11,
		7,
		4,
		9,
		1,
		10,
		14,
		3,
		5,
		12,
		2,
		15,
		8,
		6,
		1,
		4,
		11,
		13,
		12,
		3,
		7,
		14,
		10,
		15,
		6,
		8,
		0,
		5,
		9,
		2,
		6,
		11,
		13,
		8,
		1,
		4,
		10,
		7,
		9,
		5,
		0,
		15,
		14,
		2,
		3,
		12,
};

int S8[4][16] =
	{
		13,
		2,
		8,
		4,
		6,
		15,
		11,
		1,
		10,
		9,
		3,
		14,
		5,
		0,
		12,
		7,
		1,
		15,
		13,
		8,
		10,
		3,
		7,
		4,
		12,
		5,
		6,
		11,
		0,
		14,
		9,
		2,
		7,
		11,
		4,
		1,
		9,
		12,
		14,
		2,
		0,
		6,
		10,
		13,
		15,
		3,
		5,
		8,
		2,
		1,
		14,
		7,
		4,
		10,
		8,
		13,
		15,
		12,
		9,
		0,
		3,
		5,
		6,
		11,
};

int F1(int i)
{
	int r, c, b[6];
	for (int j = 0; j < 6; j++)
		b[j] = X[i][j];

	r = b[0] * 2 + b[5];
	c = 8 * b[1] + 4 * b[2] + 2 * b[3] + b[4];
	if (i == 0)
		return S1[r][c];
	else if (i == 1)
		return S2[r][c];
	else if (i == 2)
		return S3[r][c];
	else if (i == 3)
		return S4[r][c];
	else if (i == 4)
		return S5[r][c];
	else if (i == 5)
		return S6[r][c];
	else if (i == 6)
		return S7[r][c];
	else if (i == 7)
		return S8[r][c];
}

int ToBits(int value)
{
	int k, j, m;
	static int i;
	if (i % 32 == 0)
		i = 0;
	for (j = 3; j >= 0; j--)
	{
		m = 1 << j;
		k = value & m;
		if (k == 0)
			X2[3 - j + i] = '0' - 48;
		else
			X2[3 - j + i] = '1' - 48;
	}
	i = i + 4;
}
string SBox(int XORtext[])
{
	int k = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 6; j++)
			X[i][j] = XORtext[k++];

	int value;
	for (int i = 0; i < 8; i++)
	{
		value = F1(i);
		ToBits(value);
	}
	int x2size = 32;
	return intArrayToBinStr(X2, 32);
}

string finalpermutation(int pt[])
{
	int fpt[64], i;
	int fptable[] = {40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25};

	for (i = 0; i < 64; i++)
	{
		fpt[i] = pt[fptable[i] - 1];
	}

	/*cout << "the permuted bits are:";
	for (i = 0; i < 64; i++)
	{
		cout << fpt[i] - 1 << " ";
	}*/
	int fptsz=64;
	return intArrayToBinStr(fpt,64);
}


string straightp(int st[])
{
	int spt[32], i;
	int sptable[] = {16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25};

	for (i = 0; i < 32; i++)
	{
		spt[i] = st[sptable[i] - 1];
	}

	//cout << "the permuted bits are:";
	/*for (i = 0; i < 32; i++)
	{
		cout << spt[i] - 1 << " ";
	}*/
	int sptsz=32;
	return intArrayToBinStr(spt,sptsz);
 

}

string initialpermutation(int pt[])
{
	int ipt[64], i;
	int iptable[] = {58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
					 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};

	for (i = 0; i < 64; i++)
	{
		ipt[i] = pt[iptable[i] - 1];
	}

	/*cout << "the permuted bits are:";
	for (i = 0; i < 64; i++)
	{
		cout << ipt[i] - 1 << " ";
	}
	*/
	int iptsz=64;
	return (intArrayToBinStr(ipt,iptsz));
}

long long hex_tolong(string hex_text)
{
	int n = hex_text.size();
	reverse(hex_text.begin(), hex_text.end());
	unsigned long long g = 0;
	unsigned long long one = 1;
	unsigned long long j = 0;
	for (int i = 0; i < n; i++)
	{
		g = 0;
		one = 1;
		if (hex_text[i] == 'a' || hex_text[i] == 'b' || hex_text[i] == 'c' || hex_text[i] == 'd' || hex_text[i] == 'e' || hex_text[i] == 'f')
		{
			g = hex_text[i];
			g = g - 87;
			j = j + g * (one << (4 * i));
		}
		else if (hex_text[i] >= 'A' && hex_text[i] <= 'F')
		{
			g = hex_text[i];
			g = g - 'A' + 10;
			j = j + g * (one << (4 * i));
		}
		else
		{
			g = hex_text[i];
			g = g - 48;
			j = j + g * (one << (4 * i));
		}
		//cout << (g * (one << (4 * i))) << endl;
	}

	cout << "\n\nlong value" << j << "\n\n";
	return j;
}

string binary_to_hex(string b)
{
	int c = 0;
	int n = b.size();
	string out_hex;
	for (int i = 0; i < n; i = i + 4)
	{
		int a[4];
		for (int j = 0; j < 4; j++)
		{
			int t = b[i + j];
			t = t - 48;
			a[j] = t;
			// cout<<a[j];
		}
		//cout<<"\n\n";
		int k = 0;
		int l = 0;
		for (int j = 3; j >= 0; j--)
		{
			k = k + a[j] * pow(2, l);
			l = l + 1;
		}
		if (k <= 9)
			k = k + 48;
		else
			k = k + 87;
		char v = k;
		out_hex = out_hex + v;
		c++;
		//cout<<v<<" ";
	}
	//cout<<out_hex;
	return out_hex;
	/*
 	for(int i=0;i<c;i++)
 	{
 		cout<<out_hex[i]<<"\n";
 	}
*/
}

string HexToBin(string hexdec)
{

	int i = 0;
	long int j = 0;
	string binnum = "";
	int n = hexdec.size();
	//cout<<hexdec;
	for (i = 0; i < n; i++)
	{
		//cout<<binnum;
		//cout<<hexdec[i];
		switch (hexdec[i])
		{

		case '0':
			binnum = binnum + "0000";
			break;
		case '1':
			binnum = binnum + "0001";
			break;
		case '2':
			binnum = binnum + "0010";
			break;
		case '3':
			binnum = binnum + "0011";
			break;
		case '4':
			binnum = binnum + "0100";
			break;
		case '5':
			binnum = binnum + "0101";
			break;
		case '6':
			binnum = binnum + "0110";
			break;
		case '7':
			binnum = binnum + "0111";
			break;
		case '8':
			binnum = binnum + "1000";
			break;
		case '9':
			binnum = binnum + "1001";
			break;
		case 'A':
			binnum = binnum + "1010";
			break;
		case 'B':
			binnum = binnum + "1011";
			break;

		case 'C':
			binnum = binnum + "1100";
			break;
		case 'D':
			binnum = binnum + "1101";
			break;
		case 'E':
			binnum = binnum + "1110";
			break;
		case 'F':
			binnum = binnum + "1111";
			break;
		case 'a':
			binnum = binnum + "1010";
			break;
		case 'b':
			binnum = binnum + "1011";
			break;
		case 'c':
			binnum = binnum + "1100";
			break;
		case 'd':
			binnum = binnum + "1101";
			break;
		case 'e':
			binnum = binnum + "1110";
			break;
		case 'f':
			binnum = binnum + "1111";
			break;
		default:
			cout << "\nInvalid hexadecimal digit " << hexdec[i];
		}
	}
	//cout << "\n\n";
	return binnum;
}


int long_to_binary(unsigned long long key)
{
	int key_bit1[64];
	long long s = 1;
	for (int i = 0; i < 64; i++)
	{

		if ((key & s << i) > 0)
		{
			key_bit1[i] = 1;
		}
		else
			key_bit1[i] = 0;
	}
	for (int i = 0; i < 64; i++)
	{
		key_bit[i] = key_bit1[63 - i];
	}

	/* for(int i=0;i<64;i++)
   {
     cout<<key_bit[i]<<" ";
    }
    cout<<"\n";*/
}
void paraty_drop(int key_bit[64])
{
	int j = 0;
	int a[] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};
	for (int i = 0; i < 56; i++)
	{
		key_bit_no[i] = key_bit[a[i] - 1];
	}
}

void display(int a[], int l)
{
	for (int i = 0; i < l; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n\n";
}
int right_shift(int b)
{
	for (int j = 0; j < b; j++)
	{
		int x = right_key[0];
		for (int i = 0; i < 27; i++)
		{

			right_key[i] = right_key[i + 1];
		}
		right_key[27] = x;
	}
}

int left_shift1(int b)
{
	for (int j = 0; j < b; j++)
	{
		int x = left_key[0];
		for (int i = 0; i < 27; i++)
		{

			left_key[i] = left_key[i + 1];
		}
		left_key[27] = x;
	}
}

void comprat(int j)
{
	int a[] = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};
	int ab[58], g = 0;
	for (int i = 0; i < 28; i++)
	{
		ab[g] = left_key[i];
		g++;
	}
	for (int i = 0; i < 28; i++)
	{
		ab[g] = right_key[i];
		g++;
	}

	for (int i = 0; i < 48; i++)
	{
		real_key[j - 1][i] = ab[a[i] - 1];
	}
}

void to_do(unsigned long long key)
{
	int l = 0, r = 0;
	long_to_binary(key);
	paraty_drop(key_bit);

	for (int i = 0; i < 58; i++)
	{
		if (i < 28)
		{
			left_key[l] = key_bit_no[i];
			l++;
		}
		else
		{
			right_key[r] = key_bit_no[i];
			r++;
		}
	}
	//display(left_key,28);
	//display(right_key,28);
	for (int i = 1; i <= 16; i++)
	{
		if (i == 1 || i == 2 || i == 9 || i == 16)
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
	/*for(int i=0;i<16;i++)
 {
  for(int j=0;j<48;j++)
  {
    cout<<real_key[i][j]<<" ";
  }
  //cout<<"\n\n";
}*/
}

string bstrswapr(string s){
	string r,l;
	l=s.substr(0,s.size()/2);
	r = s.substr( s.size() / 2,s.size());
	return r+l;
}

string binToHex(string binstr){
	string hexstr = "";
	char c;
	while(binstr.size()%4){
		binstr="0"+binstr;
	}
	
	for(int i=0;i<binstr.size()/4;i++){
		int tmp=0;
		for(int j=3;j>=0;j--){
			if(binstr[4*i+3-j]-'0'){
				tmp+=1<<j;
			}
		}
		//cout<<tmp<<endl;
		c = tmp >= 10 ? tmp - 10 + 'a' : tmp + '0';
		hexstr = hexstr + c;
	}
	return hexstr;
}

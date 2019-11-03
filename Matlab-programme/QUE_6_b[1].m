clc
clear
close all
x=input('enter the sequence')
N=length(x) 
s=log2(N)
for m=s-1:-1:0
for p=0:1:((2^m)-1)
for k=p:(2^(m+1)):N-1
b=x(k+1)
t=(exp(-pi*1i*p/(2^m)))
x(k+1)=b+x(k+(2^m)+1)
x(k+(2^m)+1)=(b-x(k+(2^m)+1))*t
end 
end 
end 
y=bitrevorder(x)
clc;
close all;
clear all;
x1=input('Enter the first sequence :');
x2=input('Enter the second sequence: ');
l1=length(x1);
l2=length(x2);
len=max(l1,l2);
x3=cconv(x1,x2);
subplot(2,1,1);
stem(x3);
title('Circular Convolution UsingModulo Operator');
xlabel('Samples');
ylabel('Amplitude');
 
if(l2>l1)
x4=[x1,zeros(1,len-l1)];
x5=x2;
elseif(l2==l1)
        x4=x1;
        x5=x2;
else
x4=x1;
x5=[x2,zeros(1,len-l2)];
end
 
x3=zeros(1,len);
for m=0:len-1
x3(m+1)=0;
for n=0:len-1
        j=mod(m-n,len);
        x3(m+1)=x3(m+1)+x4(n+1).*x5(j+1);
end
end
subplot(2,1,2);
stem(x3);
title('Circular Convolution UsingModulo Operator');
xlabel('Samples');
ylabel('Amplitude');
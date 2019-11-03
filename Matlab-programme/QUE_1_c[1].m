clc;
clear all;
close all;
k=1;
for n=0:10
   x(k)=(0.8^n+0.8^-n)/2;
   y(k)=(0.8^n-0.8^-n)/2;
    k=k+1;
end
n=0:10;
subplot(2,1,1)
stem(n,x)
title('even');
subplot(2,1,2)
stem(n,y)
title('odd');

clc;
clear all;
close all;
f=50;
i=-0.1:0.001:0.1
x = square(2*pi*f*i,25);
y = square(2*pi*f*i,50);
z = square(2*pi*f*i,75);
subplot(3,2,1)
plot(i,x);
subplot(3,2,2)
stem(i,x);
subplot(3,2,3)
plot(i,y);
subplot(3,2,4)
stem(i,y);
subplot(3,2,5)
plot(i,z);
subplot(3,2,6)
stem(i,z);

   
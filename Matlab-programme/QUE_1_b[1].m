clc;
clear all;
close all;
k=1;
for n=0:1:32
    x(k)=cos((pi/8)*n);
    y(k)=sin((pi/8)*n);
    z=(x(k))^2+(y(k))^2;
    a(k)=sqrt(z);
    t(k)=(pi/8)*n;
    r(k)=t(k)/pi;
    k=k+1;
end
n=0:32;
subplot(3,2,1)
stem(n,x)
title('real part');
subplot(3,2,2)
stem(n,y)
title('imag part');
subplot(3,2,3)
stem(n,a)
title('abs part');
subplot(3,2,4)
stem(n,t)
title('angle part');
subplot(3,2,5)
stem(n,r)
title('redian part');
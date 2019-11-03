clear all;
close all;
clc;
xn = input('Enter the sequence n): '); 
ln = length(xn); 
xk = zeros(1, ln); 
ixk = zeros(1, ln); 

%DFT 
for k=0:ln-1 
for n=0:ln-1 
xk(k+1)=xk(k+1) + (xn(n+1)*exp((-1i)*2*pi*k*n/ln)); 
end 
end 

t = 0:ln-1; 
subplot(2,2,1) 
stem(t,xn) 
title('Input sequence') 
ylabel('Amplitude') 
xlabel('Time index'); 

magnitude = abs(xk); 
phase = unwrap(angle(xk)); 

f = (0:ln-1)*100/ln; % Frequency vector 

subplot(2,2,2) 
plot(f,magnitude) 
title('Magnitude') 
xlabel('Frequency') 
ylabel('Magnitude(DFT)'); 

subplot(2,2,3) 
plot(f,phase*180/pi) 
title('Phase') 
xlabel('Frequency') 
ylabel('Phase(DFT)'); 
xn = input('Enter the sequence same as previous one for cross checking of function): '); 
y=fft(xn);
m=abs(y);
f = (0:length(y)-1)*100/length(y);        % Frequency vector

subplot(2,2,4)
plot(f,m)
title('Magnitude by Predefine function') 
xlabel('Frequency') 
ylabel('Magnitude(DFT)');

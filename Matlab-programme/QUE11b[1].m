Fs = 7.800;                             
[z,p,k] = ellipap(6,0.23,47);           
[num,den] = zp2tf(z,p,k);             
[numd,dend] = bilinear(num,den,Fs);   
fvtool(numd,dend)       
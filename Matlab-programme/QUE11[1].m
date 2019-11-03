Wp = 1300/3900;
Ws = 1550/3900;
Rp = 0.23;
Rs = 47;
[n,Wp] = cheb1ord(Wp,Ws,Rp,Rs)
[b,a] = cheby1(n,Rp,Wp);
freqz(b,a,1024,7800) 
title('n = 4 Chebyshev Type I Lowpass Filter')
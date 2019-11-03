fsamp = 1000;
fcuts = [50 250];
mags = [1 0];
devs = [0.01 60];

[n,Wn,beta,ftype] = kaiserord(fcuts,mags,devs,fsamp);
hh = fir1(n,Wn,ftype,kaiser(n+1,beta),'noscale');

freqz(hh)

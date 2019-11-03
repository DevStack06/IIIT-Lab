f = 2000;
fs = 8000;

[b,a] = butter(4,2*pi*f,'s');
[bz,az] = impinvar(b,a,fs);

freqz(bz,az,1024,fs)

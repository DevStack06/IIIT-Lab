[z,p,k] = butter(4,2000/4000,'high');
sos = zp2sos(z,p,k);
fvtool(sos,'Analysis','freq')
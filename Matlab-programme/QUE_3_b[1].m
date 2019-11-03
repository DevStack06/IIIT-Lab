t1=input('enter lower range');
t2=input('enter upper range');
t=t1:t2;
x=[1 2 1 2];
y=[2 1 2];
h=conv(x,y);
stem(h);

clc;
clear all;
close all;
wvtool(rectwin(24));% less samples => more ripples
wvtool(rectwin(1023));% more samples => less ripples
wvtool(hamming(24));% less samples => more ripples
wvtool(hamming(1023));% more samples => less ripples
wvtool(hanning(24));% less samples => more ripples
wvtool(hanning(1023));% more samples => less ripples

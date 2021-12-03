clear;
time=[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24];
T=[15,14,14,14,14,15,16,18,20,22,23,25,28,31,32,31,29,27,25,24,22,20,18,17,16];
F1=@(c,x)c(1)*x^2+c(2)*x+c(3);  %Quadratic function
F3=@(c,x)c(1)*exp(c(2)*(x-14)^2);
[c,Q]=lsqcurvefit(F3,[0,0],time,T)


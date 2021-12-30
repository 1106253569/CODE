clear;
dfun=@Qes6_3fun;  
[x,y]=ode45(dfun,[0,50],[1;-1]);
length(x)
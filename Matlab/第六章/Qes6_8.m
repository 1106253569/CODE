fun=@(t,x)0.5*(1-x)*x;
[t,x]=ode45(fun,[0 10],0.05);
plot(t,x)
id=find(x>0.8, 1 );
t(id)
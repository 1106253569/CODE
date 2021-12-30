clear;close;
fun=@(t,x,a,b)a*x+b;
[t,x]=ode45(fun,[0 10],0.1,[],1,1);
subplot(2,4,1);plot(t,x)
[t,x]=ode45(fun,[0 10],-0.1,[],1,1);
subplot(2,4,2);plot(t,x)
[t,x]=ode45(fun,[0 10],0.1,[],1,-1);
subplot(2,4,3);plot(t,x)
[t,x]=ode45(fun,[0 10],-0.1,[],1,-1);
subplot(2,4,4);plot(t,x)
[t,x]=ode45(fun,[0 10],0.1,[],-1,1);
subplot(2,4,5);plot(t,x)
[t,x]=ode45(fun,[0 10],-0.1,[],-1,1);
subplot(2,4,6);plot(t,x)
[t,x]=ode45(fun,[0 10],0.1,[],-1,-1);
subplot(2,4,7);plot(t,x)
[t,x]=ode45(fun,[0 10],-0.1,[],-1,-1);
subplot(2,4,8);plot(t,x)
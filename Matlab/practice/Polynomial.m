a=[1 -1 -1];
b=roots(sym(a));
pretty(b)
syms f g x;

f=3*x^2+2*x+2;

g=3*x+1;

ans1=f+g;

ans2=f-g;

ans3=f*g;

ans4=f/g;

disp(ans1);disp(ans2);

disp(ans3),disp(ans4)
ezplot(f,[-5:2]);
hold on;
grid on;
ezplot(g,[-5:2]);
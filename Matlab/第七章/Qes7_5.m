syms k n x;s1=symsum(k^2,k,1,n);
s1=simple(s1);
s2=symsum(k^(-2),k,1,inf);
s2=simple(s2);
s3=symsum(1/(2*n+1)/(2*x+1)^(2*n+1),n,0,inf);s3=simple(s3) Page—143 Exercise 6
syms x y z;s=sin(x^2*y*z);
s=diff(s,x,2);
s=diff(s,y,1);
s=subs(s,{x,y,z},{1,1,3})
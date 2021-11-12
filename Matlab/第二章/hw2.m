clear;
sum=0;
n=0;
while sum<100
    sum=sum+log(1+n);
    n=n+1;
end
disp(["m must be >= ",n])
    
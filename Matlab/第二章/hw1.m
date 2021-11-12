clear;
x=[81,70,65,51,76,66,90,87,61,77];
n=length(x);
all=0;
avarage=sum(x)/n
for i=1:n
    all=all+x(i)^2;
end
s=sqrt((all-n*avarage^2)/(n-1))
    
    



%牛顿迭代法
a=input('a=');
if a<0
    warning("a must >0");
end
x = a/2; 
while true
     x1 = (x+a/x)/2;
     %前后两次结果之差处于精度范围内则输出
     if abs(x-x1)<1e-5
        break;
     end
     %最后输出的是x1的值
     x = x1;  
end
disp(x);
x=@(t) exp(-t/10).*sin(5*t);
y=@(t) exp(-t/10).*cos(5*t);
z=@(t) t;
fplot3(x,y,z,[-12,12]);
grid on;
title('墨西哥帽顶曲线');
xlabel('x=e^{-t/10}sin(5t)');
ylabel('y=e^{-t/10}cos(5t)');
zlabel('z=t');
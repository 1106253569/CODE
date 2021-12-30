x=1:1:100;
p=binopdf(x,100,0.5);
plot(x,p);
title('二项分布')
hold on;
x=0:1:20;
p=poisspdf(x,6);%单位时间内平均发生6次，求发生x次的泊松概率
plot(x,p)
title('泊松分布')
ylabel('$p=\frac{5^{x}}{x!}e^{-5}$','Interpreter','latex','FontSize',15)

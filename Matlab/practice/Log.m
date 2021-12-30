x=0:0.5:5;
y = exp(x);
figure
subplot(4, 1, 1) 
plot(x, y, 'r-.') 
title('笛卡尔坐标系')
subplot(4, 1, 2) 
semilogx(x, y, 'g:') 
title('x轴为对数坐标系') 
subplot(4, 1, 3) 
semilogy(x, y, 'b-') 
title('y轴为对数坐标系') 
subplot(4, 1, 4) 
loglog(x, y, 'k:','LineWidth',4) 
title('对数坐标系')

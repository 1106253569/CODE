clear;
fun1=@(x)1.6*x+1;
fun2=@(x)2.6-1.6*x;
x=[0,0.5,1,0];
y=[fun1(0),fun1(0.5),fun2(1),fun1(0)];

theta=pi/2;
T=[cos(theta),-sin(theta);sin(theta),cos(theta)];

title("202011010002 谢霖辉");
grid on;
hold on;

plot(x,y,'linewidth',5,'color','blue');
plot(2*x,0.5*y,'color','magenta');
plot(0.5*x,2*y,'color','green');
plot(x+1,y+1,'color','cyan');
xy=[x;y];
xy=T*xy;
plot(xy(1,:),xy(2,:),'linewidth',5,'color','blue');

x=[0.075,0.925,0.925,0.075,0.075];
y=[1,1,0,0,1];
plot(x,y,'linewidth',5,'color','blue');
plot(2*x,0.5*y,'color','magenta');
plot(0.5*x,2*y,'color','green');
plot(x+1,y+1,'color','cyan');
xy=[x;y];
xy=T*xy;
plot(xy(1,:),xy(2,:),'linewidth',5,'color','blue');

x=[0.4,0.4,0.6,0.6];
y=[0,0.5,0.5,0];
plot(x,y,'linewidth',5,'color','blue');
plot(2*x,0.5*y,'color','magenta');
plot(0.5*x,2*y,'color','green');
plot(x+1,y+1,'color','cyan');
xy=[x;y];
xy=T*xy;
plot(xy(1,:),xy(2,:),'linewidth',5,'color','blue');

x=[0.15,0.15,0.25,0.25];
y=[fun1(0.15),1.7,1.7,fun1(0.25)];
plot(x,y,'linewidth',5,'color','blue');
plot(2*x,0.5*y,'color','magenta');
plot(0.5*x,2*y,'color','green');
plot(x+1,y+1,'color','cyan');
xy=[x;y];
xy=T*xy;
plot(xy(1,:),xy(2,:),'linewidth',5,'color','blue');

x=[0.7,0.8,0.8,0.7,0.7];
y=[0.8,0.8,0.6,0.6,0.8];
plot(x,y,'linewidth',5,'color','green');
plot(2*x,0.5*y,'color','magenta');
plot(0.5*x,2*y,'color','green');
plot(x+1,y+1,'color','cyan');
xy=[x;y];
xy=T*xy;
plot(xy(1,:),xy(2,:),'linewidth',5,'color','blue');

x=x-0.5;
plot(x,y,'linewidth',5,'color','green');
plot(2*x,0.5*y,'color','magenta');
plot(0.5*x,2*y,'color','green');
plot(x+1,y+1,'color','cyan');
xy=[x;y];
xy=T*xy;
plot(xy(1,:),xy(2,:),'linewidth',5,'color','blue');

plot([0.2,0.3],[0.7,0.7],'linewidth',2.5,'color','green');
plot([0.7,0.8],[0.7,0.7],'linewidth',2.5,'color','green');
plot([0.25,0.25],[0.8,0.6],'linewidth',2.5,'color','green');
plot([0.75,0.75],[0.8,0.6],'linewidth',2.5,'color','green');

plot(0.55,0.2,'o','linewidth',2,'color','black');
close all, clc

%(a)
x = [0, pi/2, pi/6];
y = cos(x);

figure;
plot(x,y,'.','MarkerSize',20)

P2 = @(x) 1 - 0.6366*x - 0.3636*x.*(x-1.5708);

hold on
fplot(P2,[0,pi/2],'LineWidth',2)
fplot(@(x) cos(x),[0,pi/2],'LineWidth',2)
legend('Data points','P2(x)','f(x) = cos(x)','Fontsize',14)

%(b)
P2(pi/3)

%(c)
x = [0, pi/2, pi/6, pi/4];
y = cos(x);

figure;
plot(x,y,'.','MarkerSize',20)

P3 = @(x) P2(x) + 0.1063*x.*(x-1.5708).*(x-0.5236);

hold on
fplot(P3,[0,pi/2],'LineWidth',2)
fplot(@(x) cos(x),[0,pi/2],'LineWidth',2)
legend('Data points','P3(x)','f(x) = cos(x)','Fontsize',14)

P3(pi/3)
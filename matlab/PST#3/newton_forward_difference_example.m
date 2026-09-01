close all, clear all, clc

% (a)
x = [0, 0.5, 1];
y = [1, 1.6487, 2.7183];

figure;
plot(x,y,'.','MarkerSize',20)

s = @(x) 2*x;
P2 = @(x) 1 + 0.6487*s(x) + 0.21045*s(x).*(s(x)-1);
disp("peepee");
disp(P2(x))

hold on
fplot(P2,[0,1],'LineWidth',2)
legend('Data points','P2(x)','Fontsize',14)

% (b)
P2(1/3)

% (c)
x = [0, 0.5, 1, 1.5, 2];
y = [1, 1.6487, 2.7183, 4.4817, 7.3891];

figure;
plot(x,y,'.','MarkerSize',20)

s = @(x) 2*x;
P4 = @(x) P2(x) + 0.0455*s(x).*(s(x)-1).*(s(x)-2) + ...
    0.0074*s(x).*(s(x)-1).*(s(x)-2).*(s(x)-3);

disp("peepee");
disp(P4(x));

hold on
fplot(P4,[0,2],'LineWidth',2)
legend('Data points','P4(x)','Fontsize',14)

P4(1/3)
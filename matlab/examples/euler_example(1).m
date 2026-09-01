clc, close all, clear all

a = 1; % start time
b = 2; % end time
alpha = 2; % initial value y(1) = 2
n = 50; % number of subintervals
h = (b-a)/n; % stepsize
f = @(t,y) 3*t - y/t; % f(t,y)

t = a:h:b; % time array
w = zeros(size(t)); % solution array
w(1) = alpha; % initial value

% Euler's method
for j = 1:n
    w(j+1) = w(j) + h*f(t(j),w(j));
end

figure;
plot(t,w,'.-','MarkerSize',20,'LineWidth',2)
hold on
we = @(t) t.^2 + 1./t; % Exact solution
fplot(we,[a,b],'LineWidth',2)
xlabel('t','FontSize',14);
ylabel('y(t)','FontSize',14);
legend('Euler method','Exact solution','FontSize',14,'Location','SouthEast');
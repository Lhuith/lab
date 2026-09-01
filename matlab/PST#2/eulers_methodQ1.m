clc, close all, clear all

a = 0; % start time
b = 50; % end time
alpha = 100; % initial value y(1) = 2
n = 100; % number of subintervals
h = (b-a)/n; % stepsize
f = @(t,y) y * 0.1; % f(t,y)

t = a:h:b; % time array
w = zeros(size(t)); % solution array
w(1) = alpha; % initial value

% Euler's method
for j = 1:n
    w(j+1) = w(j) + h*f(t(j),w(j));
end

population = w(end); % store approximation of y at t = 50
figure;
plot(t,w,'.-','MarkerSize',20,'LineWidth',2)
hold on
we = @(t) t.^2 + 1./t; % Exact solution
fplot(we,[a,b],'LineWidth',2)
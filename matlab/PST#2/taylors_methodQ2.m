% Define parameters
%function definition?
n = 100;
alpha = 100;
a = 0;
b = 50;
r = 0.1;
K = 1000;
f = @(t,y) r*y*(1 - (y/K));
fdash = @(t,y) r^2 *y*(1 - 3*y/K + 2*y^2/K^2);

h = (b-a)/n;
t = a:h:b;
w = zeros(size(t));
w(1) = alpha;

for j = 1:n
    w(j+1) = w(j) + h*f(t(j),w(j)) + h^2/2*fdash(t(j),w(j));
end

population = w(end); % store approximation of y at t = 50
figure;
plot(t,w,'.-','MarkerSize',20,'LineWidth',2)

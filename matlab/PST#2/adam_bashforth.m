function [t, w, h] = adam_bashforth(f, a, b, alpha, n)
%AB2 Two-step Adams Bashforth method
% [t, w, h] = ab2(f, a, b, alpha, n) performs the two-step Adams Bashforth 
% method for solving the IVP y' = f(t,y) with initial condition y(a) = alpha
% taking n steps from t = a to t = b. The first step from t = a to t = a + h
% is performed using the modified Euler method.
h = (b-a)/n;
t = a:h:b;
w = zeros(size(t));

w(1) = alpha;

k1 = h*f(t(1), w(1));
k2 = h*f(t(1) + h, w(1) + k1);
w(2) = w(1) + 1/2 * (k1+k2);

for j = 2:n
    step0 = 3/2 *(h * f(t(j), w(j)));
    step1 = 1/2 *(h * f(t(j - 1), w(j - 1)));
    w(j+1) =  w(j)+ step0 - step1;
end

figure;
plot(t,w,'.-','MarkerSize',20,'LineWidth',2)
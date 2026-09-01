function [t, w, h] = rk4(f, a, b, alpha, n)
%RK4 Fourth Order Runge-Kutta method
% [t, w, h] = rk4(f, a, b, alpha, n) performs the fourth order Runge-Kutta
% method for solving the IVP y' = f(t,y) with initial condition y(a) = alpha
% taking n steps from t = a to t = b.
h = (b-a)/n;
t = a:h:b;
w = zeros(size(t));
w(1) = alpha;

for j = 1:n
    k1 = f(t(j), w(j));
    k2 = f(t(j)+0.5*h,w(j)+0.5*h*k1);
    k3 = f((t(j)+0.5*h),(w(j)+0.5*h*k2));
    k4 = f((t(j)+h),(w(j)+k3*h));
    w(j+1) =  w(j) + (1/6)*(k1+2*k2+2*k3+k4)*h;
end

figure;
plot(t,w,'.-','MarkerSize',20,'LineWidth',2)
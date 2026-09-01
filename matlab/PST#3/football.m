x0 = 6;

tol = 10E-14;

c = 0.14;
m = 0.4;
v = 48;
theta = pi/4;
g = 9.81;

f = @(t) 1 + (m/c)*(v * sin(theta) + ((m*g)/c)) * (1 - exp(-((c*t)/m))) - (((m*g)/c)*t);

fdash = @(t) ((v*cos(theta) + g) * 1 - exp((-(c*t)/m)) - ((c*t * exp((-(c*t)/m)))/m) - g*t)/c;

i = 0;
x = x0;
x_old = inf;

while abs(x - x_old) > tol
    x_old = x;
    x = x_old - f(x_old)/fdash(x_old);
    i = i + 1;
end

figure;
fplot(f, [0, 10]);
hold on;
plot(x,'.','MarkerSize',20)
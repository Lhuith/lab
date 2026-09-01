function [x, i] = secant(f, x0, x1, tol, maxiters)

if ~isa(f, 'function_handle')
    error('f isnt a function!')
end

i = 0;

x_older = inf;
x_old = x0;
x = x1;

%x0 = old x
%x = new x
%newtwon = x_old - f(x_old)/fdash(x_old);

while abs(x - x_old) >= tol && i < maxiters
    x_older = x_old;
    x_old = x;
    x = x_old - f(x_old)*(x_old-x_older)/(f(x_old)-f(x_older));  %x2
    i = i + 1;
end

if abs(x - x_old) >= tol
    warning('Max number of iterations reached without achieving tolerance')
end
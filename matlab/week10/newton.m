function [x, i] = newton(f, fdash, x0, tol, maxiters)

if ~isa(f, 'function_handle')
    error('f isnt a function!')
end

if ~isa(fdash, 'function_handle')
    error('fdash isnt a function!')
end

i = 0;

x = x0;
x_old = inf;

while abs(x - x_old) > tol && i < maxiters
    x_old = x;
    x = x_old - f(x_old)/fdash(x_old);
    i = i + 1;
end

if abs(x - x_old) > tol
    warning('Max number of iterations reached without achieving tolerance')
end
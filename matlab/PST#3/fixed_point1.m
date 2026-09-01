function [x, i] = fixed_point1(g, x0, tol, maxiters)

if ~isa(g, 'function_handle')
    error('g isnt a function!')
end

i = 0;
x = x0;
x_old = inf;

while abs(x - x_old) > tol && i < maxiters
    x_old = x;
    x = g(x);
    i = i + 1;
    disp(x_old);
end

if abs(x - x_old) > tol
    warning('Max number of iterations reached without achieving tolerance')
end
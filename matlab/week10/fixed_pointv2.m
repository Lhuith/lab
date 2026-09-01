function [x, i] = fixed_pointv2(g, x0, tol)

if ~isa(g, 'function_handle')
    error('g isnt a function!')
end

i = 0;
x = x0;
x_old = inf;

while abs(x - x_old) > tol
    x_old = x;
    x = g(x);
    i = i + 1;
end
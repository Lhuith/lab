function x = fixed_point(g, x0, n)

if ~isa(g, 'function_handle')
    error('g isnt a function!')
end

x = x0;

for i = 1:n
    x = g(x);
end

end
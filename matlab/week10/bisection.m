function p = bisection(f, a, b, n)

if ~isa(f, 'function_handle')
    error('f isnt a function!')
end

if(sign(f(a)) == sign(f(b)))
    error('f(a) and f(b) must be opposite signs!')
end

for i = 1:n
    p  = (a + b)/2;
    if (sign(f(a)) == sign(f(p)))
        a = p;
    else
        b = p;
    end
end

end
function approx = approx_root2(n)
% approx = approx_root2(n) returns an approximation to sqrt(2) obtained by
% applying n iterations of the bisection method to x^2 - 2 = 0 using the
% initial bracketing [1,4].

a = 1;
b = 4;

f = @(x) (x^2) - 2;

for i = 1:n
    approx  = (a + b)/2;
    if (sign(f(a)) == sign(f(approx)))
        a = approx;
    else
        b = approx;
    end
end

end
function [t, w, h] = eulers_method(f, a, b, alpha, n)
    h = (b-a)/n;
    t = a:h:b;
    w = zeros(size(t));
    w(1) = alpha;
    
    for j = 1:n
        w(j+1) = w(j) + h * f(t(j), w(j));
    end
end
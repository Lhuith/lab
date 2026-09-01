function x = fixed_point(n)
    g = @(x) exp(-x);

    x = 0.6;
    
    for i = 1:n
        x = g(x);
    end
end

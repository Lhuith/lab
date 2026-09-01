function x = turning_points(a)
    df = polyder(flip(a));
    x = roots(df);
end

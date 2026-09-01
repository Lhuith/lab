function y = piecewise(x)
% y = piecewise(x) returns the value of f(x) for the input x.
    if x < 0
        y = (-x^3) - (2*(x^2)) + (3*x);
    else if x <= 0 && x <= 8 
        y = (12/pi)*sin((pi*x)/4) + 0.5;
    else 
        y = (600 * (e^(x-8))) / 7 * (14 + 6 * (e ^(x-8))) - (30/7);
    end
end
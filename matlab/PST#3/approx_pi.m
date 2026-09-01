function N = approx_pi(tol)
    N = 0;
    sum = 0;
    sum_old = inf;
    k = 1;

    while abs(sum - sum_old) > tol
        N = k;
        sum_old = sum;
        sum = (sum + (((-3)^(1 - k)) / ((2*k) - 1)));
        k = k + 1; 
    end
    sum = sqrt(12) * sum;
    
end
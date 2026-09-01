function Pn = taylor_cos(a,n)
sum = 0;
    for k = 0:1:n
        k_2 = 2*k;
        term = ((-1)^k) * (a^(k_2))/factorial(k_2);
        sum = sum + term;
    end    
Pn =  sum;
end
function xtilde = approx_root2(N)
sum = 0;
    for k = 0:N
        sum = sum + (factorial(2*k + 1))/(2^(3*k+1)*(factorial(k)^2));
    end
xtilde = sum;
disp("value: " + xtilde)
disp("actual: " + sqrt(2))
end
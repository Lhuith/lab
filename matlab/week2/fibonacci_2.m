function F_n = fibonacci_2(n)

a = (1 + sqrt(5))/2;
b = (1 - sqrt(5))/2;

F_n = ((a^n) - (b^n)) / sqrt(5);

end
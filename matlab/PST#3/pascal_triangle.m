function T = pascal_triangle(n)
% T = pascal_triangle(n) returns the first n rows of Pascal's triangle.
T = zeros(n,n);

T(1,1) = 1;

if n == 1
    return
end

T(2, 1 : 2) = [1,1];

if n < 3
    return
end

for r = 3 : n
    T(r, 1) = 1;
    
    for c = 2 : r - 1
        T(r, c) = T(r - 1, c - 1) + T(r - 1, c);
    end
    
    T(r,r) = 1;
end

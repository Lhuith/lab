function T = forward_differences(Y)
% T = forward_differences(Y) returns Newton's forward difference table
% for the function values Y = [y0,y1,...,yn].
% Note that the forward difference table T is stored as:
% y0
% y1  Delta y0
% y2  Delta y1  Delta^2 y0
% y3  Delta y2  Delta^2 y1  Delta^3 y0
% etc.
% The rest of the array T is zero.
%Construct empty divided difference table
n = length(Y);
T = zeros(n, n);
%Fill first column
T(:,1) = Y;
%Fill remaining columns (REPLACE ? WITH CORRECT EXPRESSIONS)
for j = 2:n % j is the column index
    for i = j:n % i is the row index
        T(i,j) = (T(i,j-1) - T(i-1,j-1));
    end
end
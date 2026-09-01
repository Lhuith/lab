function y = forward_eval(X, T, x)
% Evaluate Newton's forward difference form of the interpolating polynomial.
% y = forward_eval(X, T, x) returns y = P(x), where P is the interpolating 
% polynomial constructed using the abscissas X = [x0,x1,...,xn] and forward
% difference table T.
% Evaluate Newton's forward difference form of the interpolating polynomial.
% y = forward_eval(X, T, x) returns y = P(x), where P is the interpolating 
% polynomial constructed using the abscissas X = [x0,x1,...,xn] and forward
% difference table T.

[m,n] = size(T);
if m ~= n
    error('T must be square.');
end

x0 = x(1);
s = @(x, k) (x - x0) ./ (X(k+1) - X(k));

y = zeros(size(x)); % initialise sum
for k = 1:n % loop over sum index
   S = ones(size(x)); % initialise product
   
   factor = factorial(k-1);
   
   for i = 0:k-2 % loop over product index
        S = S .* (s(x, i+1) - i); % multiply next factor        
   end
   
    y = y + ((T(k, k) * (S))/factor); % add next term
end

figure;
plot(x,y,'.','MarkerSize',20)
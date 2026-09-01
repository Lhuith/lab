function [a,b,c, bool] = pythag_triple(n)
%something something something
a = (2*n) + 1;
b = (2*n)*(n + 1);
c = ((2*n)*(n + 1)) + 1;

bool = a^2 + b^2 == c^2;
end
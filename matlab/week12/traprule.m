function I = traprule(f, a, b, n)
%TRAPRULE Trapezoidal rule integration.
% I = TRAPRULE(F, A, B, N) returns the trapezoidal rule approximation for
% the integral of f(x) from x=A to x=B, using N subintervals,
% where F is a function handle.
if ~isa(f, 'function_handle')
error('Your first argument was not a function handle')
end
h = (b-a) / n;
x = a:h:b; % an array of length n+1
S = 0;
for j = 2:n
    S = S + (f(x(j)));
    disp(S);
end
I = h/2 * (f(x(1)) + (2.*S) + f(x(n+1)));
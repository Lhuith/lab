function fdash = first_order_backward(f, x0, h)
%FIRST_ORDER_FORWARD First order forward difference approximation to f'.
% FDASH = FIRST_ORDER_FORWARD(F, X0, H) returns (f(X0+H) - f(X0)) / H
% where F is a function handle.
if ~isa(f, 'function_handle')
error('Your first argument was not a function handle')
end
fdash = (f(x0) - f(x0-h)) ./ h;
end
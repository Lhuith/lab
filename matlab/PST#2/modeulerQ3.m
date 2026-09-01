% Define parameters
%function definition?
n = 2400;
alpha = 80;
a = 0;
b = 40;

A = 15;
k = 0.1;

f = @(t,C) -k*(C - A);

h = (b-a)/n;
t = a:h:b;
w = zeros(size(t));
w(1) = alpha;

undrinkable_index = 0;

for j = 1:n
   k1 = h*f(t(j), w(j));
   k2 = h*f(t(j), w(j) + k1);
   w(j+1) = w(j) + 1/2 * (k1+k2); 
end

for i = 1:n 
    if(w(i) < 40) 
        undrinkable = i;
        break
    end
end

temperature = w(end); % store approximation of y at t = 50

figure;
plot(t,w,'.-','MarkerSize',20,'LineWidth',2)
hold on
we = @(t) K /(1 + 100 *(exp(-r.*t))); % Exact solution
fplot(we,[a,b],'LineWidth',2)
x = linspace(0.34,0.96,100);
X = [0.34,0.5,0.96];
Y = [0.26,0.22,0.75];

n = length(X);

if n ~= length(Y)
    error('X and Y must have the same length.');
end

y = zeros(size(x)); % initialise sum
for i = 1:n % loop over sum index
    L = ones(size(x)); % initialise product
    for j = [1:i-1 i+1:n] % loop over product index
        L = L.*((x - X(j))./(X(i) - X(j)));
    end
y = y+L*Y(i);
end

% Evaluate Lagrange form of interpolating polynomial at array x.
P = y;

% Plot interpolating polynomial and data points
figure;
plot(x,P,'b','LineWidth',2)
hold on
plot([0.34,0.5,0.96],[0.26,0.22,0.75],'r.','MarkerSize',24)
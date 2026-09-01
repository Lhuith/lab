x = [0, 0.0526, 0.1053, 0.1579, 0.2105, 0.2632, 0.3158, 0.3684, 0.4211, 0.4737, 0.5263, 0.5789, 0.6316, 0.6842, 0.7368, 0.7895, 0.8421, 0.8947, 0.9474, 1.0000]; % Store x coordinates in an array
y = [1.2335, 1.2749, 1.4000, 1.5016, 1.5191, 1.6902, 1.6744, 1.9134, 1.8501, 2.0166, 2.0642, 2.1822, 2.4690, 2.5421, 2.5530, 2.8165, 2.6928, 2.8992, 2.9901, 3.1914]; % Store y coordinates in an array

n = 20;
A = zeros(2,2); b = zeros(2,1);

% Insert code here to populate entries of A and b
A(1,1) = n;

for i = 1:n 
    A(1, 2) = A(1, 2) + x(i);
    A(2, 1) = A(2, 1) + x(i);
    A(2, 2) = A(2, 2) + (x(i)^2);
    
    b(1,1) =  b(1,1) + y(i);
    b(2,1) =  b(2,1) + (x(i) * y(i));
end


% Solve matrix equation
c = A\b;
alpha = c(1);
beta = c(2);

% Plot line of best fit and data points
figure;
plot(x,y,'r.','MarkerSize',24)
hold on
fplot(@(x) alpha + beta*x,[min(x),max(x)],'b','LineWidth',2)
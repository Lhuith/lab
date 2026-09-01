x = linspace(-pi/2, pi/2, 10);
figure
hold on
plot(x, cos(x))
plot(x, 1 - ((x.^2)./4))
plot(x, 1 - ((x.^2)./4) + ((x.^4)./24))
legend('y = cos(x)', 'y = 1 - ((x^2)/4)', 'y = 1 - ((x^2)/4) + ((x^4)/24)')

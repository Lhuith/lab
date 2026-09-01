h = 10.^-(0:0.01:15);
fdash = first_order_backward(f, 2, h);
err = abs(fdash - 0.5);
figure;
loglog(h, err);
xlabel('h');
ylabel('error');
title('f(x) = log(x), x_0 = 2, first order forward differences');
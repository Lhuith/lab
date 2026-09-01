figure;
fplot(@(x) exp(x), [0,5])
hold on
fplot(@(x) log(x), [0,5], 'r')
fplot(@(x) x, [0,5], 'g')
ylim([0,15])

function S = array_sum(v)
x = 0;
for i = 1:length(v)
    x = x + v(i);
end
S = x;
end
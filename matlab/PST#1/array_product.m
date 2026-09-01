function P = array_product(v)
 val = 1;
    for i = 1:length(v)
        val = val * v(i);
    end    
    P = val;
end
function heads,tails = flipsumcoins()
    heads = 0;
    tails = 0;
    
    for i = 0:1000
        flip = coinflip;

        if strcmp(flip, "heads")
            heads = heads + 1;
        else 
            tails = tails + 1;
        end

    end
            
end
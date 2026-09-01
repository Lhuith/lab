function steps = collatz(n,max_steps)
% COLLATZ Applies the collatz algorithm for a given starting value.
% steps = collatz(n,max_steps) performs the collatz algorithm starting with
% a positive integer n returning the number of steps required to reach a value
% of 1. If the number of steps reaches the value of max_steps (without the algorithm 
% reaching 1) then NaN is returned.
steps = 0;
val = n;
for i = 0:max_steps   
    if (val == 1) 
        break
    end
    
    if (mod(val, 2) == 0)
        val = val/2;
    else
        val = (val*3) + 1;
    end
    disp(val)
    steps = steps + 1;
end

if steps > max_steps
    steps = 0/0;
end

end
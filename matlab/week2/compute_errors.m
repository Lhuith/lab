function [abserr,relerr] = compute_errors(x, xtilde)
%compute some shit yo!
abserr = abs(x - xtilde);
relerr = abserr / abs(x);
end

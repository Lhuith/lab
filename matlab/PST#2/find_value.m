function indx = find_value(a,v)
% find_value Find all occurrences of a value in an array.
% indx = find_value(a, v) returns an array/vector containing the indices 
% of each occurrence of the value v in the array a. If v is not in a, the empty 
% array/vector is returned.
   
indx = [];
for i = 1 : length(a)
        if (a(i) == v)
            indx = [indx,i];
        end
    end
end
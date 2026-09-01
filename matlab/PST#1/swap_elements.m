 function [a,b] = swap_elements(a,b)
 % [a,b] = swap_elements(a,b) interchanges the second and fifth elements of a and b.
 tmp2 = a(2); 
 a(2) = b(2);
 b(2) = tmp2;
 
 tmp5 = a(5); 
 a(5) = b(5);
 b(5) = tmp5;
 end
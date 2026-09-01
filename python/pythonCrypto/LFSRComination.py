import math

def gcd(p,q):
# Create the gcd of two positive integers.
    while q != 0:
        p, q = q, p%q
    return p

def is_coprime(x, y):
    return gcd(x, y) == 1

def lcm(x, y):
   # choose the greater number
   if x > y:
       greater = x
   else:
       greater = y

   while(True):
       if((greater % x == 0) and (greater % y == 0)):
           lcm = greater
           break
       greater += 1

   return lcm

print((2**21 - 1)*(2**21 - 1))
print((2**7 - 1)*(2**35 - 1))
print((2**17 - 1)*(2**25 - 1))

print(is_coprime(17, 25))
print(is_coprime(21, 21))
print(is_coprime(7, 35))
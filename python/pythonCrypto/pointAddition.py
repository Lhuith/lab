def modinv2(a, p):
   return pow(a, -1, p)

def s(y, y1, x, x1, p):
   return ((y - y1) * modinv2((x - x1), p)) % p

def s2(y, x, a, p):
   return ((3 * (x**2)) + a) * modinv2((2*y), p) % p

def x_r(sr, x, x1, p):
   return ((sr ** 2) - x - x1) % p

def y_r(s, y, x, x2, p):
   return ((s * (x - x2)) - y) % p

def x_r2(sr, x, x1, p):
   return ((sr ** 2) - x - x1) % p

def y_r2(s, y, x, x2, p):
   return ((s * (x - x2)) - y) % p

def pointAddtion(x, y, x1, y1, p):
   sr = s(y, y1, x, x1, p)
   x2 = x_r(sr, x, x1, p)
   y2 = y_r(sr, y, x, x2, p)
   return x2, y2

def pointMultiplication(x, y, x1,y1, a, p):
   sr = s2(y, x, a, p)
   x2 = x_r(sr, x, x1, p)
   y2 = y_r(sr, y, x, x2, p)
   return x2, y2

print(pointAddtion(0, 3, 3, 5, 13))
print(pointAddtion(0, 3, 2, 1, 13))
print(pointAddtion(0, 3, 3, 8, 13))

print(pointMultiplication(0, 3, 3, 5, 5, 13))

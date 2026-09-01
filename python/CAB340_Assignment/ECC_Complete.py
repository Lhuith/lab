def modinv2(a, p):
      return pow(a, -1, p)
# Point Addition S
def sAdd(y_p, y_q, x_p, x_q, p):
   return ((y_q - y_p) *
           modinv2((x_q - x_p), p)) % p
# Point Doubling S
def sDouble(y_p, x_p, a, p):
   return ((3*(x_p**2)+a) *
           modinv2(2*y_p, p)) % p
def x_r(sr, x_p, x_q, p):
    return ((sr ** 2) - x_p - x_q) % p
def y_r(s, y_p, x_p, xr, p):
    return ((s * (x_p - xr)) - y_p) % p
def pointAddtion(x_p, y_p, x_q, y_q, p):
    sr = sAdd(y_p, y_q, x_p, x_q, p)
    xr = x_r(sr, x_p, x_q, p)
    yr = y_r(sr, y_p, x_p, xr, p)
    return xr, yr

def pointDoubling(x_p, y_p, a, p):
   sr = sDouble(y_p, x_p, a, p)
   xr = x_r(sr, x_p, x_p, p)
   yr = y_r(sr, y_p, x_p, xr, p)
   return xr, yr


# d) 2G : (0, 3) + (0, 3)
print(pointDoubling(0, 3, 5, 13))

# f) G + H: (0, 3) + (3, 5)
print(pointAddtion(0, 3, 3, 5, 13))
print(pointAddtion(0, 3, 2, 1, 13))

G = (0, 3)
# Alice's public key
G2 = pointDoubling(G[0], G[1], 5, 13)
G3 = pointAddtion(G2[0], G2[1], 0, 3, 13)
print("Alice's Public Point: \t", G3)

# Bobs public key
G6 = pointDoubling(G3[0], G3[1], 5, 13)
print("Bob's Public Point: \t", G6)

# Alice computes shared Key
a = 3
B = (11, 2) # G6
B2 = pointDoubling(B[0], B[1], 5, 13)
B3 = pointAddtion(B[0], B[1], B2[0], B2[1], 13)
print("Alice's Shared Point: \t", B3)

# Bob computes shared Key
b = 6
A = (3, 8) # also G3

A2 = pointDoubling(A[0], A[1], 5, 13)
A3 = pointAddtion(A[0], A[1], A2[0], A2[1], 13)
A6 = pointDoubling(A3[0], A3[1], 5, 13)
print("Bob's Shared Point: \t", A6)
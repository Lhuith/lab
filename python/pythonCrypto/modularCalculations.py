def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m

# 7 + 4 mod 12
val = (4 + 8) % 12
print(val)

# 4 * 5 mod 12
val = (4 * 5) % 12
print(val)

g = 2
for i in range(20):
    print("i: ", i, "result: ", (g**i)  % 5)

print(modinv(3, 26))
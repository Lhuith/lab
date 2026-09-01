import math

def lcm(a, b):
    return a * b // math.gcd(a, b)


def get_e(lambda_n):
    for e in range(2, lambda_n):
        if math.gcd(e, lambda_n) == 1:
            return e
    return False


def get_d(e, lambda_n):
    for d in range(2, lambda_n):
        if d * e % lambda_n == 1:
            return d
    return False

def factor(n):
    for p in range(2, n):
        if n % p == 0:
            return p, n//p

# key generation done by Alice (secret)
# step 1: generate two distinct primes
p = 2027
q = 2593
print("Primes", p, q)

# step 2: compute n = pq
n = p * q
print("Modulus n: ", n)

# step 3: compute lambda(n) (lcm(n) = λ(n) = lcm(λ(p),λ(q)), λ(p) = p-1, λ(q) = q-1, lcm(a,b) = |ab|/gcd(a,b))
lamba_n = lcm(p - 1, q - 1)
print("Lambda n", lamba_n)

# step 4: choose an interger e such that 1 < e < λ(n) and gcd(e, λ(n)) = 1
e = 65  #get_e(lamba_n)
print("public exponent ", e)

# Step 5: solve d the equation d*e = 1 (mod λ(n))
d = get_d(e, lamba_n)
print("secret exponent ", d)
m = 1024
print("the message ", m)
c = m**e % n
print("Bob sends: ", c)

# this is Alice decrypting the cipher
m = c**d % n
print("Alice reads message", m)

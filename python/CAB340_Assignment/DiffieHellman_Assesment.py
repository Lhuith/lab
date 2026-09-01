import math
import random


def is_prime(p):
    for i in range(2, math.isqrt(p)):
        if p % i == 0:
            return False
    return True


def get_prime(size):
    while True:
        p = random.randrange(size, 2 * size)
        if is_prime(p):
            return p

    for i in range(1, p - 1):
        if (g ** i) % p == 1:
            return False
    return True


def is_generator(g, prime):
    for i in range(1, prime - 1):
        possibleG = (g ** i) % prime
        if possibleG == 1:
            return False, possibleG, i
    return True, possibleG, i


def get_generator(p, lim):
    for g in range(2, lim):
        isGen, value, i = is_generator(g, p)
        if isGen:
            printResults(g, value, i, "✓")
            return g
        else:
            printResults(g, value, i, "x")
    return 2


def printResults(g, v, i, isGen):
    print('{:<1} {:<4}\t{:<4}\t{}'.format(isGen, g, v, i))


# public
p = 2027
# Sophie Germain prime
q = math.floor((p - 1) / 2)
g = get_generator(p, 10)
print("generator: ", g, "\nprime: ", p, "\nSophie Germain prime: ", q)

# Alice
a = 123
g_a = (g ** a) % p
# Alice sends this
print("Alice sends g_a: ", g_a)

b = 456
g_b = (g ** b) % p
# Bob sends this
print("Bob sends g_b: ", g_b)

# Alice
g_ab = (g_b ** a) % p
print("Alice g_ab: ", g_ab)

# bob
g_ba = (g_a ** b) % p
print("Bob g_ba: ", g_ba)

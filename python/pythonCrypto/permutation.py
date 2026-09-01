import cProfile

def factorial(n):
    return 1 if (n == 1 or n == 0) else n * factorial(n -1);

def counter(n):
    count = 0
    for i in range(n):
        count += 1
    return count;

cProfile.run("counter(factorial(13))")
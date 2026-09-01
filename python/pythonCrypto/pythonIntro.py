# Math
# - addition
# - multiplication
# - prime number (2, 3, 5, 7, ...)

# what we will learn
# - XOR
# - Modular calculations

# Python
# - Integer operations (addition, multiplication, division, XOR, modular)
a = 3
b = 7
sum = a + b
print(sum)
print(a * b)
print(b // a)


# - Functions
def add(a, b):
    return a + b


print(add(3, 7))
print(add(13, 17))

# - for and while loops
for i in range(5):
    print(i)

count = 5
while True:
    count -= 1
    print(count)
    if count <= 0:
        break

# - dictionaries
d = {}
d['a'] = 'b'
print(d['a'])
d['b'] = 'this is longer'
print(d['b'])

# - lists
my_list = ['ddd']*5
my_list.append(5)
print(my_list)

# - class / objects
class MyClass:
    def __init__(self, name="MyName"):
        self.name = name
    def get_name(self):
        return self.name

m = MyClass()
print(m.get_name())

m2 = MyClass("New Name")
print(m2.get_name())
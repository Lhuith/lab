def xor(x, s):
    print(str(bin(x)).format(37)[2:], 'xor', str(bin(s)).format(37)[2:], '=', str(bin((x ^ s))).format(37)[2:])
    print(x, 'xor', s, '=', (x ^ s))
xor(4, 8)
xor(4, 4)
xor(255, 1)
xor(255, 128)
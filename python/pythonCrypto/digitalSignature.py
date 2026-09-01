import hashlib

def modify(m):
    l = list(m)
    l[0] = l[0] ^ 1
    return bytes(l)

# These are alice's RSA keys
# Public key: (e,n):  5 170171
# Secret key (d) 9677; Private Key: (d, n)
n = 170171
e = 5
d = 9677

# This is the message that Alice wants to sign and send to Bob
message = "Bob you are awesome".encode()

# step 1: hash the message
sha256 = hashlib.sha256()
sha256.update(message)
h = sha256.digest()
h = int.from_bytes(h, "big") % n # wouldn't do this in real life!, just for example
print("hash value,", h)
og_h = h
#step 2: decrypt the hash value(use secret exponent)
sign = h**d % n

#step 3: send message with signatuire to bob
print(message, sign)

# This is Eve being evil and modifies the message
message = modify(message)
print("modified message: ", message)

# bob verify the signature
#step 1: calculate the hash value of the message
sha256 = hashlib.sha256()
sha256.update(message)
h = sha256.digest()
h = int.from_bytes(h, "big") % n # wouldn't do this in real life!, just for example
print("hash value,", h)

#step 2: Verify the signature
verification = (sign**e % n)
print("verification", verification == og_h)

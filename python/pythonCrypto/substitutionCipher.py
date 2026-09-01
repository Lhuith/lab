import random

def generate_key():
    letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    cipherLetters = list(letters)
    key = {}
    for c in letters:
        key[c] = cipherLetters.pop(random.randint(0, len(cipherLetters) - 1))
    return key

def endecrypt(key, message):
    cipher = ""
    for c in message:
        if c in key:
            cipher += key[c]
        else:
            cipher += " "
    return cipher

def get_decrypt_key(key):
    dkey = {}
    for k in key:
        dkey[key[k]] = k
    return dkey

key = generate_key()
print(key)

message = "YOU ARE AWESOME"
cipher = endecrypt(key, message)
print(cipher)

dkey = get_decrypt_key(key)
decryption = endecrypt(dkey, cipher)
print(decryption)
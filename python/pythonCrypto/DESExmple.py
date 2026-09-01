from pyDes import *

def modify(cipher):
    mod = [0]*len(cipher)
    mod[9] = 1
    return bytes(mod[i] ^ cipher[i] for i in range(len(cipher)))

message = "Give Bob:    10$ and send them to him"
key = "DESCRYPT"
iv = bytes([0]*8)
desCipher = des(key, CBC, iv, pad=None, padmode=PAD_PKCS5)

# Alice sending the encrypted message
cipher = desCipher.encrypt(message)
print("Length of plain text: ", len(message))
print("Length of cipher text: ", len(cipher))
print("Encrypted:", cipher)

# bob modifying the cipher text
cipher = modify(cipher)

message = desCipher.decrypt(cipher)
print("Decrypted:", message)

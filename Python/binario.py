def decimal_binario(num):
    binario = ''
    quociente = num
    while quociente > 0:
        binario += str(quociente % 2)
        quociente = quociente / 2
    return binario[::-1]

def main():
    print decimal_binario(127)

if __name__ == "__main__": main()

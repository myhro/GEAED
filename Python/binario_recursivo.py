def decimal_binario(num, resultado):
    if num == 0:
        return resultado[::-1]
    resultado += str(num % 2)
    num = num / 2
    return decimal_binario(num, resultado)

def main():
    print decimal_binario(10,'')

if __name__ == "__main__": main()

def main():
    numero = 999
    
    lista1 = ['I', 'IV','V', 'IX', 'X', 'XL', 'L','XC', 'C', 'CD', 'D', 'CM','M']
    lista2 = [1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000]
    
    resultado = ''
    
    for i in lista2[::-1]:
        while numero >= i:
            numero -= i
            resultado += lista1[lista2.index(i)]
            
    print resultado
    
if __name__ == "__main__": main()

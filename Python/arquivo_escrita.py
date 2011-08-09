def main():
    arquivo = open('teste.txt', 'w')
    lista = [1,2,3,4,5]
    for elem in lista:
        arquivo.write(str(elem) + '\n')
    arquivo.close()    

if __name__ == "__main__": main()

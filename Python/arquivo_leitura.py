def main():
    lista = []
    arquivo = open('teste.txt', 'r')
    for linha in arquivo:
        lista.append(int(linha))
    arquivo.close()
    print lista

if __name__ == "__main__": main()

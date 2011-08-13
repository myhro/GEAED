from getpass import getpass

def main():
    j1_vit = 0
    j2_vit = 0
    while True:
        if j1_vit == 2 or j2_vit == 2:
            break 
        while True:
            j1 = getpass("Jogador 1, escolha (Pedra/Papel/Tesoura): ")
            j1 = j1.lower()
            if j1 != 'pedra' and j1 != 'papel' and j1 != 'tesoura':
                continue
            else:
                break
        
        while True:
            j2 = getpass("Jogador 2, escolha (Pedra/Papel/Tesoura): ")
            j2 = j2.lower()
            if j2 != 'pedra' and j2 != 'papel' and j2 != 'tesoura':
                continue
            else:
                break
            
        if j1 == j2:
            print 'Empate'
        elif j1 == "pedra":
            if j2 == "papel":
                print "Jogador 2 e o vencedor"
                j2_vit += 1
            else:
                print "Jogador 1 e o vencedor"
                j1_vit += 1
        
        elif j1 == "papel":
            if j2 == "tesoura":
                print "Jogador 2 e o vencedor"
                j2_vit += 1
            else:
                print "Jogador 1 e o vencedor"
                j1_vit += 1
        
        else:
            if j2 == "pedra":
                print "Jogador 2 e o vencedor"
                j2_vit += 1
            else:
                print "Jogador 1 e o vencedor"
                j1_vit += 1
    vencedor = 'Jogador '
    if j1_vit == 2:
        vencedor += '1'
    else:
        vencedor += '2'
    vencedor += ' venceu!'
    print vencedor
   
if __name__ == "__main__": main()

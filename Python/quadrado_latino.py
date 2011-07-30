def latino(matriz, n):
    for linha in xrange(len(matriz)):
        for i in xrange(1,n+1):
            if i not in matriz[linha]:
                return 'Numero {0} nao presente na linha {1}.'.format(i,linha+1)
            if matriz[linha].count(i) > 1:
                return 'Numero {0} presente mais de uma vez na linha {1}.'.format(i,linha+1)

    for coluna in xrange(len(matriz[0])):
        for i in xrange(1,len(matriz)+1):
            if i not in matriz[coluna]:
                return 'Numero {0} nao presente na coluna {1}.'.format(i,coluna+1)
            if matriz[coluna].count(i) > 1:
                return 'Numero {0} presente mais de uma vez na coluna {1}.'.format(i,linha+1)

    return 'A matriz e um quadrado latino.'

def main():
    mat = [[1,2,3,4],[2,3,4,1],[4,1,2,3],[3,4,1,2]]
    print latino(mat, len(mat))

if __name__ == "__main__": main()

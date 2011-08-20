def main():
    while True:
        n = int(raw_input())
        if n == 0:
            break
        matriz = [[int(k) for k in raw_input().split()] for x in xrange(n)]
        
        somatorio = 0
        final = 0
        for i in xrange(n):
            somatorio = 0
            for j in xrange(n):
                somatorio += matriz[j][i]
            if somatorio > final:
                final = somatorio
        print final
        

if __name__ == "__main__": main()

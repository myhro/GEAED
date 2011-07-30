def shellsort(lista):
    h = 1
    n = len(lista)
    while True:
        h = h * 3 + 1
        if h > n:
            break
    while True:
        h /= 3
        if h < 1:
            break
        i = h
        while True:
            if i >= n:
                break
            j = i - h
            tmp = lista[i]
            while j >= 0 and tmp < lista[j]:
                lista[j + h] = lista[j]
                j -= h
            lista[j + h] = tmp;
            i += 1

def main():
    lista = [6,1,2,4,8,9,3,5,7,0]
    shellsort(lista)
    print lista

if __name__ == "__main__": main()

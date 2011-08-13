def main():
    cpf = "111.444.777-35"
    #linha1 = []
    #linha2 = []
    #linha3 = []
    
    '''for i in xrange(len(cpf)-2):
        c = cpf[i]
        if c.isdigit():
            linha1.append(int(c))'''
    linha1 = [int(i) for i in cpf[:-3] if i.isdigit()]
            
    '''n = 10
    for i in xrange(9):
        linha2.append(n)
        n -= 1 '''
    linha2 = [i for i in xrange(2,11)][::-1]
         
    '''for i in xrange(9):
        linha3.append(linha1[i]*linha2[i])'''
    
    linha3 = [n*k for n, k in zip(linha1, linha2)]
    
    '''somatorio = 0
    for i in linha3:
        somatorio += i'''
    somatorio = sum(linha3)

    resto = somatorio % 11
    '''if resto < 2:
        linha1.append(0)
    else :
        linha1.append(11-resto)'''
    linha1.append(0 if resto < 2 else 11 - resto)
    
    linha2.insert(0, 11)    
    '''for i in xrange(9):
        linha3[i]=(linha1[i]*linha2[i])
    linha3.append(linha1[-1]*linha2[-1])'''
    linha3 = [n*k for n, k in zip(linha1, linha2)]
    
    '''somatorio = 0
    for i in linha3:
        somatorio += i'''
    somatorio = sum(linha3)
        
    resto = somatorio % 11
    '''if resto < 2:
        linha1.append(0)
    else :
        linha1.append(11-resto)'''
    linha1.append(0 if resto < 2 else 11 - resto)
    
    if linha1[-1] == int(cpf[-1]) and linha1[-2] == int(cpf[-2]):
        print "CPF valido"
    else:
        print "CPF invalido" 
        print "Os ultimos digitos deveriam ser {0}{1}".format(linha1[-2],linha1[-1])
        
if __name__ == "__main__": main()
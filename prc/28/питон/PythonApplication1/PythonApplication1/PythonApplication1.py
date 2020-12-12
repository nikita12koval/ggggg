def print_factorization(c: int)-> None:
  for i in range(2, int(c + 1)):
    if (c % i == 0):
        a = 0
        b = 1
        while (c % i == 0):
            c = c / i
            a+=1
        if (a == 1):
            print (i, "*")
        else:
             print (i, "^", a, "*")
c = int(input()) 
print_factorization(n)

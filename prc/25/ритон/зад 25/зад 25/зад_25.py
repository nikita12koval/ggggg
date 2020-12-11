import random 
def bogoSort(b):
    k = len(b) 
    while (s(b)== False): 
        rg(b) 
def s(b): 
    k = len(b) 
    for i in range(0, n-1): 
        if (b[i] > b[i+1] ): 
            return False
    return True
def rg(b): 
    n = len(b) 
    for i in range (0,n): 
        r = random.randint(0,n-1) 
        b[i], b[r] = b[r], b[i] 

a = [45, 67, 90, 4, 4,34, 54, 67, 52, 45, 12, 1] 
bogoSort(a) 
print("Ваш отсортированный массив :") 
for i in range(l(a)): 
    print ("%d" %a[i]), 

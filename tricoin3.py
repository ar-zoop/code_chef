def tricoin(n):
    a=-(n*2)
    y= (1-(4*a))
    z=sqrt(y)
    x=(-1+z)//2
    print (x)
    return 

t=int(input())
for i in range(t):
    n=int(input())
    if (n==0):
        print ("0")
    elif (n==1 or n==2):
        print ("1")
    else:
        tricoin(n)
     


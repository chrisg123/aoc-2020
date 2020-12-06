import sys
def main():
    a,b = g(numbers(), 2020)
    print("%d * %d == %d" %(a,b,a*b))
          
def g(x,y):
    d = {}
    for n in x:
       a = int(n)
       b = y - a
       if a in d:
           return (a,d[a])
       d[b] = a
        
def numbers():
    with open("../input.txt", 'r') as f:
        return f.readlines()
        
if __name__ == '__main__':
    sys.exit(main())
    

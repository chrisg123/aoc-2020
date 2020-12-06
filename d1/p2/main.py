import sys
def main():
    ns = numbers()
    for n in ns:
        a = int(n)
        m = 2020 - a
        r = g(ns, m)
        if r:
            b,c = r
            print("%d + %d + %d == %d" \
                  %(a,b,c,a+b+c))
            print("%d * %d * %d == %d" \
                  %(a,b,c,a*b*c))
            break

def g(x,y):
    d = {}
    for n in x:
       a = int(n)
       b = y - a
       if a in d:
           return (a,d[a])
       d[b] = a
    return None

def numbers():
    with open("../input.txt", 'r') as f:
        return f.readlines()

if __name__ == '__main__':
    sys.exit(main())

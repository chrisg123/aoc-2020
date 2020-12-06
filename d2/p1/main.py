import sys

def main():
    valid = 0
    for l in input():
        if check(parse(l.rstrip())):
            valid += 1
    print(str(valid))
    return 0

def parse(x):
    s = x.split(':')
    s2 = s[0][:-1].strip().split('-')
    return (int(s2[0]),
            int(s2[1]),
            s[0][-1],
            s[1].strip())

def check(tpl):
    min,max,c,s = tpl
    count = 0
    for x in s:
        if x == c: count += 1
        if count > max: return False
    return count >= min
    

def input():
    with open("../input.txt") as f:
        return f.readlines()

if __name__ == '__main__':
    sys.exit(main())
    

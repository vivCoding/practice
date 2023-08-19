"""
Problem: https://purdue.kattis.com/courses/CS390-CP2/2023-spring/assignments/bshgus/problems/simon

"""

t = input()

for _ in range(int(t)):
    x = input()
    w = x.split(' ')
    if len(w) > 2 and w[0] == 'simon' and w[1] == 'says':
        print(x[11:])
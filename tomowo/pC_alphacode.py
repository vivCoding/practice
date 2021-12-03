# Problem: https://vjudge.net/contest/470649#problem/C
import sys

nums = []

while True:
	x = sys.stdin.readline()
	if x != '0\n':
		nums.append(x)
	else: break

for num in nums:
	count = 1
	for i in range(len(num) - 2):
		if int(num[i] + num[i + 1]) <= 26:
			count *= 2
	print(max(count, 1))
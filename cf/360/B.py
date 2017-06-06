#to namiri daram python mizanam =)
n = 0
k = 0
d = [0]
a = []

def check(diff):
	ret = n
	irng = range(1, n + 1)
	for i in irng:
		dp[i] = i
		sum = 0
		jrng = range(i, 0, -1)
		for j in jrng:
			sum += d[j]
			if abs(sum) <= (i - j + 1) * diff and dp[j - 1] + i - j < dp[i]:
				dp[i] = dp[j - 1] + i - j
		if dp[i] + n - i < ret:
		 	ret = dp[i] + n - i
	return ret <= k

inp = raw_input()
n = int(inp.split()[0])
k = int(inp.split()[1])
inp = raw_input()
lst = inp.split()
for i in range(n):
	a.append(int(lst[i]))
	if i > 0:
		d.append(a[i] - a[i - 1])
dp = range(n)
n += -1
lo = -1
hi = 2000000000
while hi - lo > 1:
	mid = (lo + hi) >> 1
	if check(mid):
		hi = mid
	else:
	 	lo = mid
print(hi)

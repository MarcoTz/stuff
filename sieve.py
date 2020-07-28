n = 1000

primes = []
candidates = list(range(2,n))

while len(candidates) != 0:
	c = candidates[0]
	primes.append(c)
	p = c
	print(candidates)
	while p < n:
		try:
			candidates.remove(p)
		except ValueError:
			pass
		p = p+c
print(primes)

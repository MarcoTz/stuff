MAX = 100
MIN = 0

#converts nr to list of digits
def nr_to_ls(i):
	s = str(i)
	res = []
	for c in s: 
		res.append(int(c))
	return res

#does the happification process for a number once
def happy_once(i):
	ls = nr_to_ls(i)
	res = 0
	for j in ls:
		res+=j*j
	return res

def try_happy(i):
	passed = []
	while i not in passed:
		passed.append(i)
		i = happy_once(i)
	passed.append(i)
	return passed

connections = []
for i in range(MIN,MAX):
	for i in range(0,len(conns)-1):
		if (conns[i],conns[i+1]) not in connections:
			connections.append((conns[i],conns[i+1]))

f = open('graph.dot','w')
f.write('graph{\n')
for con in connections:
	f.write(str(con[0])+'--'+str(con[1])+'\n')
f.write('}')

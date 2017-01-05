MAX=1000
MIN=1
connections=[]
for i in range(MIN,MAX):
	while i!=1:
		if i%2==0:
			newi = int(i/2)
		else:
			newi=3*i+1
		if (i,newi) not in connections:
			connections.append((i,newi))
		i=newi

f = open('graph.dot','w')
f.write('graph{\n')
for con in connections:
	f.write(str(con[0])+'--'+str(con[1])+'\n')
f.write('}')


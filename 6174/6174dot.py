import json

try:
    f = open('data','r')
except FileNotFoundError:
    print('Please generate data with 6174.py first')
    exit()

graph = open('data.dot','w')
graph.write('graph{\n')

for line in f:
    curr = json.loads(line)
    if curr[1] is not False:
        for i in curr[1]:
            graph.write(str(curr[0])+'--'+str(i)+'\n')
    
graph.write('}')

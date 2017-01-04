import json

#returns the highest number you can make by arranging the four given digits
def dig_minmax(i, highest=True):
    ls = nr_to_list(i)
    ls.sort()
    if not highest:
        ls.reverse() 
    res = 0
    for i in range(0,len(ls)):
        res += ls[i]*pow(10,i)

    return res

#converts a number to a list
def nr_to_list(i):
    s = str(i)
    ls = []
    for c in s:
        ls.append(int(c))
    return ls

#does one karekar iteration
def kap_iter(i):
    max_nr = dig_minmax(i)
    min_nr = dig_minmax(i,False)
    return max_nr-min_nr

#checks if number will converge to 6174
#any number <10000 with at least two distinc digits will converge
def does_converge(i):
    s = str(i)
    if len(s) > 4:
        return False

    if len(s)<4 and s!="0":
        return True
   
    converge = False
    last_c = s[0]
    for c in s:
        if c!=last_c:
            converge=True

    return converge

#does karekar interations until i converges
#only if i converges
#if i converges returns number of iterations, else returns False
def kap(i):
    if not does_converge(i):
        return False 
    
    i=mult4(i)
    steps = []
    while i!=6174:
        i = kap_iter(i) 
        steps.append(i)
        i=mult4(i)
    return steps
        
#multiplies a number by 10 until it has 4 digits
def mult4(i):
    if len(str(i))==4:
        return i
    if len(str(i))>4:
        return false
    
    while len(str(i))<4:
        i=i*10

    return i


f = open('data','w')

for i in range(0,10000):
    ls = kap(i)
    if ls is False:
        print(str(i)+" does not converge")
    else:
        print(str(i)+" converges in "+str(len(ls))+" steps, going through "+str(ls))

    f.write(json.dumps((i,ls))+"\n")


# Products=[ 'A' ,'B' ,'C' ,'D' ,'E' ,'F']
# Staging=[ 20,30 ,45 ,60 ,20, 10]
# Photo=[30,30 ,15 ,20 ,40, 60]pyt


file = open("inputPS1.txt", 'r')
d={}
for each in file: 
	field=each.split(':')
	d[field[0]]=(field[1].strip(" \n")).split(' / ')
	

l=[io for io in d.values()]
zipped_lists = zip(l[0],l[1],l[2])
sorted_pairs = sorted(zipped_lists)

sorted_pairs.sort(key= lambda x:(x[1],x[2]))

tuples = zip(*sorted_pairs)
product,staging,photo = [ list(tuple) for tuple in  tuples]
print("Product Sequence: ", product)
wait_time=0
total_time=0
time=0
for i in range (len(photo)):
    time+=int(photo[i])
    total_time-=int(staging[i])
    
    if(total_time<0):
        wait_time+=abs(total_time)
        total_time=0
  
    total_time+=int(photo[i])	

print("Total time to complete photoshoot: ", time+wait_time)
print("Idle time for Xavier: ",wait_time)
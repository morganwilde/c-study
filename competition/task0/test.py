import datetime, time
 
start = time.time()
 
count = 0
for i in range(200):
    for j in range(200):
		for k in range(200):
			#print i*j*k
			print str(count) + " - " + str(i*j*k)
			count += 1
 
#40.2932 - 30
#43.4881 - 50
#42.0525 - 70
#40.8721 - 100
#41.3102

#34.478094

end = time.time()
difference = datetime.datetime.fromtimestamp(start) - datetime.datetime.fromtimestamp(end)
print('time to finish {0} seconds'.format(abs(difference.total_seconds())))
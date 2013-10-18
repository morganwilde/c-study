import datetime, time

start = time.time()

count = 0
for i in range(100):
	for j in range(100):
		for k in range(100):
			#print i*j*k
			print str(count) + " - " + str(i*j*k)
			count += 1

end = time.time()
difference = datetime.datetime.fromtimestamp(start) - datetime.datetime.fromtimestamp(end)
print('time to finish {0} seconds'.format(abs(difference.total_seconds())))

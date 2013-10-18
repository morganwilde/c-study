#!/bin/bash

echo "Testing"

for i in {1..5}
do
	filei=`printf "%02d" $i`
	cp "test.$filei.in" "ads.in"
	./ads
	# convert dos to unix
	#sed -e 's/\r$//' "test.$filei.out" > "test.$filei.outtmp"
	perl -pe 's/\r\n|\n|\r/\n/g' "test.$filei.out" > "test.$filei.outtmp"
	
	difference=$(diff "ads.out" "test.$filei.outtmp" | grep ">")
	diff "ads.out" "test.$filei.outtmp"
	#cat ads.out
	#echo "test.$filei.out"
	#cat test.$filei.out
	if [[ -z "$difference" ]]
	then
		echo "Test $i - OK"
	else
		echo "Test $i - Wrong answer"
	fi

	rm "ads.in"
	rm "ads.out"
	rm "test.$filei.outtmp"
done

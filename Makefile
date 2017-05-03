bucketsort: bucketsort.cpp bucket.o
	g++ -std=c++11 -Wfatal-errors -O2 bucket.o bucketsort.cpp -o bucketsort

bucket.o: bucket.cpp bucket.h
	g++ -std=c++11 -Wfatal-errors -O2 -c bucket.cpp

clean:
	rm -f *.o

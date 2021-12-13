OBJS = country.o main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

program : $(OBJS) summary.csv
	$(CC) $(LFLAGS) $(OBJS) -o program

country.o : country.h country.cpp
	$(CC) $(CFLAGS) country.cpp

main.o : country.h main.cpp
	$(CC) $(CFLAGS) main.cpp

summary : 
	wget https://api.covid19api.com/summary

summary.csv : summary
	./json2csv summary > summary.csv

clean:
	\rm *.o program summary summary.csv

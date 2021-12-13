SRC = main.cpp SignInOut.cpp CustomerDatabase.cpp Customer.cpp Database.cpp NotifyCustomers.cpp BusinessDatabase.cpp Business.cpp Admin.cpp
IDIR = ./lib/include/jdbc/cppconn
LDIR = ./lib/lib
CC = g++
DEBUG = -g
CFLAGS = -Wall -I $(IDIR) $(DEBUG)
LFLAGS = -L $(LDIR)
LIBS = -lmysqlcppconn

quicktrack : $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LFLAGS) $(LIBS) -o quicktrack

clean:
	rm quicktrack

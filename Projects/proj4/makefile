EXE = $${PWD\#\#*/}
CXXFLAGS = -Wall -g
SOURCES = $(wildcard *.cpp)
OBJS = $(SOURCES:.cpp=.o)
DEPS = $(wildcard *.h)

all: $(EXE) run

build: $(EXE)

c: clean all

echo:
	echo $(Folder)
	
$(EXE): $(OBJS)
	$(CXX) $(OBJS) -o $(EXE)
	
	

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< 
	
	
(%): %.cpp
	$(CXX) -g $< -o $%
	gdb $%
	

clean:
	rm -f $(EXE) $(OBJS) $(wildcard *.stackdump)
	# rm *.o*
	# rm *~ 

	


run:
	./$(EXE)
	
run1: build
	./proj4 p4_comp1.txt p4_user1.txt

run2: build
	./proj4 p4_comp2.txt p4_user2.txt

run3: build
	./proj4 p4_comp3.txt p4_user3.txt
	
c1: clean run1

c2: clean run2

c3: clean run3

v1: build
	valgrind ./proj4 p4_comp1.txt p4_user1.txt

v2: build
	valgrind ./proj4 p4_comp2.txt p4_user2.txt

v3: build
	valgrind ./proj4 p4_comp3.txt p4_user3.txt
	
depend: .depend

.depend: $(DEPS)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ > ./.depend;
	
include .depend


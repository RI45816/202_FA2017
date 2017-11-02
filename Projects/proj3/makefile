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
	./proj3 proj3_t1.txt

run2: build
	./proj3 proj3_t2.txt

run3: build
	./proj3 proj3_t3.txt

c1: clean run1

c2: clean run2

c3: clean run3


	
depend: .depend

.depend: $(DEPS)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ > ./.depend;
	
include .depend


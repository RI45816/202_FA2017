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
	./$(EXE) p5_music1.txt

val1: build
	valgrind ./$(EXE) p5_music1.txt

v1: build
	valgrind --leak-check=full ./$(EXE) p5_music1.txt
	
depend: .depend

.depend: $(DEPS)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ > ./.depend;
	
include .depend


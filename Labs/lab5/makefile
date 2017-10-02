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
	
	

clean:
	rm -f $(EXE) $(OBJS) $(wildcard *.stackdump)
	# rm *.o*
	# rm *~ 

	


run:
	./$(EXE)
	
	
depend: .depend

.depend: $(DEPS)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ > ./.depend;
	
include .depend

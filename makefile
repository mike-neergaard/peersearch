CC = g++

IDIR = ./include
OBJDIR = ./obj
SRCDIR = ./src
CFLAGS = -I$(IDIR) -std=c++11 
LFLAGS = -v
HDRS = $(wildcard $(IDIR)/*.h)
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ= $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))
EXECUTABLE = peersearch


simple: 
	$(CC) $(CFLAGS) $(SRC) -o $(EXECUTABLE)

all:	$(EXECUTABLE)
    
$(SRC):	$(HDRS)
	touch $@

$(OBJ):	$(SRC) | ObjDir
	$(CC) $(CFLAGS) -c $< -o $@


ObjDir:
	@mkdir -p $(OBJDIR)

$(EXECUTABLE):	$(OBJ)
	$(CC) $^ $(LFLAGS)  -o $@

.PHONY: again
again:
	$(CC) $(LFLAGS) $(OBJ) -o $@


.PHONY: clean
clean:
	rm peersearch
	rm $(OBJ)

#A little trick to printout variable contents
print-%:
	@echo '$*=$($*)'


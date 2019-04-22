ifeq ($(OS), Windows_NT)
	CXX = g++
else
	CXX = /usr/local/Cellar/mingw-w64/6.0.0/bin/i686-w64-mingw32-g++
endif

OBJS = label.o main.o

all: $(OBJS)
	$(CXX) $(OBJS) -o main.exe -static
clean:
	rm -f
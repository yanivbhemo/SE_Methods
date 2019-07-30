CXX = i686-w64-mingw32-g++
CPPFLAGS = -std=c++1z -static -g

OBJS += Common/Control.o Common/EventEngine.o Common/Graphics.o FinalProject/Source.o Controls/Label.o Common/Border/Border.o Common/Border/None.o Common/Border/Single.o Common/Border/Double.o Controls/Panel.o Controls/Button.o Controls/NumericBox.o Controls/CheckList.o Controls/TextBox.h
# OBJS += try/try.o

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

all: $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o final.exe
clean:
	rm -f $(OBJS)
	rm -f *.exe
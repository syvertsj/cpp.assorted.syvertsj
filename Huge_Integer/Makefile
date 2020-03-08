
CXX           = g++
LINK          = g++
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. 
LFLAGS        = -m64 -Wl,-O1
LIBS          = -L/usr/lib/x86_64-linux-gnu -lpthread 
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CXXFLAGS      = -m64 -pipe -O2 -W -D_REENTRANT $(DEFINES)

OBJECTS       = HugeInt.o mainHugeInt.o
TARGET        = mainHugeInt

start: 
	@echo "make [all|run|clean]"

all: Makefile $(TARGET)

run: $(TARGET)
	@./$(TARGET) 

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

HugeInt.o: HugeInt.cpp HugeInt.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o HugeInt.o HugeInt.cpp $(LIBS)

mainHugeInt.o: mainHugeInt.cpp HugeInt.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainHugeInt.o mainHugeInt.cpp $(LIBS)

clean:
	-rm -f $(OBJECTS) $(TARGET) 
	-rm -f *~ core *.core 


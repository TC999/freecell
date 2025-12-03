# Makefile for FreeCell game project
# Cross-compilation for Windows using MinGW-w64

CXX = x86_64-w64-mingw32-g++
CXXFLAGS = -std=c++17 -Wall -DUNICODE -D_UNICODE -O2
LDFLAGS = -static -mwindows
LIBS = -luser32 -lgdi32 -lshell32 -lcomctl32 -lole32 -lcomdlg32 -ladvapi32

# Source files
SOURCES = winmain.cpp InitializeEngine.cpp EngineHandler.cpp DialogHelper.cpp FreeCellGame.cpp globals.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Output
TARGET = FreeCell.exe

# Build rules
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Dependencies
winmain.o: winmain.cpp types.h DialogHelper.h EngineHandler.h InitializeEngine.h
InitializeEngine.o: InitializeEngine.cpp InitializeEngine.h types.h DialogHelper.h EngineHandler.h
EngineHandler.o: EngineHandler.cpp EngineHandler.h types.h DialogHelper.h
DialogHelper.o: DialogHelper.cpp DialogHelper.h types.h
FreeCellGame.o: FreeCellGame.cpp FreeCellGame.h types.h
globals.o: globals.cpp types.h DialogHelper.h EngineHandler.h

# Clean
clean:
	rm -f $(OBJECTS) $(TARGET)

# Rebuild
rebuild: clean all

.PHONY: all clean rebuild

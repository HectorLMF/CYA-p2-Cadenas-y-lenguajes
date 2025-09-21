CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
SRCDIR = src
SOURCES = $(SRCDIR)/Alphabet.cc $(SRCDIR)/String.cc $(SRCDIR)/Language.cc $(SRCDIR)/Main.cc
EXECUTABLE = cadenas_lenguajes

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(SOURCES)

clean:
	rm -f $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

.PHONY: all clean run
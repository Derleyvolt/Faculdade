CXX      = g++
CXXFLAGS = -std=c++17 -o -02 -Wall -pedantic

# -Werror transforma qualquer warning em compilation error
# -02     otimização de código.. torna a compilação mais lenta

program:
	$(CXX) $(CXXFLAGS) $(program) $(program).cpp && ./$(program)

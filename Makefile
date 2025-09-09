CFLAGS = -std=c++17 -O2

c++: main.cpp
	g++ $(CFLAGS) -o c++ main.cpp
	x86_64-w64-mingw32-g++ $(CFLAGS) -static -s -o c++.exe main.cpp
# i686-w64-mingw32-g++ -static-libstdc++ -o c++.exe main.cpp

.PHONY: test clean

test: c++
	./c++

clean:
	rm -f c++
	rm -f c++.exe
all: main.o InterfazGLUT.o
	g++ main.o InterfazGLUT.o -o aed -lfreeglut -lopengl32 -lglu32

main.o: src/main.cpp
	g++ -c src/main.cpp

InterfazGLUT.o: src/InterfazGLUT.cpp
	g++ -c src/InterfazGLUT.cpp

run:
	./aed

clean:
	rm *.o aed
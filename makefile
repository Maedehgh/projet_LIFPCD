
all:myProgram
myProgram: src/mainTest.cpp src/Image.cpp src/Pixel.cpp
	g++ -Wall src/mainTest.cpp src/Image.cpp src/Pixel.cpp -o bin/myProgram
clean:
	rm -f bin/myProgram
myProjet: Pixel.o Image.o mainTest.o
	g++  Pixel.o Image.o mainTest.o -o myProjet

#Pixel.o : Pixel.cpp Pixel.h
#	g++ -Wall -c Pixel.cpp

#Image.o: Image.cpp Image.h
#	g++ -Wall -c Image.cpp
#in the LIFAPCD CONCEPTION ET DEVELOPPEMENT D’APPLICATIONS
#OBJS = Pixel.o Image.o mainTest.o
#FLAGS =  -ggdb-Wall
#myProjet = $(OBJS)
#	g++ $(FLAGS) -o myProjet $(OBJS)
#clean :
#	rm obj/*.o



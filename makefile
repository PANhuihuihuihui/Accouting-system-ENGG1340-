final.o: final.cpp gobal.h
	g++ -c final.cpp
print.o: print.cpp
	g++ -c print.cpp
final: final.o print.o
	g++ $^ -o final
clean:
	rm final final.o print.o
tar:
	tar -czvf final.tgz *.cpp 
.PHONY: clean tar




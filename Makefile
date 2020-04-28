FLAGS = -pedantic-errors -std=c++11
STRUCT = palyer.h

initialization.o: initialization.cpp $(STRUCT)
	g++ $(FLAGS) -c $<

main.o: main.cpp initialization.h $(STRUCT)
	g++ $(FLAGS) -c $<

main: main.o initialization.o
	g++ $(FLAGS) $^ -o $@

tar:
	tar -czvf project.tgz *.cpp *.h

clean:
	rm -f main main.o initialization.o project.tgz

.PHONY: clean tar

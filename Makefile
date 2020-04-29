FLAGS = -pedantic-errors -std=c++11
STRUCT = palyer.h

initialization.o: initialization.cpp $(STRUCT)
	g++ $(FLAGS) -c $<

gamestage.o: gamestage.cpp $(STRUCT)
	g++ $(FLAGS) -c $<

result.o: result.cpp $(STRUCT)
	g++ $(FLAGS) -c $<

main.o: main.cpp functions.h $(STRUCT)
	g++ $(FLAGS) -c $<

main: main.o initialization.o gamestage.o result.o
	g++ $(FLAGS) $^ -o $@

tar:
	tar -czvf project.tgz *.cpp *.h

clean:
	rm -f main main.o initialization.o result.o gamestage.o result.txt project.tgz

.PHONY: clean tar

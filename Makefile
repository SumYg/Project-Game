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

gp87game: main.o initialization.o gamestage.o result.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f gp87game main.o initialization.o result.o gamestage.o result.txt

again:
	rm result.txt
	./gp87game

.PHONY: clean again

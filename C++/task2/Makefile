all: program.out

program.out: main.cpp utils.cpp miller_test.cpp
	g++ main.cpp utils.cpp pocklington_test.cpp gost_test.cpp -o program.out

clean:
	rm -f program.out
MAINS := $(wildcard *.cpp)
LIBS := $(shell root-config --cflags --libs)

test: $(MAINS)
	for ff in $(patsubst %.cpp, %, $(MAINS)) ; do \
		g++ $(LIBS) -o $$ff $$ff.cpp  ; \
	done

clean:
	rm $(patsubst %.cpp, %, $(MAINS))

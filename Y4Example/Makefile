Target  = Analysis
Objects = Reader.o WeightReader.o
ROOTFLAGS = $(shell root-config --cflags)
ROOTLIBS  = $(shell root-config --libs)

all:$(Target)

Analysis: Analysis.cxx Analysis.h  $(Objects)
	g++ -o $@ Analysis.cxx $(Objects) $(ROOTFLAGS) $(ROOTLIBS)

Reader.o: Reader.C Reader.h
	g++ -o $@ Reader.C -c $(ROOTFLAGS) 

WeightReader.o: WeightReader.C WeightReader.h
	g++ -o $@ WeightReader.C -c $(ROOTFLAGS) 

clean:
	rm -f Analysis *.o
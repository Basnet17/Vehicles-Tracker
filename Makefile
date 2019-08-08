# Makefile for muni project
#****************************************************************

CPPOPTIONS = -I../StanfordCPPLib -fvisibility-inlines-hidden -std=c++11 -g
LDOPTIONS = -L../StanfordCPPLib
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: muni test_track test_time test_point spl.jar

spl.jar:
	@ln -s ../StanfordCPPLib/spl.jar

muni: muni.o point.o time.o track.o
	g++ $(LDOPTIONS) -o muni muni.o point.o time.o track.o $(LIB)

muni.o: muni.cpp point.h time.h track.h
	g++ $(CPPOPTIONS) -c muni.cpp

point.o: point.cpp point.h
	g++ $(CPPOPTIONS) -c point.cpp

time.o: time.cpp time.h
	g++ $(CPPOPTIONS) -c time.cpp

track.o: track.cpp track.h
	g++ $(CPPOPTIONS) -c track.cpp

test_point.o: test_point.cpp point.h time.h
	g++ $(CPPOPTIONS) -c test_point.cpp

test_point: test_point.o point.o time.o
	g++ $(LDOPTIONS) -o test_point test_point.o point.o time.o $(LIB)

test_time.o: test_time.cpp time.h
	g++ $(CPPOPTIONS) -c test_time.cpp

test_time: test_time.o time.o
	g++ $(LDOPTIONS) -o test_time test_time.o time.o $(LIB)

test_track.o: test_track.cpp track.h point.h time.h
	g++ $(CPPOPTIONS) -c test_track.cpp

test_track: test_track.o track.o point.o time.o
	g++ $(LDOPTIONS) -o test_track track.o test_track.o point.o time.o $(LIB)

# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS)

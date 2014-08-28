CXX=g++
CXXFLAGS=-Wall -g

tests/test :
	$(CXX) $(CXXFLAGS) -I./include ./src/CompareoRSCMP7Capture.cc ./tests/testingoRSCcapture.cpp -o tests/testGlobal

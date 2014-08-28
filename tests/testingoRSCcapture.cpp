//Simple test on ORSC operation methods
#include <iostream>
#include "CompareoRSCMP7Capture.hh"

int main() {


std::vector < std::vector < unsigned int > > bufferoRSC;
std::vector < std::vector < unsigned int > > rawdataoRSC;
std::vector < std::vector < unsigned int > > rawdataMP7;

unsigned int array[1024];

//Needed to Reserve Enough Memory for this vector of vectors
std::vector<unsigned int> tempVector;
tempVector.resize(sizeof(array));
bufferoRSC.resize(6*sizeof(tempVector));
  
  for(unsigned int i = 0; i<23; i++) {
    for(int j = 0; j < 1024; j++) bufferoRSC[i].push_back(j);
 }     

CompareoRSCMP7Capture *compare=new CompareoRSCMP7Capture();
compare->SetoRSCPattern(bufferoRSC);
compare->SetoRSCBuffer(bufferoRSC);
compare->SetMP7Buffer(bufferoRSC);
bool flag=compare->Compare();
if(flag) std::cout<<"comparison successfully ended"<<std::endl;
else std::cout<<"comparison failed"<<std::endl;

return 1;

}


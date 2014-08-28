//Simple test on ORSC operation methods
#include <iostream>
#include "CompareoRSCMP7Capture.hh"

int main() {

std::vector < std::vector < unsigned int > > bufferoRSC;
std::vector < std::vector < unsigned int > > rawdataoRSC;
std::vector < std::vector < unsigned int > > rawdataMP7;

unsigned int array[1024];
int latencyMP7vsORSC=9;

//Needed to Reserve Enough Memory for this vector of vectors
std::vector<unsigned int> tempVector;
tempVector.resize(sizeof(array));

bufferoRSC.resize(6*sizeof(tempVector));
 for(unsigned int i = 0; i<23; i++) {
    for(int j = 0; j < 1024; j++) bufferoRSC[i].push_back(j);    
 }   
 
rawdataoRSC.resize(6*sizeof(tempVector));
 for(unsigned int i = 0; i<23; i++) {
    for(int j = 0; j < 1024; j++) rawdataoRSC[i].push_back(j);    
 }     

rawdataMP7.resize(6*sizeof(tempVector));
 for(unsigned int i = 0; i<72; i++) {
    for(int j = 0; j < latencyMP7vsORSC; j++) rawdataMP7[i].push_back(0xFFFFFFFF);    
    for(int j = latencyMP7vsORSC; j < 1024; j++) rawdataMP7[i].push_back(j-latencyMP7vsORSC);    
 }     

CompareoRSCMP7Capture *compare=new CompareoRSCMP7Capture();
compare->SetoRSCPattern(bufferoRSC);
compare->SetoRSCBuffer(rawdataoRSC);
compare->SetMP7Buffer(rawdataMP7);

bool flag=compare->CompareoRSCPoke();
if(flag) std::cout<<"what you wrote in oRSC is what you captured in oRSC are consistent!!"<<std::endl;
else std::cout<<"ERROR! what you wrote in oRSC is what you captured in oRSC are NOT consistent!!"<<std::endl;
flag=compare->CompareoRSCMP7();
if(flag) std::cout<<"payload matches !!!"<<std::endl;
return 1; 

}


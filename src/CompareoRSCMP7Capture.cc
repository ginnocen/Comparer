#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>

#include "CompareoRSCMP7Capture.hh"
#include <unistd.h>
using namespace std;

// Constructor
  CompareoRSCMP7Capture::CompareoRSCMP7Capture(){
    
    bufferMP7.clear();
    bufferoRSC.clear();
    patternoRSC.clear();
    NlinksActiveoRSC=12;
    NlinksActiveMP7=12;
    offsetMP7=0;
    
  }

// Desstructor
CompareoRSCMP7Capture::~CompareoRSCMP7Capture()
{
}

bool CompareoRSCMP7Capture::GetoRSCBufferAtLink(int linkid,std::vector < unsigned int >&bufferatlinkoRSC){
  for(std::vector<unsigned int>::iterator it = bufferoRSC[linkid].begin(); it != bufferoRSC[linkid].end(); ++it) {
    bufferatlinkoRSC.push_back(*it);
  }
  return true;
}

bool CompareoRSCMP7Capture::GetMP7BufferAtLink(int linkid,std::vector < unsigned int >&bufferatlinkMP7){
  for(std::vector<unsigned int>::iterator it = bufferMP7[linkid].begin(); it != bufferMP7[linkid].end(); ++it) {
    bufferatlinkMP7.push_back(*it);
  }
  return true;
}

bool CompareoRSCMP7Capture::CompareoRSCPoke(){
  
  bool flag=true;
   for (int i=0;i<NLinksoRSC;i++){
     for (int j=0;j<NwordsInLink;j++){
      if (!((bufferoRSC[i][j]==patternoRSC[i][j]))) {
      //std::cout<<"ERROR, patternoRSC["<<i<<"]["<<j<<"] does not match with bufferMP7["<<i<<"]["<<j<<"]"<<std::endl;
      flag=false;}
     }
   }
  return flag;  
}


bool CompareoRSCMP7Capture::CompareoRSCMP7(){
  
  bool flag=true;  
  if(bufferoRSC[0][0]!=bufferMP7[0][0]) {
    cout<<"frame 0 oRSC does not corresponds to frame 0 MP7, looking for matching"<<endl;
  }
  else{cout<<"frame 0 oRSC does corresponds to frame 0 MP7"<<endl;}
  
  for (int i=0;i<NwordsInLink;i++){
    if(bufferMP7[0][i]==bufferoRSC[0][0]) {offsetMP7=i; cout<<"found corresponding word in frame="<<i<<endl;}
  }
  for (int i=0;i<NLinksForComparison;i++){
    if(!(bufferMP7[i][offsetMP7]==bufferoRSC[i][0])) { cout<<"MP7 links not aligned!!"<<endl; return false;}
  }
   
  cout<<"Checking for payload with offset="<<offsetMP7<<endl; 
    
  for (int i=0;i<NLinksForComparison;i++){
     for (int j=offsetMP7;j<NwordsInLink;j++){
      if (!((bufferoRSC[i][j-offsetMP7]==bufferMP7[i][j]))) {        
        std::cout<<"ERROR, patternoRSC["<<i<<"]["<<j<<"] does not match with bufferMP7["<<i<<"]["<<j<<"]"<<std::endl;
        flag=false;
       }
     }
   }
  return flag;
}



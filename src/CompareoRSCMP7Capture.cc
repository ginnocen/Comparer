#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>

#include "CompareoRSCMP7Capture.hh"
#include <unistd.h>

// Constructor
  CompareoRSCMP7Capture::CompareoRSCMP7Capture(){
    bufferMP7.clear();
    bufferoRSC.clear();
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

bool CompareoRSCMP7Capture::Compare(){
  
  bool flag=true;
   for (int i=0;i<NLinksoRSC;i++){
     for (int j=0;j<NwordsInLink;j++){
      if (!((bufferoRSC[i][j]==bufferMP7[i][j]))) {std::cout<<"wrong"<<std::endl; flag=false;}
     }
   }
  return flag;  
}


#ifndef CompareoRSCMP7Capture_hh
#define CompareoRSCMP7Capture_hh

using namespace std;

// Included classes

#include <vector>
#include <stdint.h>

#define NwordsInLink 1024
#define NLinksoRSC 23
#define NLinksMP7 72

#define NLinksForComparison 12


// Object to compare the payload of MP7 and oRSC

class CompareoRSCMP7Capture{
public:

  // Constructor
  CompareoRSCMP7Capture();
  // Destructor
  virtual ~CompareoRSCMP7Capture();
  int maplinkfromoRSCtoMP7(int);
  int maplinkfromMP7tooRSC(int);

  void SetoRSCPattern(const std::vector < std::vector < unsigned int > > &mypatternoRSC){
    patternoRSC.reserve(mypatternoRSC.size());
    copy(mypatternoRSC.begin(), mypatternoRSC.end(), patternoRSC.begin());
  }

  void SetoRSCBuffer(const std::vector < std::vector < unsigned int > > &mybufferoRSC){
    bufferoRSC.reserve(mybufferoRSC.size());
    copy(mybufferoRSC.begin(), mybufferoRSC.end(), bufferoRSC.begin());
  }
  
  void SetMP7Buffer(const std::vector < std::vector < unsigned int > > &mybufferMP7){
    bufferMP7.reserve(mybufferMP7.size());
    copy(mybufferMP7.begin(), mybufferMP7.end(), bufferMP7.begin());
  }
  
//  void SetActiveLinksMP7BitMask(const  std::vector < unsigned int > &linkmap){
//    activelinksMP7.reserve(linkmap.size());
//   copy(linkmap.begin(), linkmap.end(), activelinksMP7.begin());
//  }
  
//  void SetActiveLinksoRSCBitMask(const  std::vector < unsigned int > &linkmap){
//    activelinksoRSC.reserve(linkmap.size());
//    copy(linkmap.begin(), linkmap.end(), activelinksoRSC.begin());
//  }
  
  bool GetoRSCBufferAtLink(int linkid, std::vector < unsigned int >&);
  bool GetMP7BufferAtLink(int linkid, std::vector < unsigned int >&);
  int CheckoRSCBufferLinkAlignment();
  
  bool CompareoRSCPoke();
  bool CompareoRSCMP7();
  
protected:

private:
  // Local variables
  std::vector < std::vector < unsigned int > > patternoRSC;
  std::vector < std::vector < unsigned int > > bufferoRSC;
  std::vector < std::vector < unsigned int > > bufferMP7;

  int NlinksActiveoRSC;
  int NlinksActiveMP7;
  int offsetMP7;
  
  
  	
};

#endif



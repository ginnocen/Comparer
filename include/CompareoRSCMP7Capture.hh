#ifndef CompareoRSCMP7Capture_hh
#define CompareoRSCMP7Capture_hh

using namespace std;

// Included classes

#include <vector>
#include <stdint.h>

#define NwordsInLink 1024
#define NLinksoRSC 23
#define NLinksMP7 23


// Object to compare the payload of MP7 and oRSC

class CompareoRSCMP7Capture{
public:

  // Constructor
  CompareoRSCMP7Capture();
  // Destructor
  virtual ~CompareoRSCMP7Capture();
  int maplinkfromoRSCtoMP7(int);
  int maplinkfromMP7tooRSC(int);

  bool SetoRSCPattern(const std::vector < std::vector < unsigned int > > &mypatternoRSC){
    patternoRSC.reserve(mypatternoRSC.size());
    copy(mypatternoRSC.begin(), mypatternoRSC.end(), patternoRSC.begin());
  }

  bool SetoRSCBuffer(const std::vector < std::vector < unsigned int > > &mybufferoRSC){
    bufferoRSC.reserve(mybufferoRSC.size());
    copy(mybufferoRSC.begin(), mybufferoRSC.end(), bufferoRSC.begin());
  }
  
  bool SetMP7Buffer(const std::vector < std::vector < unsigned int > > &mybufferMP7){
    bufferMP7.reserve(mybufferMP7.size());
    copy(mybufferMP7.begin(), mybufferMP7.end(), bufferMP7.begin());
  }
    
  bool GetoRSCBufferAtLink(int linkid, std::vector < unsigned int >&);
  bool GetMP7BufferAtLink(int linkid, std::vector < unsigned int >&);
  bool Compare();
  
protected:

private:
  // Local variables
  std::vector < std::vector < unsigned int > > patternoRSC;
  std::vector < std::vector < unsigned int > > bufferoRSC;
  std::vector < std::vector < unsigned int > > bufferMP7;
  	
};

#endif



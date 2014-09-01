#include "rct/ts/workerCell/CelloRSCMP7Compare.h"
#include "ts/toolbox/CellToolbox.h"
#include "ts/framework/CellAbstractContext.h"
#include "ts/exception/CellException.h"
#include "rct/ts/workerCell/CellContext.h"
#include "xcept/tools.h"
#include <boost/lexical_cast.hpp>
#include <string>
#include <vector>
#include <sstream>
#include "toolbox/string.h"
#include "log4cplus/logger.h"
#include "xdata/xdata.h"

using namespace std;
using namespace log4cplus;

rcttsWorkerCell::CelloRSCMP7Compare::CelloRSCMP7Compare(Logger& log, tsframework::CellAbstractContext* context):tsframework::CellCommand(log,context)
{
  logger_ = Logger::getInstance(log.getName() +".CelloRSCMP7Compare");
  
  for (int i=0;i<10;i++){
    stringstream ss;
    ss << "Link" <<i;
    getParamList().insert(std::make_pair(ss.str(),new xdata::String("")));
  }
  
  CellContext* cell = dynamic_cast<CellContext*>(getContext());
  oRSCOp_ = cell->getoRSCOp();
}

rcttsWorkerCell::CelloRSCMP7Compare::~CelloRSCMP7Compare()
{
	
}



void rcttsWorkerCell::CelloRSCMP7Compare::code()
{ 
  const int NintsPerLink=1024;
  unsigned int array[NintsPerLink];
  std::vector < std::vector < unsigned int > > myvectorLink;
  std::vector<unsigned int> tempVector;
  tempVector.resize(sizeof(array));
  myvectorLink.resize(6*sizeof(tempVector));
  for(unsigned int i = 0; i<10; i++) myvectorLink[i].reserve(sizeof(array));

  unsigned int val; 
  for (int i=0;i<10;i++){
    stringstream sst;
    stringstream test;
    sst << "Link" <<i;
    string mystringLink = dynamic_cast<xdata::String*>(getParamList()[sst.str()])->toString();
    test<<mystringLink;
    //if (!mystringLink.empty()) payload_ = new xdata::String(test.str());   
    
    std::istringstream iss (mystringLink);
    for (int n=0; n<NintsPerLink; n++){
      iss >> val; 
      myvectorLink[i].push_back(val); 
    }
 }
 
   stringstream last;
   last << "Value addss" <<myvectorLink[3][888];
   payload_ = new xdata::String(last.str());   
   
   //LOG4CPLUS_INFO((logger_),  "test:"  << endl);

    //if(1) payload_ = new xdata::String("ALL larger version  affanculo2");
    //else payload_ = new xdata::String("b<0 TRIS!");
  
 }

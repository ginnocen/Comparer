#include "rct/ts/workerCell/CelloRSCMP7Compare.h"
#include "ts/toolbox/CellToolbox.h"
#include "ts/framework/CellAbstractContext.h"
#include "ts/exception/CellException.h"
#include "rct/ts/workerCell/CellContext.h"
#include "xcept/tools.h"
#include <boost/lexical_cast.hpp>
#include <string>
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
  
  std::vector < std::vector < unsigned int > > myvectorLink;
  int value;

  for (int i=0;i<10;i++){
    stringstream sst;
    sst << "Link" <<i;
    string mystringLink = getParamList()[sst.str()]->toString();
    istringstream issLink(mystringLink);
    
    while(issLink){
     issLink >> value;
     myvectorLink[i].push_back(value);
    }  
  }
    //LOG4CPLUS_INFO((logger_),  "test:"  << endl);

    if(1) payload_ = new xdata::String("ALL larger version  FFssFFF");
    else payload_ = new xdata::String("b<0 TRIS!");
  
 }

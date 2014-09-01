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

  for (int i=0;i<1;i++){
    stringstream sst;
    stringstream test;
    sst << "Link" <<i;
    string mystringLink = dynamic_cast<xdata::String*>(getParamList()[sst.str()])->toString();
    test<<mystringLink;
    if (!mystringLink.empty()) payload_ = new xdata::String(test.str());   
    
    std::istringstream iss (mystringLink);
    //for (int n=0; n<10; n++){int val; iss >> val; myvectorLink[i].push_back(val); }
    for (int n=0; n<10; n++){
      int val; 
      iss >> val; 
    }
 }
//    for (int n=0; n<1024; n++){
//      int val;
//      iss >> val;
//    }
//  }

    //LOG4CPLUS_INFO((logger_),  "test:"  << endl);

    //if(1) payload_ = new xdata::String("ALL larger version  affanculo2");
    //else payload_ = new xdata::String("b<0 TRIS!");
  
 }

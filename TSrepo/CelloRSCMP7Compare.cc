#include "rct/ts/workerCell/CelloRSCMP7Compare.h"
#include "ts/toolbox/CellToolbox.h"
#include "ts/framework/CellAbstractContext.h"
#include "ts/exception/CellException.h"
#include "rct/ts/workerCell/CellContext.h"
#include "xcept/tools.h"

#include <string>

#include "toolbox/string.h"
#include "log4cplus/logger.h"
#include "xdata/xdata.h"

using namespace std;
using namespace log4cplus;

rcttsWorkerCell::CelloRSCMP7Compare::CelloRSCMP7Compare(Logger& log, tsframework::CellAbstractContext* context):tsframework::CellCommand(log,context)
{
  logger_ = Logger::getInstance(log.getName() +".CelloRSCMP7Compare");

  getParamList().insert(std::make_pair("Link0",new xdata::String("")));
  //getParamList().insert(std::make_pair("Link1",new xdata::String("")));
  //getParamList().insert(std::make_pair("Link2",new xdata::String("")));
  //getParamList().insert(std::make_pair("Link3",new xdata::String("")));
    
  CellContext* cell = dynamic_cast<CellContext*>(getContext());
  oRSCOp_ = cell->getoRSCOp();
}

rcttsWorkerCell::CelloRSCMP7Compare::~CelloRSCMP7Compare()
{
	
}



void rcttsWorkerCell::CelloRSCMP7Compare::code()
{ 
  //xdata::Integer* nslots = dynamic_cast<xdata::Integer*>(getParamList()["Link0"]);
  string sPatternTestLink0 = dynamic_cast<xdata::String*>(getParamList()["Link0"])->toString();
  //string sPatternTestLink1 = dynamic_cast<xdata::String*>(getParamList()["Link1"])->toString();
  //string sPatternTestLink2 = dynamic_cast<xdata::String*>(getParamList()["Link2"])->toString();
  //string sPatternTestLink3 = dynamic_cast<xdata::String*>(getParamList()["Link3"])->toString();

  string mystringLink0 = getParamList()["Link0"]->toString();
  //string mystringLink1 = getParamList()["Link1"]->toString();
  //string mystringLink2 = getParamList()["Link2"]->toString();
  //string mystringLink3 = getParamList()["Link3"]->toString();

  
  istringstream issLink0(mystringLink0);
  //istringstream issLink1(mystringLink1);
  //istringstream issLink2(mystringLink2);
  //istringstream issLink3(mystringLink3);
        
  
  std::vector <int> myvectorLink0;
  //std::vector <int> myvectorLink1;
  //std::vector <int> myvectorLink2;
  //std::vector <int> myvectorLink3;
  
  int n0;//,n1,n2,n3;
  
  //iss >> a >> b >>c; 
  while (issLink0){
    issLink0 >> n0; 
    //issLink1 >> n1; 
    //issLink2 >> n2; 
    //issLink3 >> n3; 
    myvectorLink0.push_back(n0); 
    //myvectorLink0.push_back(n1); 
    //myvectorLink0.push_back(n2); 
    //myvectorLink0.push_back(n3); 
    
  }  	
    //LOG4CPLUS_INFO((logger_),  "test:"  << endl);

    if(myvectorLink0[0]>0) payload_ = new xdata::String("ALL larger than zero");
    else payload_ = new xdata::String("b<0!");
  
 }

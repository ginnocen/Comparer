#include "rct/ts/workerCell/CelloRSCMP7Compare.h"
#include "ts/toolbox/CellToolbox.h"
#include "ts/framework/CellAbstractContext.h"
#include "ts/exception/CellException.h"
#include "rct/ts/workerCell/CellContext.h"
#include "xcept/tools.h"
#include <boost/lexical_cast.hpp>

#include <string>
 
#include "toolbox/string.h"
#include "log4cplus/logger.h"
#include "xdata/xdata.h"

using namespace std;
using namespace log4cplus;

rcttsWorkerCell::CelloRSCMP7Compare::CelloRSCMP7Compare(Logger& log, tsframework::CellAbstractContext* context):tsframework::CellCommand(log,context)
{
  logger_ = Logger::getInstance(log.getName() +".CelloRSCMP7Compare");
  //std::string text ="Link";
  //std::ostringstream oss;
  //oss.c_str()
  //for (int i=0;i<4;i++) {
  //    oss << text << i;
  //getParamList().insert(std::make_pair(oss.str(),new xdata::String("")));
  //}
  getParamList().insert(std::make_pair("Link0",new xdata::String("")));
  getParamList().insert(std::make_pair("Link1",new xdata::String("")));
  getParamList().insert(std::make_pair("Link2",new xdata::String("")));
  getParamList().insert(std::make_pair("Link3",new xdata::String("")));
  getParamList().insert(std::make_pair("Link4",new xdata::String("")));
  getParamList().insert(std::make_pair("Link5",new xdata::String("")));
  getParamList().insert(std::make_pair("Link6",new xdata::String("")));
  getParamList().insert(std::make_pair("Link7",new xdata::String("")));
  getParamList().insert(std::make_pair("Link8",new xdata::String("")));
  getParamList().insert(std::make_pair("Link9",new xdata::String("")));

  CellContext* cell = dynamic_cast<CellContext*>(getContext());
  oRSCOp_ = cell->getoRSCOp();
}

rcttsWorkerCell::CelloRSCMP7Compare::~CelloRSCMP7Compare()
{
	
}



void rcttsWorkerCell::CelloRSCMP7Compare::code()
{ 
  string sPatternTestLink0 = dynamic_cast<xdata::String*>(getParamList()["Link0"])->toString();
  string sPatternTestLink1 = dynamic_cast<xdata::String*>(getParamList()["Link1"])->toString();
  string sPatternTestLink2 = dynamic_cast<xdata::String*>(getParamList()["Link2"])->toString();
  string sPatternTestLink3 = dynamic_cast<xdata::String*>(getParamList()["Link3"])->toString();
  string sPatternTestLink4 = dynamic_cast<xdata::String*>(getParamList()["Link4"])->toString();
  string sPatternTestLink5 = dynamic_cast<xdata::String*>(getParamList()["Link5"])->toString();
  string sPatternTestLink6 = dynamic_cast<xdata::String*>(getParamList()["Link6"])->toString();
  string sPatternTestLink7 = dynamic_cast<xdata::String*>(getParamList()["Link7"])->toString();
  string sPatternTestLink8 = dynamic_cast<xdata::String*>(getParamList()["Link8"])->toString();
  string sPatternTestLink9 = dynamic_cast<xdata::String*>(getParamList()["Link9"])->toString();


  string mystringLink0 = getParamList()["Link0"]->toString();
  string mystringLink1 = getParamList()["Link1"]->toString();
  string mystringLink2 = getParamList()["Link2"]->toString();
  string mystringLink3 = getParamList()["Link3"]->toString();
  string mystringLink4 = getParamList()["Link4"]->toString();
  string mystringLink5 = getParamList()["Link5"]->toString();
  string mystringLink6 = getParamList()["Link6"]->toString();
  string mystringLink7 = getParamList()["Link7"]->toString();
  string mystringLink8 = getParamList()["Link8"]->toString();
  string mystringLink9 = getParamList()["Link9"]->toString();  
  
  istringstream issLink0(mystringLink0);
  istringstream issLink1(mystringLink1);
  istringstream issLink2(mystringLink2);
  istringstream issLink3(mystringLink3);
  istringstream issLink4(mystringLink4);
  istringstream issLink5(mystringLink5);
  istringstream issLink6(mystringLink6);
  istringstream issLink7(mystringLink7);
  istringstream issLink8(mystringLink8);
  istringstream issLink9(mystringLink9);
  
  std::vector <int> myvectorLink0;
  std::vector <int> myvectorLink1;
  std::vector <int> myvectorLink2;
  std::vector <int> myvectorLink3;
  std::vector <int> myvectorLink4;
  std::vector <int> myvectorLink5;
  std::vector <int> myvectorLink6;
  std::vector <int> myvectorLink7;
  std::vector <int> myvectorLink8;
  std::vector <int> myvectorLink9;
 
  int n0,n1,n2,n3,n4,n5,n6,n7,n8,n9;
  
  //iss >> a >> b >>c; 
  while (issLink0 && issLink1 && issLink2 && issLink3 && issLink4 && issLink5 && issLink6 && issLink7 && issLink8 && issLink9){
    issLink0 >> n0; 
    issLink1 >> n1; 
    issLink2 >> n2; 
    issLink3 >> n3; 
    issLink4 >> n4; 
    issLink5 >> n5; 
    issLink6 >> n6; 
    issLink7 >> n7; 
    issLink8 >> n8; 
    issLink9 >> n9; 
    
    myvectorLink0.push_back(n0);     
    myvectorLink1.push_back(n1);     
    myvectorLink2.push_back(n2);     
    myvectorLink3.push_back(n3);     
    myvectorLink4.push_back(n4);     
    myvectorLink5.push_back(n5);     
    myvectorLink6.push_back(n6);     
    myvectorLink7.push_back(n7);     
    myvectorLink8.push_back(n8);     
    myvectorLink9.push_back(n9);     
  }  
    //LOG4CPLUS_INFO((logger_),  "test:"  << endl);

    if(myvectorLink0[0]>0&&myvectorLink1[0]>0&&myvectorLink2[0]>0&&myvectorLink3[0]>0&&myvectorLink4[0]>0) payload_ = new xdata::String("ALL larger version  sssss");
    else payload_ = new xdata::String("b<0 TRIS!");
  
 }

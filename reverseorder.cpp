#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reverseorder.h"

void reverse_order(std::string date1, std::string date2)
{
  //OPEN STREAM
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if(fin.fail()){
    std::cerr<<"File cannot be opened for reading."<<std::endl;
    exit(1);//This exits if the file can't be read
  }

  //GET RID OF FIRST LINE SINCE ITS HEADERS
  std::string junk;
  getline(fin,junk);

  //CREATE VARIABLES
  std::string thisDate;
  int MAX_SIZE=0;
  bool counting=false;
  double eastSt, eastEl,westSt,westEl;


  //GO THROUGH EACH LINE
  while(fin>>thisDate>>eastSt>>eastEl>>westSt>>westEl){
    fin.ignore(INT_MAX, '\n');
    if(thisDate==date1){
      counting=true;
    }
    if(counting==true){
      MAX_SIZE++;
    }
    if(thisDate==date2){
      counting=false;
      break;
    }
  }

  //CLOSE READER
  fin.close();
  
  //CREATE ARRAY FOR SPECIFIC DAYS
  std::string dates[MAX_SIZE];
  double elevations[MAX_SIZE];
  int index=0;

  //OPEN STREAM
  std::ifstream newFin("Current_Reservoir_Levels.tsv");
  if(newFin.fail()){
    std::cerr<<"File cannot be opened for reading."<<std::endl;
    exit(1);//This exits if the file can't be read
  }

  //GET RID OF FIRST LINE SINCE ITS HEADERS
  getline(newFin,junk);
  
  //GO THROUGH EACH LINE AGAIN
  while(newFin>>thisDate>>eastSt>>eastEl>>westSt>>westEl){
    newFin.ignore(INT_MAX, '\n');
    if(thisDate==date1){
      counting=true;
    }
    if(counting==true){
      dates[index]=thisDate;
      elevations[index]=westEl;
      index++;
    }
    if(thisDate==date2){
      counting=false;
      break;
    }
  }

  //CLOSE READER
  newFin.close();

  //FINALLY PRINT 
  for(int i=MAX_SIZE-1;i>=0;i--){
    std::cout<<dates[i]<<" "<<elevations[i]<<" ft\n";
  }
  
}


// add your code
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"

double get_east_storage(std::string date)
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
  double eastSt, eastEl,westSt,westEl,requestedStorage;


  //GO THROUGH EACH LINE
  while(fin>>thisDate>>eastSt>>eastEl>>westSt>>westEl){
    fin.ignore(INT_MAX, '\n');
    if(thisDate==date){
      requestedStorage=eastSt;
      break;
    }
  }

  //CLOSE AND RETURN REQUESTED STORAGED
  fin.close();
  return requestedStorage;
}

double get_min_east()
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
  double eastSt, eastEl,westSt,westEl,min;
  int count=0;

  //GO THROUGH EACH LINE
  while(fin>>thisDate>>eastSt>>eastEl>>westSt>>westEl){
    fin.ignore(INT_MAX, '\n');
    if(count==0){
      min=eastSt;
      count=1;
    }
    if(eastSt<min){
      min=eastSt;
    }
  }

  //CLOSE AND RETURN MIN
  fin.close();
  return min;
}

double get_max_east()
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
  double eastSt, eastEl,westSt,westEl,max;
  int count=0;

  //GO THROUGH EACH LINE
  while(fin>>thisDate>>eastSt>>eastEl>>westSt>>westEl){
    fin.ignore(INT_MAX, '\n');
    if(count==0){
      max=eastSt;
      count=1;
    }
    if(eastSt>max){
      max=eastSt;
    }
  }

  //CLOSE AND RETURN MAX
  fin.close();
  return max;
}

std::string compare_basins(std::string date)
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
  std::string thisDate,compareResult;
  double eastSt, eastEl,westSt,westEl;


  //GO THROUGH EACH LINE
  while(fin>>thisDate>>eastSt>>eastEl>>westSt>>westEl){
    if(thisDate==date){
      if(eastEl>westEl){
	compareResult="East";
      }
      else if(westEl>eastEl){
	compareResult="West";
      }
      else{
	compareResult="Equal";
      }
      break;
    }
  }

  //CLOSE AND RETURN RESULT OF COMPARISON
  fin.close();
  return compareResult;
}

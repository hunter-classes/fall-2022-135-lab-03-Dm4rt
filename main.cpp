// add your code as appropriate 
#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  double storage,min,max;
  std::string compared;

  std::cout<<"TASK A:\n";
  storage=get_east_storage("05/20/2018");
  std::cout<<"East basin storage: "<<storage<<" billion gallons\n";
  storage=get_east_storage("11/05/2018");
  std::cout<<"East basin storage: "<<storage<<" billion gallons\n";
  storage=get_east_storage("02/12/2018");
  std::cout<<"East basin storage: "<<storage<<" billion gallons\n";
  std::cout<<"\n";

  std::cout<<"TASK B:\n";
  min=get_min_east();
  std::cout<<"Minimum storage in east basin: "<<min<<" billion gallons\n";
  max=get_max_east();
  std::cout<<"Maximum storage in east basin: "<<max<<" billion gallons\n";
  std::cout<<"\n";

  std::cout<<"TASK C:\n";
  compared=compare_basins("02/14/2018");
  std::cout<<"The result is: "<<compared<<"\n";
  compared=compare_basins("07/10/2018");
  std::cout<<"The result is: "<<compared<<"\n";
  compared=compare_basins("10/21/2018");
  std::cout<<"The result is: "<<compared<<"\n";
  std::cout<<"\n";

  std::cout<<"TASK D:\n";
  reverse_order("05/29/2018","06/02/2018");
  std::cout<<"\n";
  reverse_order("04/12/2018","05/04/2018");

  
  return 0;
}

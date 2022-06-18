#include "kerangos.h"

int main(){

  Kerang kerang_obj;

  /* local variable */
  std::string y;

  /* kerang shell should pointed to Kerang.shell*/

  /* inputan mantap */
  std::cout<<"Kerang OS : Kerang Ajaib "<<std::endl;

#if DEBUG_MODE
  std::cout<<"Check "<<std::endl;
#endif

  /* main program */
  while(1)
    {
      std::cout<<kerang_obj.shell;
      getline(std::cin, y);
      std::cout<<"output : "<<y<<std::endl;
      kerang_obj.setShell(y);
      command(y);
    }
  
  return 0;

}

void Kerang::setShell(std::string cmd){

  /* default cmd */
  shell=cmd;
  shell=cmd+" > ";

}


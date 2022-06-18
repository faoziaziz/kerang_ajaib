#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<string.h>
#define DEBUG_MODE 1




void command(std::string cmd);

int main(){


  /* local variable */
  std::string y;

  /* inputan mantap */
  std::cout<<"Kerang OS : Kerang Ajaib "<<std::endl;

#if DEBUG_MODE
  std::cout<<"Check "<<std::endl;
#endif

  
  while(1)
    {
      std::cout<<"> ";
      getline(std::cin, y);
      std::cout<<"output : "<<y<<std::endl;
      command(y);
    }
  

  return 0;

}


void command(std::string cmd){

  /* bandingkan cmd dengan thread */
  std::string biasa_saja="pacar";


  if(cmd.compare(biasa_saja)==0){
    std::cout<<"I love you"<<std::endl;
  }
  

}

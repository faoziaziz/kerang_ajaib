#include<iostream>
#include<csignal>
#include<unistd.h>
#define MODE_DEBUG 0


void signalHandler(int signum){
  std::cout<<"INterupt signal ("<<signum<<") received.\n"<<std::endl;
  exit(signum);

}

void signalApapun(int signum){

  int k=0;
  std::cout<<"signal detected you must sleep"<<std::endl;
  while(++k){
    std::cout<<"printing "<<k<<std::endl;
    sleep(1);

    if(k==15){
      break;

    }
  }

}

int main(){
  int i=0;


  signal(SIGINT, signalHandler);
  signal(SIGUSR1, signalApapun);
#if MODE_DEBUG
  std::cout<<"saya mengerti "<<std::endl;
#endif
  std::cout<<"Saya ganteng"<<std::endl;

  while(++i){
    
    std::cout<<"Going to sleep "<<std::endl;
    if(i==3){
      raise(SIGUSR1);
    }

    if(i==10){
      raise(SIGINT);
    }
    sleep(1);

  }
  
  return 0; 
}

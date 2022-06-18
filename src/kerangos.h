#ifndef __KERANGOS_H
#define __KERANGOS_H

#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

#define DEBUG_MODE 1
#define MAX_THREAD 32

class Kerang {
 public:
  std::string shell="> ";
  void setShell(std::string cmd);
  
};

class CommandsList {
  public:
  std::string title;
  void fungsiCommands();

};


void *perform_work(void *argument);
void command(std::string cmd);
void runningBackground();
void json_test();
#endif

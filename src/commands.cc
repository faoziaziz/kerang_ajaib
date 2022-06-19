/*
  nama : Aziz Amerul Faozi
  deskripsi : ini file commands tester
*/

#include "kerangos.h"
#include <stdio.h>
#include <json.h>
#include <curl/curl.h>


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
void curl_test();

void runningBackground(){
  /* maybe called daemon */
  
}




void command(std::string cmd){
  /* bandingkan cmd dengan thread */
  std::string biasa_saja="set";


  /* detect space */
  if(cmd.compare(biasa_saja)==0){
    std::cout<<"I love you"<<std::endl;
  }

  json_test();
  curl_test();
}


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


void curl_test(){
  CURL *curl;
  CURLcode res;
  std::string readBuffer;

  curl=curl_easy_init();
  if(curl){
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    std::cout << readBuffer << std::endl;
  }
  
}

void json_test(){
  struct json_object *jobj;
  char *str = "{ \"msg-type\": [ \"0xdeadbeef\", \"irc log\" ], \
		\"msg-from\": { \"class\": \"soldier\", \"name\": \"Wixilav\" }, \
		\"msg-to\": { \"class\": \"supreme-commander\", \"name\": \"[Redacted]\" }, \
		\"msg-log\": [ \
			\"soldier: Boss there is a slight problem with the piece offering to humans\", \
			\"supreme-commander: Explain yourself soldier!\", \
			\"soldier: Well they don't seem to move anymore...\", \
			\"supreme-commander: Oh snap, I came here to see them twerk!\" \
			] \
		}";

  printf("str:\n---\n%s\n---\n\n", str);

  jobj = json_tokener_parse(str);
  printf("jobj from str:\n---\n%s\n---\n",
	 json_object_to_json_string_ext(jobj, JSON_C_TO_STRING_SPACED | JSON_C_TO_STRING_PRETTY));
}



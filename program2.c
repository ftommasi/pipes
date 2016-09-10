#include <unistd.h>
#include <stdio.h>


int main(int argc, char** argv){
  while(1){
    char buf[256];
    char* ret = fgets(buf,256,stdin);
    if(ret == NULL)
      break;
    printf("Program 2 got : %s\n",buf);
  }
}

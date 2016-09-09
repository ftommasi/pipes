#include <unistd.h>
#include <stdio.h>


int main(int argc, char** argv){
  while(1){
    char buf[256];
    fgets(buf,256,stdin);
    if(buf == NULL)
      break;
    printf("Program 2 got : %s\n",buf);
  }
}

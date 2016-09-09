#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv){

  int child_pid1 = fork();
  int child_pid2 = fork();
  if(child_pid1 != 0){
    waitpid(child_pid1,NULL,0);
  }
  
  else{
    //child 1 exec
    char** my_argv
    execvp("program1",);
  }
   if(child_pid2 != 0){
    waitpid(child_pid2,NULL,0);
  }
  
  else{
    //child 2 exec
  }
 


}

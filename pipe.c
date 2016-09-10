#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv){

  int fd[2];
  pipe(fd);

  int pid = fork();
  if(!pid){
    waitpid(pid,NULL,0);
  } else {
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    //child 1 exec
    char* cmd = "./program1";
    char* myargv[] = {"program1", '\0'};
    int ret = execvp( cmd, myargv );
    if( ret == -1 ) perror("Error exec'ing program1");
  }

  pid = fork();
  if(!pid){
    waitpid(pid,NULL,0);
  } else {
    dup2(fd[0], STDIN_FILENO);
    close(fd[1]);
    //child 2 exec
    char* cmd = "./program2";
    char* myargv[] = {"program2", '\0'};
    int ret = execvp( cmd, myargv );
    if( ret == -1 ) perror("Error exec'ing program2");
  }

  close(fd[1]);
  close(fd[0]);

  return 0;
}

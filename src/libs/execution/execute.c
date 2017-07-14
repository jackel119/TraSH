#include <execute.h>

int execute(char **tokens) {
  
  // Process IDs
  pid_t this_id, wpid;
  int status;

  this_id = fork();
  if (this_id == 0) {
    // Child process
    if (execvp(tokens[0], tokens) == -1) {
      fprintf(stderr, "Unknown Command: %s \n", tokens[0]);
    }
    exit(EXIT_FAILURE);
  } else if (this_id < 0) {
    // Error forking
    fprintf(stderr, "Process fork failed\n");
  } else {
    // Parent process
    do {
      wpid = waitpid(this_id, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;  

}

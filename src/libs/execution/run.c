#include <run.h>

void run(void) {

  // Read line
  char *line = read_line();

  // Tokenize
  char **tokens = tokenize(line);

  // Execute
  execute(tokens);

  // Free Memory
  free(tokens);
  free(line);
  
}

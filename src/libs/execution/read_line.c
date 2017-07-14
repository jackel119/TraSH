#include <read_line.h>

char* read_line(void) {
  int bufsize = STANDARD_LINE_BUFFER_SIZE;
  char *line = malloc(sizeof(char) * bufsize); 
  char current;
  int index = 0;

  while (1) {
    // Gets next char
    current = getchar();

    // Checks for end of line
    if (current == EOF || current == '\n'){
      line[index] = '\0';
      return line;
    } else {
      line[index] = current;
    }

    // Increments Index
    index++;

    // Checks if buffer size needs to be increased
    if (index >= bufsize) {
      bufsize += STANDARD_LINE_BUFFER_SIZE;
      line = realloc(line, bufsize);
      if (line == NULL) {
        fprintf(stderr, "Insufficient memory: failed to allocate space memory");
        exit(EXIT_FAILURE);
      }
    }
  }
}

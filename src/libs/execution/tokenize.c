#include <tokenize.h>

char** tokenize(char* line) {

  // Variables
  size_t bufsize = TOKEN_BUFFER_SIZE;
  char *saveptr;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;
  int token_index = 0;

  if (tokens == NULL) {
    fprintf(stderr, "Out of Memory: Failed to allocate more memory");
    exit(EXIT_FAILURE);
  }
  
  token = strtok_r(line, " ", &saveptr);
  while (token != NULL) {
    tokens[token_index] = token;
    token_index++;

    if (token_index >= bufsize) {
      bufsize += TOKEN_BUFFER_SIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (tokens == NULL) {
        fprintf(stderr, "Out of Memory: Failed to allocate more memory");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok_r(NULL, " ", &saveptr);
  }
  tokens[token_index] = NULL;
  return tokens;
}

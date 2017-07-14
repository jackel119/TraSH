#include <prompt.h>

void shell_prompt(void) {
  // User
  struct passwd *p = getpwuid(getuid());  // Check for NULL!

  // Hostname
  char *hostname = malloc(256);
  gethostname(hostname, 256);  // Check the return value!

  // Current Working Directory;
  char *dir = getcwd(NULL, 1024);
  if (p == NULL) {
    fprintf(stderr, "USER ID UNAVAILABLE\n");
    exit(EXIT_FAILURE);
  }
  printf("%s@%s~>%s$ ", p->pw_name, hostname,dir);
  // free(*p);
  free(hostname);
  free(dir);
}

#include <stdio.h>
#include <stdlib.h>
#include <trash.h>
#include <pwd.h>


int main(void) {
  // Load Config Files

  // Command Loop 
  while (1) {
    shell_prompt();
    run();
  }


  return EXIT_SUCCESS;
}

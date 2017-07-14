#ifndef _execute
#define _execute

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pwd.h>

int execute(char **tokens);

#endif


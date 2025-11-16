#ifndef GNL
# define GNL
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
char *get_next_line(int fd);
# endif
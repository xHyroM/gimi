#include "../cli.h"
#include <errno.h>
#include <linux/limits.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define INIT_CONFIG "[providers]\n"

void cli_command_init(int argc, char **argv) {
  errno = 0;
  int ret = mkdir(".gimi", S_IRWXU);
  if (ret == -1 && errno != EEXIST) {
    printf("Failed to initialize gimi.\n");
    return;
  }

  char cwd[PATH_MAX];
  if (getcwd(cwd, sizeof(cwd)) == NULL) {
    printf("Failed to get current working directory.\n");
  }
  printf("Initialized gimi in %s/.gimi\n", cwd);

  FILE *file_ptr;
  file_ptr = fopen(".gimi/config.toml", "w");

  fprintf(file_ptr, INIT_CONFIG);
  fclose(file_ptr);
}
#include "../../config.h"
#include "../cli.h"
#include <stdio.h>

#define INIT_CONFIG "[providers]\n"

void cli_command_config(int argc, char **argv) {
  gimi_config *cfg = config_read();
  for (int i = 0; i < cfg->providers_size; i++) {
    gimi_config_provider *provider = cfg->providers[i];
    printf("ssh: %s | primary: %d\n", provider->ssh, provider->primary);
  }
}
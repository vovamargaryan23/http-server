#include <stdio.h>
#include "config/parser.h"

Config get_server_config(int use_default_config, char *file_path)
{
    Config config;

    if (use_default_config)
    {
        config = config_defaults;
    }
    else
    {
        config = parse_file(file_path);
    }

    return config;
}

int main()
{
    int use_default_config = 0;
    Config config = get_server_config(use_default_config, "../test.conf");
    printf("%s\n", config.server_ip);
    printf("%i\n", config.server_port);
    return 0;
}
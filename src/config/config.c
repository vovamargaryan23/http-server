#include "config/config.h"
#include "config/validation.h"

void set_server_ip(Config *config, const char *server_ip)
{
    if (!is_ip_address_valid(server_ip))
    {
        fprintf(stderr, "Invalid ip address specified in config file!\n");
        exit(-1);
    }
    strncpy(config->server_ip, server_ip, MAX_IP_ADDR_LENGTH - 1);
    config->server_ip[MAX_IP_ADDR_LENGTH - 1] = '\0';
}

void set_server_port(Config *config, const char *server_port)
{
    int val = atoi((char *)server_port);
    if (!is_port_valid(val))
    {
        fprintf(stderr, "Invalid port number specified in config file!\n");
        exit(-1);
    }

    config->server_port = (unsigned short)val;
}
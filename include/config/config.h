#ifndef CONFIG_H
#define CONFIG_H
#include <regex.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_IP_ADDR_LENGTH 16

typedef struct
{
    char server_ip[MAX_IP_ADDR_LENGTH - 1];
    unsigned short server_port;

} Config;

typedef void (*handler_fnc)(Config *, const char *);

typedef struct
{
    char *key;
    handler_fnc value;

} ConfigEntry;

void set_server_ip(Config *config, const char *server_ip);
void set_server_port(Config *config, const char *server_port);

static const ConfigEntry entries[] = {
    {"server_ip", set_server_ip},
    {"server_port", set_server_port}};

static const int ENTRIES_SIZE = sizeof(entries) / sizeof(ConfigEntry);

static Config config_defaults = {"127.0.0.1", 8000};

#endif
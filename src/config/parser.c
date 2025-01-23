#include "config/parser.h"

#define MAX_LINE_SIZE 256

void _trim_string(char *str)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isspace((unsigned char)str[i]))
        {
            str[j++] = str[i];
        }
    }

    str[j] = '\0';
}

const ConfigEntry *_get_from_config_entries(const char *key)
{
    for (int i = 0; i < ENTRIES_SIZE; i++)
    {
        if (strcmp(entries[i].key, key) == 0)
            return &entries[i];
    }

    return NULL;
}

Config parse_file(const char *file_path)
{
    FILE *file_ptr = fopen(file_path, "r");

    if (file_ptr == NULL)
    {
        fprintf(stderr, "Failed to open configuration File, exiting!");
        exit(-1);
    }

    Config config = config_defaults;

    char line[MAX_LINE_SIZE];

    while (fgets(line, MAX_LINE_SIZE, file_ptr))
    {
        _trim_string(line);
        if (line[0] == '#' || line[0] == ';' || line[0] == '\0' || line[0] == '\n')
            continue;

        char *param_key = strtok(line, "=");
        void *param_value = strtok(NULL, "\n");

        const ConfigEntry *entry = _get_from_config_entries(param_key);
        if (entry != NULL)
        {
            handler_fnc fnc = entry->value;
            fnc(&config, param_value);
        }
    }

    fclose(file_ptr);

    return config;
}
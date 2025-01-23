#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "config/config.h"

#define READ_LINE_SIZE 256

Config parse_file(const char *file_path);

#endif
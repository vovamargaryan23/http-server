#ifndef VALIDATION_H
#define VALIDATION_H
#include <unistd.h>
#include <regex.h>

int is_ip_address_valid(const char *ip_address);
int is_port_valid(int port);
#endif
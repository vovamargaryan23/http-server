#include "config/validation.h"

int is_ip_address_valid(const char *ip_address)
{
    const char *ip_pattern = "^([0-9]|[1-9][0-9]|1([0-9][0-9])|2([0-4][0-9]|5[0-5]))."
                             "([0-9]|[1-9][0-9]|1([0-9][0-9])|2([0-4][0-9]|5[0-5]))."
                             "([0-9]|[1-9][0-9]|1([0-9][0-9])|2([0-4][0-9]|5[0-5]))."
                             "([0-9]|[1-9][0-9]|1([0-9][0-9])|2([0-4][0-9]|5[0-5]))$";
    regex_t regex;

    int is_invalid = regcomp(&regex, ip_pattern, REG_EXTENDED | REG_NOSUB);
    is_invalid = regexec(&regex, ip_address, 0, NULL, 0);
    return !is_invalid;
}

int is_port_valid(int port)
{
    return port >= 1 && port <= 65535;
}
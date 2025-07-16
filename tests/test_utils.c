#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <string.h>

static inline const char* extract_function_name(const char* path) {
    const char* last_slash = strrchr(path, '/');
    if (!last_slash) last_slash = strrchr(path, '\\');
    const char* filename = last_slash ? last_slash + 1 : path;

    static char function_name[256];
    strncpy(function_name, filename, sizeof(function_name) - 1);
    function_name[sizeof(function_name) - 1] = '\0';

    char* dot = strchr(function_name, '.');
    if (dot) *dot = '\0';

    if (strncmp(function_name, "test_", 5) == 0)
        return function_name + 5;
    return function_name;
}

#endif

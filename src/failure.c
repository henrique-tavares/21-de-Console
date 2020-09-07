#include "../headers/failure.h"

void is_null_failure(void *ptr, const char *msg)
{
    if (!ptr)
    {
        wprintf(L"%s", msg);
        exit(EXIT_FAILURE);
    }
}
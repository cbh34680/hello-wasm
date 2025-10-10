// UTF-8N CRLF
#include <emscripten.h>
#include <cstdio>
#include <cstdarg>

extern "C"
void log_impl(const char* format...)
{
    va_list args1;

    va_start(args1, format);
    vprintf(format, args1);
    va_end(args1);
}

// EOF
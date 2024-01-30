#pragma once
#include "backend.h"
#include <stdarg.h>

#ifndef NDEBUG
void g_log_write_event(const char *fmt, const char* filename, const char* source, int line, ...);

#define g_write_log(format, ...) \
	g_log_write_event(format, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)

#else
#define g_write_log(format, ...)
#endif

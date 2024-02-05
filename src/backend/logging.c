#include "logging.h"

#ifndef NDEBUG
void g_log_write_event(const char *fmt, const char* filename, const char* source, int line, ...) {
	va_list ap, ap2;
	va_start(ap, line);
	va_start(ap2, line);

	int length = vsnprintf(NULL, 0, fmt, ap) + 1;
	va_end(ap);

	char *buffer = calloc(length, sizeof(char));
	vsnprintf(buffer, length, fmt, ap2);

	printf("%-32s | %-3d | %-20s | %s\n", filename, line, source, buffer);
	free(buffer);
}

#define g_write_log(format, ...) \
	g_log_write_event(format, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)

#else
#define g_write_log(format, ...)
#endif

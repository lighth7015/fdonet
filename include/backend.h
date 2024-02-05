#pragma once
#include <sys/stat.h>

#include <stdlib.h>
#include <stdarg.h>

#include <string.h>
#include <stdint.h>

#include <inttypes.h>
#include <stdint.h>

#include <libgen.h>
#include <stdio.h>

#define PACKED __attribute__ ((packed))

#include "utils/list.h"
#include "utils/segment.h"
#include "logging.h"
#include "hexdump.h"
#include "crc.h"
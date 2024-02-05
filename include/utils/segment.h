#pragma once
#include "backend.h"

//
// HELPER: Segment type(s)
// Used for ad-hoc breaking apart integer data
//
typedef union st16_t {
	struct {
		uint8_t hi, lo;
	};

	uint16_t value;
} st16;

typedef union st32_t {
	struct {
		uint8_t hi1, lo1, hi2, lo2;
		uint16_t whi, wlo;
	};
	uint32_t value;
} st32;

typedef union st64_t {
	struct {
		uint8_t		hi1, lo1,	// first uint16_t
					hi2, lo2,	// second uint16_t
					hi3, lo3,	// third uint16_t
					hi4, lo4;	// fourth uint16_t

		uint16_t	whi1, wlo1,
					whi2, wlo2;

		uint32_t	dwhi, dwlo;
	};

	uint64_t value;
} st64;

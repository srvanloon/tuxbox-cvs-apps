/*
 * $Id: time_date_section.cpp,v 1.3 2005/10/29 00:10:17 obi Exp $
 *
 * Copyright (C) 2002-2005 Andreas Oberritter <obi@saftware.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation.
 *
 * See the file 'COPYING' in the top level directory for details.
 */

#include <dvbsi++/byte_stream.h>
#include <dvbsi++/time_date_section.h>

TimeAndDateSection::TimeAndDateSection(const uint8_t * const buffer) : ShortSection(buffer)
{
	utcTimeMjd = UINT16(&buffer[3]);
	utcTimeBcd = (buffer[5] << 16) | UINT16(&buffer[6]);
}

uint16_t TimeAndDateSection::getUtcTimeMjd(void) const
{
	return utcTimeMjd;
}

uint32_t TimeAndDateSection::getUtcTimeBcd(void) const
{
	return utcTimeBcd;
}


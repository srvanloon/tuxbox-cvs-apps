/*
 * $Id: tdt.cpp,v 1.2 2003/08/20 22:47:35 obi Exp $
 *
 * Copyright (C) 2002, 2003 Andreas Oberritter <obi@saftware.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#include <dvb/byte_stream.h>
#include <dvb/table/tdt.h>

TimeAndDateTable::TimeAndDateTable(const uint8_t * const buffer) : ShortTable(buffer)
{
	utcTimeMjd = UINT16(&buffer[3]);
	utcTimeBcd = (buffer[5] << 16) | UINT16(&buffer[6]);
}

uint16_t TimeAndDateTable::getUtcTimeMjd(void) const
{
	return utcTimeMjd;
}

uint32_t TimeAndDateTable::getUtcTimeBcd(void) const
{
	return utcTimeBcd;
}


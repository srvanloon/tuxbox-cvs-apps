/*
 * $Id: bat.cpp,v 1.3 2003/08/20 22:47:35 obi Exp $
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
#include <dvb/table/bat.h>

BouquetAssociation::BouquetAssociation(const uint8_t * const buffer)
{
	transportStreamId = UINT16(&buffer[0]);
	originalNetworkId = UINT16(&buffer[2]);
	transportStreamLoopLength = DVB_LENGTH(&buffer[4]);

	for (uint16_t i = 6; i < transportStreamLoopLength + 6; i += buffer[i + 1] + 2)
		descriptor(&buffer[i]);
}

BouquetAssociationTable::BouquetAssociationTable(const uint8_t * const buffer) : LongCrcTable(buffer)
{
	bouquetDescriptorsLength = DVB_LENGTH(&buffer[8]);

	for (uint16_t i = 10; i < bouquetDescriptorsLength + 10; i += buffer[i + 1] + 2)
		descriptor(&buffer[i]);

	transportStreamLoopLength = DVB_LENGTH(&buffer[bouquetDescriptorsLength + 10]);

	for (uint16_t i = bouquetDescriptorsLength + 12; i < sectionLength - 1; i += DVB_LENGTH(&buffer[i + 4]) + 6)
		bouquet.push_back(new BouquetAssociation(&buffer[i]));
}

BouquetAssociationTable::~BouquetAssociationTable(void)
{
	for (BouquetAssociationIterator i = bouquet.begin(); i != bouquet.end(); ++i)
		delete *i;
}


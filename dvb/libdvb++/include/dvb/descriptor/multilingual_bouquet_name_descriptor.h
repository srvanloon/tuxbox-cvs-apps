/*
 * $Id: multilingual_bouquet_name_descriptor.h,v 1.1 2003/07/17 01:07:14 obi Exp $
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

#ifndef __dvb_descriptor_multilingual_bouquet_name_descriptor_h__
#define __dvb_descriptor_multilingual_bouquet_name_descriptor_h__

#include "descriptor.h"

class MultilingualBouquetName
{
	protected:
		std::string iso639LanguageCode;
		unsigned bouquetNameLength			: 8;
		std::string bouquetName;

	public:
		MultilingualBouquetName(const uint8_t * const buffer);

		std::string getIso639LanguageCode(void) const;
		std::string getBouquetName(void) const;
};

typedef std::vector<MultilingualBouquetName *> MultilingualBouquetNameVector;
typedef MultilingualBouquetNameVector::iterator MultilingualBouquetNameIterator;
typedef MultilingualBouquetNameVector::const_iterator MultilingualBouquetNameConstIterator;

class MultilingualBouquetNameDescriptor : public Descriptor
{
	protected:
		MultilingualBouquetNameVector multilingualBouquetNames;

	public:
		MultilingualBouquetNameDescriptor(const uint8_t * const buffer);
		~MultilingualBouquetNameDescriptor(void);

		const MultilingualBouquetNameVector *getMultilingualBouquetNames(void) const;
};

#endif /* __dvb_descriptor_multilingual_bouquet_name_descriptor_h__ */

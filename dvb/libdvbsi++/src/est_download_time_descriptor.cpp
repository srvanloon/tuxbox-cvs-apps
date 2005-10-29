/*
 * $Id: est_download_time_descriptor.cpp,v 1.2 2005/10/29 00:10:16 obi Exp $
 *
 * Copyright (C) 2004-2005 St�phane Est�-Gracias <sestegra@free.fr>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation.
 *
 * See the file 'COPYING' in the top level directory for details.
 */

#include <dvbsi++/est_download_time_descriptor.h>
#include <dvbsi++/byte_stream.h>

EstDownloadTimeDescriptor::EstDownloadTimeDescriptor(const uint8_t * const buffer) : Descriptor(buffer)
{
	estDownloadTime = r32(&buffer[2]);
}

uint32_t EstDownloadTimeDescriptor::getEstDownloadTime(void) const
{
	return estDownloadTime;
}

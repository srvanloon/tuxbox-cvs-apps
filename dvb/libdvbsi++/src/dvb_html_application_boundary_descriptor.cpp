/*
 * $Id: dvb_html_application_boundary_descriptor.cpp,v 1.2 2005/10/29 00:10:16 obi Exp $
 *
 * Copyright (C) 2004-2005 St�phane Est�-Gracias <sestegra@free.fr>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation.
 *
 * See the file 'COPYING' in the top level directory for details.
 */

#include <dvbsi++/dvb_html_application_boundary_descriptor.h>

DvbHtmlApplicationBoundaryDescriptor::DvbHtmlApplicationBoundaryDescriptor(const uint8_t * const buffer) : Descriptor(buffer)
{
	labelLength = buffer[2];
	label.assign((char *)&buffer[3], labelLength);
	regularExpression.assign((char *)&buffer[labelLength + 3], descriptorLength - labelLength - 1);
}

const std::string &DvbHtmlApplicationBoundaryDescriptor::getLabel(void) const
{
	return label;
}

const std::string &DvbHtmlApplicationBoundaryDescriptor::getRegularExpression(void) const
{
	return regularExpression;
}

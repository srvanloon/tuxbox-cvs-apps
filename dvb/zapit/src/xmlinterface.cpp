/*
 * $Header: /cvs/tuxbox/apps/dvb/zapit/src/Attic/xmlinterface.cpp,v 1.26 2005/06/19 14:34:21 barf Exp $
 *
 * xmlinterface for zapit - d-box2 linux project
 *
 * (C) 2002 by thegoodguy <thegoodguy@berlios.de>
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

#include <cstdio>

#include <zapit/debug.h>
#include <zapit/xmlinterface.h>

#ifdef USE_LIBXML
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#else  /* USE_LIBXML */
#include <xmltok.h>
#endif /* USE_LIBXML */


unsigned long xmlGetNumericAttribute(const xmlNodePtr node, char *name, const int base)
{
	char *ptr = xmlGetAttribute(node, name);

	if (!ptr)
		return 0;

	return strtoul(ptr, 0, base);
}

long xmlGetSignedNumericAttribute(const xmlNodePtr node, char *name, const int base)
{
	char *ptr = xmlGetAttribute(node, name);

	if (!ptr)
		return 0;

	return strtol(ptr, 0, base);
}

xmlNodePtr xmlGetNextOccurence(xmlNodePtr cur, const char * s)
{
	while ((cur != NULL) && (strcmp(xmlGetName(cur), s) != 0))
		cur = cur->xmlNextNode;
	return cur;
}


std::string Unicode_Character_to_UTF8(const int character)
{
#ifdef USE_LIBXML
	xmlChar buf[5];
	int length = xmlCopyChar(4, buf, character);
	return std::string((char*)buf, length);
#else  /* USE_LIBXML */
	char buf[XML_UTF8_ENCODE_MAX];
	int length = XmlUtf8Encode(character, buf);
	return std::string(buf, length);
#endif /* USE_LIBXML */
}

#ifdef USE_LIBXML
xmlDocPtr parseXmlFile(const char * filename, bool warning_by_nonexistence /* = true */)
{
	xmlDocPtr doc;
	xmlNodePtr cur;
	
	doc = xmlParseFile(filename);

	if (doc == NULL)
	{
		WARN("Error parsing \"%s\"", filename);
		return NULL;
	}
	else
	{
		cur = xmlDocGetRootElement(doc);
		if (cur == NULL)
		{
			WARN("Empty document\n");
			xmlFreeDoc(doc);
			return NULL;
		}
		else
			return doc;
	}
}
#else /* USE_LIBXML */
xmlDocPtr parseXmlFile(const char * filename, bool warning_by_nonexistence /* = true */)
{
	char buffer[2048];
	XMLTreeParser* tree_parser;
	size_t done;
	size_t length;
	FILE* xml_file;

	xml_file = fopen(filename, "r");

	if (xml_file == NULL)
	{
	        if (warning_by_nonexistence)
			perror(filename);
		return NULL;
	}

	tree_parser = new XMLTreeParser(NULL);

	do
	{
		length = fread(buffer, 1, sizeof(buffer), xml_file);
		done = length < sizeof(buffer);

		if (!tree_parser->Parse(buffer, length, done))
		{
			WARN("Error parsing \"%s\": %s at line %d",
			       filename,
			       tree_parser->ErrorString(tree_parser->GetErrorCode()),
			       tree_parser->GetCurrentLineNumber());

			fclose(xml_file);
			delete tree_parser;
			return NULL;
		}
	}
	while (!done);

	fclose(xml_file);

	if (!tree_parser->RootNode())
	{
		delete tree_parser;
		return NULL;
	}
	return tree_parser;
}
#endif /* USE_LIBXML */

#include <lib/base/estring.h>
#include <ctype.h>
#include <limits.h>
#include <lib/system/elock.h>

static pthread_mutex_t lock=PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP;

///////////////////////////////////////// eString sprintf /////////////////////////////////////////////////
eString& eString::sprintf(char *fmt, ...)
{
	singleLock s(lock);
// Implements the normal sprintf method, to use format strings with eString
// The max length of the result string is 1024 char.
	static char buf[1024];
	va_list ap;
	va_start(ap, fmt);
	std::vsnprintf(buf, 1024, fmt, ap);
	va_end(ap);
	assign(buf);
	return *this;
}

///////////////////////////////////////// eString setNum(uint, uint) ///////////////////////////////////////
eString& eString::setNum(int val, int sys)
{
//	Returns a string that contain the value val as string
//	if sys == 16 than hexadezimal if sys == 10 than decimal
	char buf[12];

	if (sys == 10)
		std::snprintf(buf, 12, "%i", val);
	else if (sys == 16)
		std::snprintf(buf, 12, "%X", val);		
	
	assign(buf);
	return *this;
}

///////////////////////////////////////// eString replaceChars(char, char) /////////////////////////////
eString& eString::removeChars(char fchar)
{
//	Remove all chars that equal to fchar, and returns a reference to itself
	unsigned int index=0;

	while ( ( index = find(fchar, index) ) != npos )
		erase(index, 1);

	return *this;
}

/////////////////////////////////////// eString upper() ////////////////////////////////////////////////
eString& eString::upper()
{
//	convert all lowercase characters to uppercase, and returns a reference to itself
	for (iterator it = begin(); it != end(); it++)
		switch(*it)
		{
			case 'a' ... 'z' :
				*it -= 32;
			break;

			case '�' :
				*it = '�';
			break;
			
			case '�' :
				*it = '�';
			break;
			
			case '�' :
				*it = '�';
			break;
		}

	return *this;
}

eString& eString::strReplace(const char* fstr, const eString& rstr)
{
//	replace all occurrence of fstr with rstr and, and returns a reference to itself
	unsigned int index=0;
	unsigned int fstrlen = strlen(fstr);
	int rstrlen=rstr.size();

	while ( ( index = find(fstr, index) ) != npos )
	{
		replace(index, fstrlen, rstr);
		index+=rstrlen;
	}
	
	return *this;
}

int strnicmp(const char *s1, const char *s2, int len)
{
//	makes a case insensitive string compare with len Chars
	while ( *s1 && *s2 && len-- )
		if ( tolower(*s1) != tolower(*s2) )
			return tolower(*s1) < tolower(*s2) ? -1 : 1;
		else
			s1++, s2++;

	return 0;
}

/////////////////////////////////////// eString icompare(const eString&) ////////////////////////////////////////////////
int eString::icompare(const eString& s)
{
//	makes a case insensitive string compare
	std::string::const_iterator p = begin(),
															p2 = s.begin();

	while ( p != end() && p2 != s.end() )
		if ( tolower(*p) != tolower(*p2) )
			return tolower(*p) < tolower(*p2) ? -1 : 1;
		else
			p++, p2++;

	return length() == s.length() ? 0 : length() < s.length() ? -1 : 1;
}

		// 8859-x to dvb coding tables. taken from www.unicode.org/Public/MAPPINGS/ISO8859/
static unsigned long c88595[128]={
0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087, 0x0088, 0x0089, 0x008a, 0x008b, 0x008c, 0x008d, 0x008e, 0x008f, 
0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097, 0x0098, 0x0099, 0x009a, 0x009b, 0x009c, 0x009d, 0x009e, 0x009f, 
0x00a0, 0x0401, 0x0402, 0x0403, 0x0404, 0x0405, 0x0406, 0x0407, 0x0408, 0x0409, 0x040a, 0x040b, 0x040c, 0x00ad, 0x040e, 0x040f, 
0x0410, 0x0411, 0x0412, 0x0413, 0x0414, 0x0415, 0x0416, 0x0417, 0x0418, 0x0419, 0x041a, 0x041b, 0x041c, 0x041d, 0x041e, 0x041f, 
0x0420, 0x0421, 0x0422, 0x0423, 0x0424, 0x0425, 0x0426, 0x0427, 0x0428, 0x0429, 0x042a, 0x042b, 0x042c, 0x042d, 0x042e, 0x042f, 
0x0430, 0x0431, 0x0432, 0x0433, 0x0434, 0x0435, 0x0436, 0x0437, 0x0438, 0x0439, 0x043a, 0x043b, 0x043c, 0x043d, 0x043e, 0x043f, 
0x0440, 0x0441, 0x0442, 0x0443, 0x0444, 0x0445, 0x0446, 0x0447, 0x0448, 0x0449, 0x044a, 0x044b, 0x044c, 0x044d, 0x044e, 0x044f, 
0x2116, 0x0451, 0x0452, 0x0453, 0x0454, 0x0455, 0x0456, 0x0457, 0x0458, 0x0459, 0x045a, 0x045b, 0x045c, 0x00a7, 0x045e, 0x045f};

static unsigned long c88596[128]={
0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087, 0x0088, 0x0089, 0x008a, 0x008b, 0x008c, 0x008d, 0x008e, 0x008f, 
0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097, 0x0098, 0x0099, 0x009a, 0x009b, 0x009c, 0x009d, 0x009e, 0x009f, 
0x00a0, 0x0000, 0x0000, 0x0000, 0x00a4, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x060c, 0x00ad, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x061b, 0x0000, 0x0000, 0x0000, 0x061f, 
0x0000, 0x0621, 0x0622, 0x0623, 0x0624, 0x0625, 0x0626, 0x0627, 0x0628, 0x0629, 0x062a, 0x062b, 0x062c, 0x062d, 0x062e, 0x062f, 
0x0630, 0x0631, 0x0632, 0x0633, 0x0634, 0x0635, 0x0636, 0x0637, 0x0638, 0x0639, 0x063a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0640, 0x0641, 0x0642, 0x0643, 0x0644, 0x0645, 0x0646, 0x0647, 0x0648, 0x0649, 0x064a, 0x064b, 0x064c, 0x064d, 0x064e, 0x064f, 
0x0650, 0x0651, 0x0652, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000};

static unsigned long c88597[128]={
0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087, 0x0088, 0x0089, 0x008a, 0x008b, 0x008c, 0x008d, 0x008e, 0x008f, 
0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097, 0x0098, 0x0099, 0x009a, 0x009b, 0x009c, 0x009d, 0x009e, 0x009f, 
0x00a0, 0x2018, 0x2019, 0x00a3, 0x0000, 0x0000, 0x00a6, 0x00a7, 0x00a8, 0x00a9, 0x0000, 0x00ab, 0x00ac, 0x00ad, 0x0000, 0x2015, 
0x00b0, 0x00b1, 0x00b2, 0x00b3, 0x0384, 0x0385, 0x0386, 0x00b7, 0x0388, 0x0389, 0x038a, 0x00bb, 0x038c, 0x00bd, 0x038e, 0x038f, 
0x0390, 0x0391, 0x0392, 0x0393, 0x0394, 0x0395, 0x0396, 0x0397, 0x0398, 0x0399, 0x039a, 0x039b, 0x039c, 0x039d, 0x039e, 0x039f, 
0x03a0, 0x03a1, 0x0000, 0x03a3, 0x03a4, 0x03a5, 0x03a6, 0x03a7, 0x03a8, 0x03a9, 0x03aa, 0x03ab, 0x03ac, 0x03ad, 0x03ae, 0x03af, 
0x03b0, 0x03b1, 0x03b2, 0x03b3, 0x03b4, 0x03b5, 0x03b6, 0x03b7, 0x03b8, 0x03b9, 0x03ba, 0x03bb, 0x03bc, 0x03bd, 0x03be, 0x03bf, 
0x03c0, 0x03c1, 0x03c2, 0x03c3, 0x03c4, 0x03c5, 0x03c6, 0x03c7, 0x03c8, 0x03c9, 0x03ca, 0x03cb, 0x03cc, 0x03cd, 0x03ce, 0x0000};

static unsigned long c88598[128]={
0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087, 0x0088, 0x0089, 0x008a, 0x008b, 0x008c, 0x008d, 0x008e, 0x008f, 
0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097, 0x0098, 0x0099, 0x009a, 0x009b, 0x009c, 0x009d, 0x009e, 0x009f, 
0x00a0, 0x0000, 0x00a2, 0x00a3, 0x00a4, 0x00a5, 0x00a6, 0x00a7, 0x00a8, 0x00a9, 0x00d7, 0x00ab, 0x00ac, 0x00ad, 0x00ae, 0x00af, 
0x00b0, 0x00b1, 0x00b2, 0x00b3, 0x00b4, 0x00b5, 0x00b6, 0x00b7, 0x00b8, 0x00b9, 0x00f7, 0x00bb, 0x00bc, 0x00bd, 0x00be, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2017, 
0x05d0, 0x05d1, 0x05d2, 0x05d3, 0x05d4, 0x05d5, 0x05d6, 0x05d7, 0x05d8, 0x05d9, 0x05da, 0x05db, 0x05dc, 0x05dd, 0x05de, 0x05df, 
0x05e0, 0x05e1, 0x05e2, 0x05e3, 0x05e4, 0x05e5, 0x05e6, 0x05e7, 0x05e8, 0x05e9, 0x05ea, 0x0000, 0x0000, 0x200e, 0x200f, 0x0000};

static unsigned long c88599[128]={
0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087, 0x0088, 0x0089, 0x008a, 0x008b, 0x008c, 0x008d, 0x008e, 0x008f, 
0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097, 0x0098, 0x0099, 0x009a, 0x009b, 0x009c, 0x009d, 0x009e, 0x009f, 
0x00a0, 0x00a1, 0x00a2, 0x00a3, 0x00a4, 0x00a5, 0x00a6, 0x00a7, 0x00a8, 0x00a9, 0x00aa, 0x00ab, 0x00ac, 0x00ad, 0x00ae, 0x00af, 
0x00b0, 0x00b1, 0x00b2, 0x00b3, 0x00b4, 0x00b5, 0x00b6, 0x00b7, 0x00b8, 0x00b9, 0x00ba, 0x00bb, 0x00bc, 0x00bd, 0x00be, 0x00bf, 
0x00c0, 0x00c1, 0x00c2, 0x00c3, 0x00c4, 0x00c5, 0x00c6, 0x00c7, 0x00c8, 0x00c9, 0x00ca, 0x00cb, 0x00cc, 0x00cd, 0x00ce, 0x00cf, 
0x011e, 0x00d1, 0x00d2, 0x00d3, 0x00d4, 0x00d5, 0x00d6, 0x00d7, 0x00d8, 0x00d9, 0x00da, 0x00db, 0x00dc, 0x0130, 0x015e, 0x00df, 
0x00e0, 0x00e1, 0x00e2, 0x00e3, 0x00e4, 0x00e5, 0x00e6, 0x00e7, 0x00e8, 0x00e9, 0x00ea, 0x00eb, 0x00ec, 0x00ed, 0x00ee, 0x00ef, 
0x011f, 0x00f1, 0x00f2, 0x00f3, 0x00f4, 0x00f5, 0x00f6, 0x00f7, 0x00f8, 0x00f9, 0x00fa, 0x00fb, 0x00fc, 0x0131, 0x015f, 0x00ff};

		// UPC Direct / HBO strange two-character encoding. 0xC2 means acute, 0xC8 doule 'dot', 0xCA small 'circle', 0xCD double 'acute', 0xCF acute.
		// many thanks to the czechs who helped me while solving this.
static inline unsigned int doCzech(int c1, int c2)
{
	switch (c1)
	{
	case 0xC2: // acute
		switch (c2)
		{
		case 'A': return 0x00C1;
		case 'a': return 0x00E1;
		case 'E': return 0x00C9;
		case 'e': return 0x00E9;
		case 'I': return 0x00CD;
		case 'i': return 0x00ED;
		case 'O': return 0x00D3;
		case 'o': return 0x00F3; // corrected, was 0x00E3
		case 'U': return 0x00DA;
		case 'u': return 0x00FA;
		case 'Y': return 0x00DD;
		case 'y': return 0x00FD;
		default:
			return 0;
		}
	case 0xC8: // double 'dot'
		switch (c2)
		{
		case 'A': return 0x00C4;
		case 'a': return 0x00E4;
		case 'E': return 0x00CB;
		case 'e': return 0x00EB;
		case 'O': return 0x00D6;
		case 'o': return 0x00F6;
		case 'U': return 0x00DC;
		case 'u': return 0x00FC;
		default:
			return 0;
		}
	case 0xCA: // small 'circle'
		switch (c2)               
		{                         
		case 'U': return 0x016E;  
		case 'u': return 0x016F;  
		default:                  
			return 0;             
		}                         
	case 0xCD: // double 'acute'
		switch (c2)               
		{                         
		case 'O': return 0x0150;  
		case 'o': return 0x0151;  
		case 'U': return 0x0170;  
		case 'u': return 0x0171;  
		default:                  
			return 0;             
		}                         
	case 0xCF: // caron
		switch (c2)
		{
		case 'C': return 0x010C;
		case 'c': return 0x010D;
		case 'D': return 0x010E;
		case 'd': return 0x010F;
		case 'E': return 0x011A;
		case 'e': return 0x011B;
		case 'L': return 0x013D;	// not sure if they really exist.
		case 'l': return 0x013E;
		case 'N': return 0x0147;
		case 'n': return 0x0148;
		case 'R': return 0x0158;
		case 'r': return 0x0159;
		case 'S': return 0x0160;
		case 's': return 0x0161;
		case 'T': return 0x0164;
		case 't': return 0x0165;
		case 'Z': return 0x017D;
		case 'z': return 0x017E;
		default:
			return 0;
		}
	default:
		return 0;
	}
}

static inline unsigned int recode(unsigned char d, int cp)
{
	if (d < 0x80)
		return d;
	switch (cp)
	{
	case 0:		// 8859-1 Latin1 <-> unicode mapping
		return d;
	case 1:		// 8859-5 -> unicode mapping
		return c88595[d-0x80];
	case 2:		// 8859-6 -> unicode mapping
		return c88596[d-0x80];
	case 3:		// 8859-7 -> unicode mapping
		return c88597[d-0x80];
	case 4:		// 8859-8 -> unicode mapping
		return c88598[d-0x80];
	case 5:		// 8859-9 -> unicode mapping
		return c88599[d-0x80];
	default:
		return d;
	}
}

eString convertDVBUTF8(const unsigned char *data, int len, int table)
{
	int i;
	if (!len)
		return "";
		
	i=0;
	if (data[0] <= 5)
		table=data[i++];
	if ((data[0] >= 0x10) && (data[0] <= 0x12))
		return "<unsupported encoding>";

	int bytesneeded=0, t=0, s=i;
	
	for (; i<len; ++i)
	{
		unsigned long code=0;
		if ((table == 5) && ((data[i] == 0xC2) || (data[i] == 0xC8) || (data[i] == 0xCA) || (data[i] == 0xCD) || (data[i] == 0xCF)) && (i+1 < len))
				// braindead czech encoding...
			if ((code=doCzech(data[i], data[i+1])))
				++i;
		if (!code)
			code=recode(data[i], table);
		if (!code)
			continue;
		if (code >= 0x10000)
			bytesneeded++;
		if (code >= 0x800)
			bytesneeded++;
		if (code >= 0x80)
			bytesneeded++;
		bytesneeded++;
	}
	
	i=s;
	
	unsigned char res[bytesneeded];
	
	while (i < len)
	{
		unsigned long code=0;
		if ((table == 5) && ((data[i] == 0xC2) || (data[i] == 0xC8) || (data[i] == 0xCA) || (data[i] == 0xCD) || (data[i] == 0xCF)) && (i+1 < len))
				// braindead czech encoding...
			if ((code=doCzech(data[i], data[i+1])))
				i+=2;
		if (!code)
			code=recode(data[i++], table);
		if (!code)
			continue;
				// Unicode->UTF8 encoding
		if (code < 0x80) // identity ascii <-> utf8 mapping
			res[t++]=char(code);
		else if (code < 0x800) // two byte mapping
		{
			res[t++]=(code>>6)|0xC0;
			res[t++]=(code&0x3F)|0x80;
		} else if (code < 0x10000) // three bytes mapping
		{
			res[t++]=(code>>12)|0xE0;
			res[t++]=((code>>6)&0x3F)|0x80;
			res[t++]=(code&0x3F)|0x80;
		} else
		{
			res[t++]=(code>>18)|0xF0;
			res[t++]=((code>>12)&0x3F)|0x80;
			res[t++]=((code>>6)&0x3F)|0x80;
			res[t++]=(code&0x3F)|0x80;
		}
	}
	if ( t != bytesneeded)
		eFatal("t: %d, bytesneeded: %d", t, bytesneeded);
	return eString().assign((char*)res, t);
}

eString convertUTF8DVB(const eString &string, int table)
{
	unsigned long *coding_table=0;

	eString ss;

	int len=string.length();

	for(int i=0;i<len;i++)
	{
		unsigned char c1=string[i];
		unsigned int c;
		if(c1<0x80)
			c=c1;
		else
		{
			i++;
			unsigned char c2=string[i];
			c=((c1&0x3F)<<6) + (c2&0x3F);
			if (!coding_table)
			{
				switch(table)
				{
					case 1:
						coding_table = c88595;
						break;
					case 2:
						coding_table = c88596;
						break;
					case 3:
						coding_table = c88597;
						break;
					case 4:
						coding_table = c88598;
						break;
					case 5:
						coding_table = c88599;
						break;
					default:
						eFatal("unknown coding table\n");
						break;
				}
			}
			for(unsigned int j=0;j<128;j++)
			{
				if(coding_table[j]==c)
				{
					c=0x80+j;
					break;
				}
			}
		}
		ss+=c;
	}
	return ss;
}

eString convertLatin1UTF8(const eString &string)
{
	unsigned int bytesneeded=0, t=0, i;
	
	unsigned int len=string.size();
	
	for (i=0; i<len; ++i)
	{
		unsigned long code=string[i];
		if (!code)
			continue;
		if (code >= 0x10000)
			bytesneeded++;
		if (code >= 0x800)
			bytesneeded++;
		if (code >= 0x80)
			bytesneeded++;
		bytesneeded++;
	}
	
	i=0;
	
	unsigned char res[bytesneeded];
	
	while (i < len)
	{
		unsigned long code=string[i++];
				// Unicode->UTF8 encoding
		if (code < 0x80) // identity latin <-> utf8 mapping
			res[t++]=char(code);
		else if (code < 0x800) // two byte mapping
		{
			res[t++]=(code>>6)|0xC0;
			res[t++]=(code&0x3F)|0x80;
		} else if (code < 0x10000) // three bytes mapping
		{
			res[t++]=(code>>12)|0xE0;
			res[t++]=((code>>6)&0x3F)|0x80;
			res[t++]=(code&0x3F)|0x80;
		} else
		{
			res[t++]=(code>>18)|0xF0;
			res[t++]=((code>>12)&0x3F)|0x80;
			res[t++]=((code>>6)&0x3F)|0x80;
			res[t++]=(code&0x3F)|0x80;
		}
	}
	if ( t != bytesneeded)
		eFatal("t: %d, bytesneeded: %d", t, bytesneeded);
	return eString().assign((char*)res, t);
}

int isUTF8(const eString &string)
{
	unsigned int len=string.size();
	
	for (unsigned int i=0; i < len; ++i)
	{
		if (!(string[i]&0x80)) // normal ASCII
			continue;
		if ((string[i] & 0xE0) == 0xC0) // one char following.
		{
				// first, length check:
			if (i+1 >= len)
				return 0; // certainly NOT utf-8
			i++;
			if ((string[i]&0xC0) != 0x80)
				return 0; // no, not UTF-8.
		} else if ((string[i] & 0xF0) == 0xE0)
		{
			if ((i+1) >= len)
				return 0;
			i++;
			if ((string[i]&0xC0) != 0x80)
				return 0;
			i++;
			if ((string[i]&0xC0) != 0x80)
				return 0;
		}
	}
	return 1; // can be UTF8 (or pure ASCII, at least no non-UTF-8 8bit characters)
}


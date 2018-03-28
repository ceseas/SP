#include "Stream.h"


Stream::Stream(BYTE * buffer)
{
	_buffer = buffer;
	_length = 0;
}

Stream::~Stream()
{
}

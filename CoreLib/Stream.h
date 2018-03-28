#ifndef STREAM_H
#define STREAM_H

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

class Stream
{
public :
	Stream(BYTE *buffer);
	~Stream();

	template <typename T>
	BOOL Write(T t);

	template <typename T>
	BOOL Read(T *t);

private :

	BYTE *_buffer;
	LONG _length;

};

template<typename T>
inline BOOL Stream::Write(T t)
{
	CopyMemory(_buffer + _length, &t, sizeof(t));
	_length += sizeof(t);

	return true;
}

template<typename T>
inline BOOL Stream::Read(T *t)
{
	CopyMemory(t, _buffer + _length, sizeof(*t));
	_length += sizeof(*t);

	return true;
}

#endif

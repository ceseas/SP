#pragma comment(lib, "CoreLib")

#include "../CoreLib/Stream.h"

#include <tchar.h>

#include <stdio.h>

struct TestStruct
{
	int _a;
	int _b;
	float _c;
	TCHAR _d[64];
};


int main()
{
	TestStruct test;
	test._a = 10;
	test._b = 30;
	test._c = 40.0f;
	_stprintf(test._d, _T("Hi my name is park chi su"));

	BYTE *buffer = new BYTE[128];
	Stream writeStream(buffer);

	writeStream.Write<TestStruct>(test);

	Stream readStream(buffer);

	TestStruct readTest;
	ZeroMemory(&readTest, sizeof(TestStruct));
	readStream.Read<TestStruct>(&readTest);

    return 0;
}


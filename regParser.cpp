#include "regParserHeader.h"

S32 main(U32 argc, const U8 * argv[])
{
	if (argc != 2) {
		PrintError("[usage] regParser [file absolute path]");
	}

	HiveBin rootHbin;

	return 0;
}

void PrintError(string errorMsg) {
	cout << errorMsg << endl;
	exit(1);
}

void getFileDump(const U8 fileName[], U64 offset, U64 fileSize) {

}
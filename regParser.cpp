#include "regParserHeader.h"

S32 main(U32 argc, const char * argv[])
{
	if (argc != 2) {
		PrintError("[usage] regParser [file absolute path]");
	}

	HiveBin rootHbin;
	vector<U8> buf;
	getFileDump(argv[1], buf, 0, 0);
	
	return 0;
}

void PrintError(string errorMsg) {
	cout << errorMsg << endl;
	exit(1);
}

void getFileDump(const char fileName[], vector<U8> & buf, U64 offset, U64 fileSize) {
	ifstream ifs(fileName, ios::binary | ios::beg);
	if (fileSize == 0) {
		ifs.seekg(ios::end);
		fileSize = ifs.tellg();
		cout << "filesize : " << fileSize << endl;
	}


	ifs.close();
}
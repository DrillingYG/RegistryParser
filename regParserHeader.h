#pragma once
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

typedef uint64_t U64;
typedef uint32_t U32;
typedef uint16_t U16;
typedef uint8_t U8;
typedef int64_t S64;
typedef int32_t S32;
typedef int16_t S16;
typedef int8_t S8;

#pragma pack(1)
typedef struct {
	U8 MagicNumber[4];
	U32 SeqNum1;
	U32 SeqNum2;
	U64 TimeStamp;
	U32 MajorVersion;
	U32 MinorVersion;
	U64 Unknown1;
	U32 PointerToFirstKeyRecord;
	U32 PointerToStartOfLastHbin;
	U32 Unknown2;
	U8 HiveFileName[64];
	U8 Unknowns1[396];
	U32 ChecksumOfData;
	U8 Unknowns2[3584];
} RegistryHeader;

class Cell {
public:
	
protected :
	U32 mCellLength;
};

class Key : public Cell {
public:
	Key(U32 offset, U8 * hexDump) {
		memcpy_s(this, sizeof(Key) - sizeof(U8*), hexDump, sizeof(Key) - sizeof(U8*));
		KeyName = new U8[this->KeyNameLength];
		memcpy_s(this->KeyName, KeyNameLength, hexDump + sizeof(Key) - sizeof(U8*), KeyNameLength);
	}

	~Key() {
		if (KeyName != nullptr) delete[] KeyName;
	}
private:
	U8 MagicNumber[2];
	U16 Flags;
	U64 TimeStamp;
	U32 Unknown1;
	U32 ParentNkRecordOffset;
	U32 NumberOfSubkeysStable;
	U32 NumberOfSubkeysVolatile;
	U32 PointerToSubkeyListStable;
	U32 PointerToSubkeyListVolatile;
	U32 NumberOfValues;
	U32 PointerToValueList;
	U32 PointerToSkRecord;
	U32 PointerToClassName;
	U32 MaxNumberOfBytesInSubkeyName;
	U32 MaxSubkeyClassNameLength;
	U32 MaxNumberOfBytesInValueName;
	U32 MaxValueDataSize;
	U32 Unknown2;
	U16 KeyNameLength;
	U16 ClassNameLength;
	U8 * KeyName = nullptr;
};

class SubKeyLists : public Cell {
public:
	
};

class HiveBin {
public:
	void SetHiveBin();

private:
	U8 MagicNumber[4];
	U32 DistanceFromFirstHbin;
	U32 HbinSize;
	U8 Unknowns[16];
	U32 RelativeOffsetOfNextHbin;

};

void PrintError(string errorMsg);
void getFileDump(const U8 fileName[], U64 offset, U64 fileSize);

#pragma pack()

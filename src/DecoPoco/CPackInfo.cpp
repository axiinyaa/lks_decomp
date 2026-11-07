#include "DecoPoco\CPackInfo.hpp"
#include <string.h>
CPackInfo::CPackInfo()
{
	filePointer = 0;
}

CPackInfo::~CPackInfo()
{
	//Destructor. Included Here for Parity
}

bool CPackInfo::SetPackFile(char* FilePointer)
{
	//Sets the Header Pointer (If the Header is Valid)
	filePointer = 0;
	if(FilePointer == 0)
	{
		//If Pointer is Null, Return False
		return false;
	}
	if(FilePointer[0] != 'P')
	{
		//If File Magic is Wrong, Return False
		return false;
	}
	if(FilePointer[1] != 'C')
	{
		//If File Magic is Wrong, Return False
		return false;
	}
	if(FilePointer[2] != 'K')
	{
		//If File Magic is Wrong, Return False
		return false;
	}
	if(FilePointer[3] != 'F' && FilePointer[3] != 'G')
	{
		//If File Magic is Wrong, Return False. Interestingly there are 2 valid headers here.
		return false;
	}
	//It has a valid header so it can be the new pointer
	filePointer = (PackFile*)FilePointer;
	return true;
}
void CPackInfo::GetPackedFile(CPackInfo::PACK_INFO_ACCESS File)
{
	//Set File Pointer Pointer to this's pointer
	File->FilePackHeader = 0;
	if(filePointer == 0)
	{
		return;
	}
	File->FilePackHeader = (int)filePointer + 0x20;
}

CPackInfo::PackHeaderAccess::PackHeaderAccess()
{
    Header = 0;
}
CPackInfo::PackHeaderAccess::PackHeaderAccess(char* HeaderType)
{
	Header = 0;
	CPackInfo::PackFileHeader* PackHeader = (CPackInfo::PackFileHeader*)HeaderType;
    Header = PackHeader;
}
CPackInfo::PackHeaderAccess::~PackHeaderAccess()
{
    //Destructor. Included Here for Parity
}
void CPackInfo::PackHeaderAccess::AdvanceHeader()
{
	//Set the Header to be the next Header in the package, if it exists
	if(Header==0)
	{
		//There is no next header as the header is null
		return;
	}
	else if(Header->HeaderOffset!=0)
	{
		 Header = (PackFileHeader*)((int)Header + Header->HeaderOffset);
		return;
	}
	Header = 0;
	
}
void CPackInfo::PackHeaderAccess::AdvanceHeaderAlt()
{
	//Duplicate of AdvanceHeader
	//Set the Header to be the next Header in the package, if it exists
	if(Header==0)
	{
		//There is no next header as the header is null
		return;
	}
	else if(Header->HeaderOffset!=0)
	{
		 Header = (PackFileHeader*)((int)Header + Header->HeaderOffset);
		return;
	}
	Header = 0;
}
bool CPackInfo::PackHeaderAccess::equals(CPackInfo::PackHeaderAccess otherHeader)
{
	//Returns true if the passed Access's Header is the same as the current's Header
	return Header == otherHeader.Header;
}
bool CPackInfo::PackHeaderAccess::areUnique(CPackInfo::PackHeaderAccess otherHeader)
{
	//Returns true if the passed Access's Header is not the same as the current's Header
	return Header != otherHeader.Header;
}
char* CPackInfo::PackHeaderAccess::GetFileName()
{
	//Get a pointer to the start of the name in the package header
	return Header->Name;
}
int CPackInfo::PackHeaderAccess::GetFileNameLength()
{
	//Get the Size of the Name Buffer in the Pack Header
	return (Header->HeaderSize - 12) + (int)Header->Name;
}
int CPackInfo::PackHeaderAccess::GetFileSize()
{
	//Get the Size of the File as defined by the Package Header
	return Header->FileSize;
}
CPackInfo::PACK_INFO_ACCESS::PACK_INFO_ACCESS(PackFileHeader* FileHeader)
{
	Header = FileHeader;
}
CPackInfo::PACK_INFO_ACCESS::~PACK_INFO_ACCESS()
{
	//Destructor. Included Here for Parity
}
bool CPackInfo::PACK_INFO_ACCESS::equals(char* name)
{
	//Return true if the given name is equal to the Header's Name
	if(Header == 0)
	{
		//If header is null, there is no name so return they arent equal
		return false;
	}
	//If header name is equal to passed name, return true;
	return strcmp(Header->Name, name) == 0;;
}

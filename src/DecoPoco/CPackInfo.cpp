#include "DecoPoco\CPackInfo.h"

bool CPackInfo::SetPackFile(char* FilePointer)
{
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
void CPackInfo::GetPackedFile(char** File, CPackInfo Info)
{
	if(Info.filePointer == 0)
	{
		*File = 0;
		return;
	}
	*File = (char*)Info.filePointer->FilePackHeader;
}

CPackInfo::PackHeaderAccess::PackHeaderAccess()
{
    Header = 0;
}
CPackInfo::PackHeaderAccess::PackHeaderAccess(CPackInfo::PackFileHeader* HeaderType)
{
    Header = HeaderType;
}
void CPackInfo::PackHeaderAccess::AdvanceHeader()
{
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
void CPackInfo::PACK_INFO_ACCESS::GetFileFromName(char* name)
{

}

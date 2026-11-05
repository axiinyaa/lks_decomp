#include <DecoPoco/CPackInfo.h>

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
void CPackInfo::PackHeaderAccess::ShiftHeader()
{

}
void CPackInfo::PackHeaderAccess::FUN_8008f8c4()
{

}
void CPackInfo::PackHeaderAccess::FUN_8008f8f4()
{

}
void CPackInfo::PackHeaderAccess::FUN_8008f90c()
{

}
char* CPackInfo::PackHeaderAccess::GetNextFileName()
{
	return Header->Name;
}
int CPackInfo::PackHeaderAccess::GetNextFileNameLength()
{

}
int CPackInfo::PackHeaderAccess::GetNextFileSize()
{

}
void CPackInfo::PACK_INFO_ACCESS::GetFileFromName(char* name)
{

}

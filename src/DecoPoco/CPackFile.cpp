#include <DecoPoco/CPackFile.h>
#include <DecoPoco/CPackInfo.h>

CPackFile::CPackFile()
{
	Padding1 = 0;
	PackInfo = new CPackInfo();
}
CPackFile::~CPackFile()
{

}
CPackFile::GetPackPadding()
{
	return Padding1;
}
CPackFile::GetPackageType(byte* FilePointer)
{

}
CPackInfo::CPackInfo()
{
	filePointer = NULL;
}
CPackInfo::SetPackFile()
{
	filePointer = NULL;
}

#include <DecoPoco/CPackFile.h>
#include <DecoPoco/CPackInfo.h>

CPackFile::CPackfile()
{
	padding = 0;
	PackInfo = new CPackInfo();
}
CPackInfo::CPackInfo()
{
	filePointer = NULL;
}

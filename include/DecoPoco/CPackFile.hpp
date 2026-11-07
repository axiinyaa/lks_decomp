#ifndef C_PACK_FILE_H
#define C_PACK_FILE_H

#include "DecoPoco\CPackInfo.hpp"

class CPackFile
{
	private:
		int PackageType;
		int Padding1;
		CPackInfo PackInfo;
	public:
		CPackFile():PackageType(0),Padding1(0),PackInfo(){};
		virtual ~CPackFile(){};
		void CPackFil1e(const char* filePointer);
		void DeletePackFile(){};
		void SetPackPadding();
		int GetPackageType(char* FilePointer);
		char* LoadPackage();
		char* GetFileType();
		char* GetFileFromPack();
};

#endif

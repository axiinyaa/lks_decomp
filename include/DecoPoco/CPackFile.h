#include <CPackInfo.h>

class CPackFile
{
	private:
		int PackageType;
		int Padding1;
		CPackInfo PackInfo;
	public:
		CPackFile():PackageType(0),Padding1(0),PackInfo(){};
		virtual ~CPackFile(){};
		CPackFile(const char* filePointer);
		void DeletePackFile(){};
		void SetPackPadding();
		int GetPackageType(char* FilePointer);
		char* LoadPackage();
		char* GetFileType();
		char* GetFileFromPack();
};

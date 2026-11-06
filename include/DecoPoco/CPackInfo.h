#ifndef C_PACK_INFO_H
#define C_PACK_INFO_H

class CPackInfo
{
	struct PackFileHeader
	{
		int HeaderOffset;
		int FileSize;
		int HeaderSize;
		char Name[20];
		char FileData[];
	};
	struct PackFile
	{
		char Magic[32];
		PackFileHeader* FilePackHeader;
	};
	private:
		PackFile* filePointer;
	public:
		CPackInfo():filePointer(0){}
		virtual ~CPackInfo();
		bool SetPackFile(char* FilePointer);
		void GetPackedFile(char** File,CPackInfo Info);
		class PackHeaderAccess
		{
			private:
			PackFileHeader* Header;
			public:
			PackHeaderAccess();
			PackHeaderAccess(PackFileHeader* HeaderType);
			~PackHeaderAccess();
			void AdvanceHeader();
			void AdvanceHeaderAlt();
			bool equals(CPackInfo::PackHeaderAccess otherHeader);
			bool areUnique(CPackInfo::PackHeaderAccess otherHeader);
			char* GetFileName();
			int GetFileNameLength();
			int GetFileSize();
		};
		class PACK_INFO_ACCESS
		{
			private:
			PackFileHeader* Header;
			public:
				PACK_INFO_ACCESS():Header(0){};
				virtual ~PACK_INFO_ACCESS();
				void GetFileFromName(char* name);
		};
};

#endif

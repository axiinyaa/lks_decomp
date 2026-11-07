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
	class PackHeaderAccess
		{
			public:
			PackFileHeader* Header;
			PackHeaderAccess();
			PackHeaderAccess(PackFileHeader** HeaderPointer);
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
			public:
				PACK_INFO_ACCESS(PackFileHeader* FileHeader);
				virtual ~PACK_INFO_ACCESS();
				bool equals(char* name);
				PackFileHeader* Header;
		};
	
	public:
		CPackInfo();
		virtual ~CPackInfo();
		bool SetPackFile(char* FilePointer);
		static void SetPackHeader(PackHeaderAccess* File, CPackInfo* Info);
	private:
		PackFile* filePointer;
};

#endif

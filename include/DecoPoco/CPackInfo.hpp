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
		CPackInfo();
		virtual ~CPackInfo();
		bool SetPackFile(char* FilePointer);
		void GetPackedFile(CPackInfo::PACK_INFO_ACCESS File);
		class PackHeaderAccess
		{
			private:
			PackFileHeader* Header;
			public:
			PackHeaderAccess();
			PackHeaderAccess(char* HeaderType);
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
				PACK_INFO_ACCESS(PackFileHeader* FileHeader);
				virtual ~PACK_INFO_ACCESS();
				bool equals(char* name);
		};
};

#endif

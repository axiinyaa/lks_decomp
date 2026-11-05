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
		void GetPackedFile(char** File, CPackInfo Info);
		class PackHeaderAccess
		{
			private:
			PackFileHeader* Header;
			public:
			PackHeaderAccess():Header(0){}
			PackHeaderAccess(PackFileHeader* HeaderType):Header(HeaderType){}
			~PackHeaderAccess();
			void ShiftHeader();
			void FUN_8008f8c4();
			void FUN_8008f8f4();
			void FUN_8008f90c();
			char* GetNextFileName();
			int GetNextFileNameLength();
			int GetNextFileSize();
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

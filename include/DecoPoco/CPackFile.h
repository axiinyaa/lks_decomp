namespace CPackFile {
struct CPackInfo
{
	byte* filePointer;
};
struct CPackFile
{
	int PackageType;
	int Padding1;
	CPackInfo PackInfo;
};
struct PACK_INFO_ACCESS
{

};
}

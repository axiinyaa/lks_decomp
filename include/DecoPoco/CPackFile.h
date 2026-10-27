namespace CPackFile {
struct CPackFile
{
	int PackageType
	int Padding1
	CPackInfo PackInfo
};
struct CPackInfo
{
	byte* filePointer
};
struct PACK_INFO_ACCESS
{

};
}

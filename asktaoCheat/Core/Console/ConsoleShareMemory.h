#ifndef __ASKTAOCHEAT_GAMEDLL_CORE_CONSOLE_CONSOLESHAREMEMORY_H__
#define __ASKTAOCHEAT_GAMEDLL_CORE_CONSOLE_CONSOLESHAREMEMORY_H__

#include <Core/Common/GameStruct.h>
#include <future>

class CConsoleShareMemory
{
public:
	CConsoleShareMemory() = default;
	~CConsoleShareMemory();

	static CConsoleShareMemory& GetInstance();
public:

	// Read Console Share Memory Mapping to here
	// ��ȡ����̨���ڴ湲������
	BOOL Initialize();

private:
	// Watch Console Memory => Is Run Script ...
	// ���ӿ���̨��ָ��
	VOID AsyncWatchConsole();

private:
	ConsoleShareMemoryContent*  _pConsoleShareMemory	= nullptr;
	HANDLE						_hFileMapping			= NULL;
	std::future<VOID>			_AsyncWatchConsolePtr;
	BOOL						_RunThread				= FALSE;
};



#endif // !__ASKTAOCHEAT_GAMEDLL_CORE_CONSOLE_CONSOLESHAREMEMORY_H__

#include <Windows.h>
#include <KexComm.h>
#include <KexDll.h>
#include <NtDll.h>

// TODO: Implement these functions properly. But for now, basically no apps
// actually use these so it's low priority.

PVOID WINAPI LdrResolveDelayLoadedAPI(
	IN	PVOID							ParentModuleBase,
	IN	PVOID							DelayloadDescriptor,
	IN	PVOID							FailureDllHook,
	IN	PVOID							FailureSystemHook,
	OUT	PIMAGE_THUNK_DATA				ThunkAddress,
	IN	ULONG							Flags)
{
	ODS_ENTRY(L"(%p, %p, %p, %p, %p, %I32u)", ParentModuleBase, DelayloadDescriptor, FailureDllHook, FailureSystemHook, ThunkAddress, Flags);
	return NULL;
}

void __fastfail(unsigned int code);

NTSTATUS WINAPI LdrGetDllFullName(HMODULE DllHandle, UNICODE_STRING *FileName)
{
	GetModuleFileNameW(DllHandle, FileName->Buffer, FileName->Length);
	switch(GetLastError()) {
	case 0x7E:
		return 0xC0000135;
		break;
	case 0x7A:
		return 0xC000002;
		break;
	}
	return 0x00000000;
}
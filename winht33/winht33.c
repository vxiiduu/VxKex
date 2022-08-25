#include <Windows.h>
#include <Shlwapi.h>
#include <KexDll.h>
#include <Winhttp.h>

DWORD WINAPI WinHttpWebSocketClose( HINTERNET hsocket, USHORT status, void *reason, DWORD len ) {
    return WinHttpCloseHandle(hsocket);
}

DWORD WINAPI WinHttpWebSocketReceive(HINTERNET hWebSocket, PVOID pvBuffer, DWORD dwBufferLength, DWORD *pdwBytesRead, enum WINHTTP_WEB_SOCKET_BUFFER_TYPE *peBufferType) {
	return WinHttpReceiveResponse(hWebSocket, pvBuffer);
}

DWORD WINAPI WinHttpWebSocketSend(HINTERNET hWebSocket, enum WINHTTP_WEB_SOCKET_BUFFER_TYPE eBufferType, PVOID pvBuffer, DWORD dwBufferLength) {
	return WinHttpSendRequest(hWebSocket, ((LPCWSTR)pvBuffer), dwBufferLength, pvBuffer, 0, 0, NULL);
}

HINTERNET WINAPI WinHttpWebSocketCompleteUpgrade(HINTERNET hRequest, DWORD_PTR pContext) {
	return WinHttpSetStatusCallback(hRequest, NULL, WINHTTP_CALLBACK_FLAG_SENDREQUEST_COMPLETE, NULL);
}
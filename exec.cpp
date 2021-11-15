// dllmain.cpp : Defines the entry point for the DLL application.
#include <string>
#include <vector>
#include <fstream>
#include "windows.h"
#include <iostream>
#include "detours/detours.h"
#pragma comment(lib, "detours/detours.lib")
using namespace std;
typedef __int64(__fastcall* t_27360)(__int64 a1, char* scriptName, char* a3);
t_27360 hook_27360 = (t_27360)((uintptr_t)GetModuleHandle(L"citizen-scripting-lua.dll") + 0x28CF0);
__int64 __fastcall sub_27360(__int64 a1, char* scriptName, char* a3) {
    std::string roothpath = (char*)scriptName;
    if (roothpath.find("client.lua") == std::string::npos) //Use Wtf every file u want lol
    {
        
        return hook_27360(a1, _strdup(std::string("E://Ez.lua").c_str()), a3);
    };
    


    return hook_27360(a1, scriptName, a3);
}
DWORD WINAPI HotChick(HMODULE hModule)
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(LPVOID&)hook_27360, &sub_27360);
    DetourTransactionCommit();
    return true;
}
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)HotChick, 0, 0, 0);
    }
    return TRUE;
}


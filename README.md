# FiveM-Executor

## Here comes a little Explanation what we did

Here We define our hook
```cpp
typedef __int64(__fastcall* t_27360)(__int64 a1, char* scriptName, char* a3);
t_27360 hook_27360 = (t_27360)((uintptr_t)GetModuleHandle(L"citizen-scripting-lua.dll") + 0x28CF0);
```


Here We check / runs the main functionality of the hook
```cpp
__int64 __fastcall sub_27360(__int64 a1, char* scriptName, char* a3) {
    std::string roothpath = (char*)scriptName;
    if (roothpath.find("client.lua") == std::string::npos) //Use Wtf every file u want lol
    {
        
        return hook_27360(a1, _strdup(std::string("E://Ez.lua").c_str()), a3);
    };
    


    return hook_27360(a1, scriptName, a3);
}
```


This Executor is Proof-of-Concept which means its not always hard so keep going also if Nk or any other retards claim statements like executor is 3000 lines as he usually do, you can contact me by ```cpp H4xton#1337```

#include <Windows.h>
#include <stdio.h>

#define REG_KEY_PATH L"Software\\Microsoft\\Windows\\CurrentVersion\\Run"

#define REG_VALUE_NAME L"StartupProgram"

const wchar_t* programPath = L"C:\\StartUp.exe";

void RegisterStartupProgram(const wchar_t* programPath) {
    HKEY hKey;
    LONG result = RegOpenKeyEx(HKEY_CURRENT_USER, REG_KEY_PATH, 0, KEY_SET_VALUE, &hKey);

    if (result == ERROR_SUCCESS) {
        result = RegSetValueEx(hKey, REG_VALUE_NAME, 0, REG_SZ, (BYTE*)programPath, (wcslen(programPath) + 1) * sizeof(wchar_t));

        RegCloseKey(hKey);
    }
}

int main() {
    RegisterStartupProgram(programPath);
    return 0;
}
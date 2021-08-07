#include <windows.h>
#include <iostream>
HKEY key;

DWORD buffsize = 4096;

DWORD type = 0;

DWORD dwRet;

char*  value = new char [buffsize];

#define KEY_WOW64_32KEY 0x0200
#define KEY_WOW64_64KEY 0x0100
int main() {

    HKEY hKey;
    RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_WOW64_64KEY | KEY_ALL_ACCESS, &hKey);
    RegDeleteValue(hKey,"USUWANIEIKONYDEF");
    RegDeleteValue(hKey,"SecurityHealth");
    //Dodatkowe usuwanie 32-bitowe
    RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\WOW6432Node\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_WOW64_64KEY | KEY_ALL_ACCESS, &hKey);
    RegDeleteValue(hKey,"USUWANIEIKONYDEF");
    RegDeleteValue(hKey,"SecurityHealth");
        //std::cout<<GetLastError();
    RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\StartupApproved\\Run", 0, KEY_WOW64_64KEY | KEY_ALL_ACCESS, &hKey);
    RegDeleteValue(hKey,"USUWANIEIKONYDEF");
    RegDeleteValue(hKey,"SecurityHealth");
    RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\StartupApproved\\Run32", 0, KEY_WOW64_64KEY | KEY_ALL_ACCESS, &hKey);
    RegDeleteValue(hKey,"USUWANIEIKONYDEF");
    RegCloseKey(hKey);

   // system("reg delete \"HKEY_LOCAL_MACHINE\\SOFTWARE\\AAA\"  ");
    std::cout<<"==========================================================\n========Windows 10 Bloat Remover v. 1.7.4 by Koraz========\n==========================================================\n";
    std::cout<<"\nDzialanie zakonczono pomyslnie!\n"<<std::endl;
    system("pause");
    return 0;
}

#include <iostream>
#include <windows.h>

typedef const char* (*getFileFormatPtr)(const char*);

int main() {
    HINSTANCE hDLL = LoadLibrary(".\\getTextureInfo.dll");
    if (hDLL == NULL) {
        std::cerr << "Failed to load DLL." << std::endl;
        return 1;
    }

    getFileFormatPtr getFileFormat = reinterpret_cast<getFileFormatPtr>(GetProcAddress(hDLL, "getFileFormat"));
    if (getFileFormat == NULL) {
        std::cerr << "Failed to get function address." << std::endl;
        return 1;
    }

    const char* inputString = ".\\steve.3dst";
    const char* result = getFileFormat(inputString);
    std::cout << result << std::endl;

    FreeLibrary(hDLL);
    return 0;
}
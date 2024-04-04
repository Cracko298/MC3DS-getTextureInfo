# getTextureInfo
- A cross-platform and language compiled Binary.
- Gets information from Minecraft 3DST File Format.
- Feel Free to use this for Any project you want, just make sure to abide by the license.

## Callable Functions:
```cpp
getFileFormat(yourPathString);
getDemensions(yourCoolerPathString);
getMIPValue(yourEvenBetterPathString);
getFileVersion(yourLesserCoolPathString);
```

## Building:
### Linux:
```ps
 g++ -shared -fPIC -luser32 -o getTextureInfo.so -Os -O3 -flto -s LinuxFormatFind.cpp
```
Windows:
```ps
g++ -shared -o getTextureInfo.dll -Os -O3 -flto -s FormatFind.cpp
```
## Example for Calling Functions:
### Python:
```py
import ctypes
dll = ctypes.CDLL('.\\getTextureInfo.dll')

getFileFormat = dll.getFileFormat # Function Name Refrence
getFileFormat.argtypes = [ctypes.c_char_p]
getFileFormat.restype = ctypes.c_char_p
bFileFormat = getFileFormat(".\\steve.3dst".encode('utf-8'))
dFileFormat = bFileFormat.decode('utf-8')
print(dFileFormat)
```
### C++
```cpp
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
```
### Lua:
```lua
local ffi = require("ffi")
local mydll = ffi.load(".\\getTextureInfo.dll")
ffi.cdef("const char* getFileFormat(const char* input);")

local inputString = ".\\steve.3dst"
local result = ffi.string(mydll.getFileFormat(inputString))
print(result)
```
### Java:
```java
public class Main {
    static {
        System.loadLibrary(".\\getTextureInfo.dll");
    }

    public static native String getFileFormat(String input);

    public static void main(String[] args) {
        String inputString = ".\\steve.3dst";
        String result = getFileFormat(inputString);
        System.out.println(result);
    }
}
```

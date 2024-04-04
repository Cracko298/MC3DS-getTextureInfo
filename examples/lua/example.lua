local ffi = require("ffi")
local mydll = ffi.load(".\\getTextureInfo.dll")
ffi.cdef("const char* getFileFormat(const char* input);")

local inputString = ".\\steve.3dst"
local result = ffi.string(mydll.getFileFormat(inputString))
print(result)
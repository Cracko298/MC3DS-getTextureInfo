import ctypes
dll = ctypes.CDLL('.\\getTextureInfo.dll')

getFileFormat = dll.getFileFormat # Function Name Refrence
getFileFormat.argtypes = [ctypes.c_char_p]
getFileFormat.restype = ctypes.c_char_p
bFileFormat = getFileFormat(".\\steve.3dst".encode('utf-8'))
dFileFormat = bFileFormat.decode('utf-8')
print(dFileFormat)
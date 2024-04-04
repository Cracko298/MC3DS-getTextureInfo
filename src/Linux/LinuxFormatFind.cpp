#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <tuple>

extern "C" const char* getFileFormat(const char* filename) {
    int hFile = open(filename, O_RDONLY);
    if (hFile == -1) {
        return "File Not Found";
    }

    off_t offset = 0x20;
    lseek(hFile, offset, SEEK_SET); // Skip the first 0x20 bytes

    char buffer[4];
    ssize_t bytesRead;
    while ((bytesRead = read(hFile, buffer, 4)) > 0) {
        if (buffer[0] == '\xFF') {
            close(hFile);
            return "ABGR";
        } else if (buffer[3] == '\xFF') {
            close(hFile);
            return "RGBA8";
        }

        offset = 4;
        lseek(hFile, offset, SEEK_CUR); // Skip forward 4 bytes
    }

    close(hFile);
    return "No Format Found";
}

extern "C" int getFileVersion(const char* filename) {
    int hFile = open(filename, O_RDONLY);
    if (hFile == -1) {
        return -1; // File not found or unable to open
    }

    int fileVersion;
    off_t offset = 0x04;
    lseek(hFile, offset, SEEK_SET);
    read(hFile, &fileVersion, sizeof(int));

    close(hFile);
    return fileVersion;
}

extern "C" std::tuple<int, int> getDimensions(const char* filename) {
    int hFile = open(filename, O_RDONLY);
    if (hFile == -1) {
        return std::make_tuple(-1, -1); // File not found or unable to open
    }

    int width, height;
    off_t offset;

    offset = 0x0C;
    lseek(hFile, offset, SEEK_SET);
    read(hFile, &width, sizeof(int));

    offset = 0x10;
    lseek(hFile, offset, SEEK_SET);
    read(hFile, &height, sizeof(int));

    close(hFile);
    return std::make_tuple(width, height);
}

extern "C" int getMIPValue(const char* filename) {
    int hFile = open(filename, O_RDONLY);
    if (hFile == -1) {
        return -1; // File not found or unable to open
    }

    int mipValue;
    off_t offset = 0x1C;
    lseek(hFile, offset, SEEK_SET);
    read(hFile, &mipValue, sizeof(int));

    close(hFile);
    return mipValue;
}

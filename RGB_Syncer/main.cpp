#include <filesystem>
#include <Windows.h>

constexpr const char* GCC_PATH = "C:\\Program Files\\GIGABYTE\\Control Center\\GCC.exe";
constexpr const char* ICUE_PATH = "C:\\Program Files\\Corsair\\Corsair iCUE5 Software\\ICUE.exe";

inline bool file_exists(const char* path);
inline char* get_open_command(const char* path);

int main() {
    if (!file_exists(GCC_PATH)) {
        MessageBox(NULL, L"Gigabyte Control Center executable has not been found!", L"File not found", MB_ICONERROR | MB_OK);
        return -1;
    }

    if (!file_exists(ICUE_PATH)) {
        MessageBox(NULL, L"ICUE executable has not been found!", L"File not found", MB_ICONERROR | MB_OK);
        return -1;
    }

    std::system(get_open_command(ICUE_PATH));
    Sleep(2500);  
    std::system(get_open_command(GCC_PATH));

    return 1;
}

inline char* get_open_command(const char* path){
    const char* explorer = "explorer ";
    size_t iSize = strlen(GCC_PATH) + strlen(ICUE_PATH) + 1;

    char* command = new char[iSize];
    memset(command, 0, iSize);
    
    strcat_s(command, iSize, explorer);
    strcat_s(command, iSize, path);
    command[iSize] = '\0';

    return command;
}

inline bool file_exists(const char* path) {
    std::filesystem::path fPath(path);
    return std::filesystem::exists(fPath);
}
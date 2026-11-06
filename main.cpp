#include <iostream>
#include <windows.h>

int main() {
    std::cout << "===========================================" << std::endl;
    std::cout << "   Standalone Windows Application Running  " << std::endl;
    std::cout << "===========================================\n" << std::endl;

    // Retrieve System Information
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    std::cout << "Processor Architecture: " << sysInfo.wProcessorArchitecture << std::endl;
    std::cout << "Number of Processors:   " << sysInfo.dwNumberOfProcessors << std::endl;

    // Retrieve Physical Memory Status
    MEMORYSTATUSEX memStatus;
    memStatus.dwLength = sizeof(memStatus);
    if (GlobalMemoryStatusEx(&memStatus)) {
        DWORDLONG totalRAM = memStatus.ullTotalPhys / (1024 * 1024);
        DWORDLONG availRAM = memStatus.ullAvailPhys / (1024 * 1024);
        std::cout << "Total Memory:           " << totalRAM << " MB" << std::endl;
        std::cout << "Available Memory:       " << availRAM << " MB" << std::endl;
    }

    std::cout << "\nBuild complete. Press Enter to exit...";
    std::cin.get();
    return 0;
}

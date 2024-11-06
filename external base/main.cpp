#include <thread>
#include "render/overlay/overlay.h"
#include "cheatHandler/cheats.h"
#include "memory/memory.h"
#include "globals.h"
#include <iostream>

int main()
{

    // memory init
    globals::pID = memory::GetProcID(L"cs2.exe");

    if (globals::pID == 0) {
        std::cout << "game not found!";
    }
    
    globals::baseAddress = memory::GetModuleBaseAddress(pID, L"client.dll");
    HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);

    std::cout << "game found!!" << std::endl;
    std::cout << "pid >> " << globals::pID << std::endl;
    std::cout << "base address: 0x" << std::hex << globals::baseAddress << std::dec << std::endl;

    // threading
    std::thread cheatsThread(Cheats::Run);
    std::thread overlayThread(overlay::render);
    cheatsThread.join();
    overlayThread.join();

    return 0;
}

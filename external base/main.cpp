#include <thread>
#include "render/overlay/overlay.h"
#include "cheatHandler/cheats.h"
#include "memory/memory.h"
#include "globals.h"

int main()
{

    // memory init
    globals::pID = memory::GetProcID(L"cs2.exe");
    globals::baseAddress = memory::GetModuleBaseAddress(pID, L"client.dll");
    HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);



    // threading
    std::thread cheatsThread(Cheats::Run);
    std::thread overlayThread(overlay::render);
    cheatsThread.join();
    overlayThread.join();

    return 0;
}
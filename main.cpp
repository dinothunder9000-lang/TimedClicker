#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

void performClick() {
    INPUT inputs[2] = {};
    
    inputs[0].type = INPUT_MOUSE;
    inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

    inputs[1].type = INPUT_MOUSE;
    inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

    SendInput(2, inputs, sizeof(INPUT));
}

int main() {
    std::cout << "===========================================\n";
    std::cout << "             TIMED AUTO-CLICKER            \n";
    std::cout << "===========================================\n\n";

    int intervalMs = 100;
    std::cout << "Enter click interval in milliseconds (e.g. 100): ";
    if (!(std::cin >> intervalMs) || intervalMs <= 0) {
        intervalMs = 100;
    }

    std::cout << "\nControls:\n";
    std::cout << "  [F6] - Toggle ON / OFF\n";
    std::cout << "  [F7] - Exit Program\n\n";
    std::cout << "Current Status: STOPPED\n";

    bool running = false;
    bool f6Pressed = false;

    while (true) {
        // Toggle running state with F6 key
        if (GetAsyncKeyState(VK_F6) & 0x8000) {
            if (!f6Pressed) {
                running = !running;
                f6Pressed = true;
                std::cout << "Status: " << (running ? "RUNNING..." : "STOPPED") << std::endl;
            }
        } else {
            f6Pressed = false;
        }

        // Exit with F7 key
        if (GetAsyncKeyState(VK_F7) & 0x8000) {
            std::cout << "Exiting program...\n";
            break;
        }

        // Click loop
        if (running) {
            performClick();
            std::this_thread::sleep_for(std::chrono::milliseconds(intervalMs));
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }

    return 0;
}

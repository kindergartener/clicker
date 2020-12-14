#include <autoclicker.h>
#include <windows.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <config.h>
#include <array>
#include <algorithm>
#include <config.h>

std::array<float, 21> deviation_from_avg = {-9.0f, -9.0f, 9.0f, -6.0f, 3.0f, 1.0f, -1.0f, 1.0f, 0.0f, -8.0f, 2.0f, 12.0f, 2.0f, -10.0f, 5.0f, 12.0f, -10.0f, 2.0f, -6.0f, 1.0f, 6.0f};

int calc_cps(float target_cps) {
    return std::max(static_cast<int>((1000.0f/(2.0f*target_cps)) /*+ deviation_from_avg[rand() % deviation_from_avg.size()]*/ - 0.5f), 0);
}

void clicker::autoclicker() {
    while(true) {
        if(GetAsyncKeyState( 'M' ) & 0x8000) {
            mouse_event(
                MOUSEEVENTF_LEFTDOWN,
                0,
                0,
                0,
                0
            );

            std::this_thread::sleep_for(std::chrono::milliseconds(  calc_cps(config.attack_cps) ));

            mouse_event(
                MOUSEEVENTF_LEFTUP,
                0,
                0,
                0,
                0
            );

            std::this_thread::sleep_for(std::chrono::milliseconds( calc_cps(config.attack_cps) ));

        } else std::this_thread::sleep_for(std::chrono::milliseconds(1));

    }
}

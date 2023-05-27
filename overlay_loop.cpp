#include "main_loop.hpp"
#include <string>

void controller_test::overlay_loop() {
        DrawFPS(10, 10);
        DrawText(std::to_string(m_rotation_angle.x).c_str(), 10, 40, 20, BLACK);
}

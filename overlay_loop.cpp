#include "main_loop.hpp"
#include <string>

void controller_test::overlay_loop() {
        DrawFPS(10, 10);
        DrawText(std::to_string(m_forward_vector.x).c_str(), 10, 40, 20, BLACK);
        DrawText(std::to_string(m_forward_vector.y).c_str(), 10, 60, 20, BLACK);
}

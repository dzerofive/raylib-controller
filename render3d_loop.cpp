#include "main_loop.hpp"
#include <raylib.h>

void controller_test::render3d_loop() {
        DrawGrid(40, 1.f);
        DrawCube(Vector3{m_position.x, m_position.y+(m_height/2), m_position.z}, 0.5f, 0.5f, m_height, RED);
        DrawCube(m_camera_target+m_position, 0.2f, 0.2f, 0.2f, BLUE);
}

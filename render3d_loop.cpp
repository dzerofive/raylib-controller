#include "main_loop.hpp"
#include <raylib.h>

void controller_test::render3d_loop() {
        DrawGrid(40, 1.f);
        DrawCube(Vector3{m_position.x, m_position.y, (m_height/2)+m_position.z}, 0.5f, 0.5f, m_height, RED);
        DrawCube(Vector3{m_forward_vector.x+m_position.x, m_forward_vector.y+m_position.y, m_position.z+(m_height*0.85f)}, 0.2f, 0.2f, 0.2f, BLUE);
}

#include "main_loop.hpp"
#include <raylib.h>
#include <math.h>

void controller_test::render3d_loop() {
        DrawGrid(40, 1.f);
        //DrawCube(Vector3{m_position.x, m_position.y, (m_height/2)+m_position.z}, 0.5f, 0.5f, m_height, RED);
        DrawCube(Vector3{m_forward_vector.x+m_position.x, m_forward_vector.y+m_position.y, m_position.z+(m_height*0.7f)}, 0.1f, 0.1f, 0.1f, BLUE);

        switch(m_animation_state) {
        case animation_states::idle:
                UpdateModelAnimation(murasame, anim_idle, m_animation_frame);
                break;
        case animation_states::walk:
                if(m_animation_frame >= anim_walk.frameCount) m_animation_state = animation_states::idle;              
                else UpdateModelAnimation(murasame, anim_walk, m_animation_frame);
                if(m_animation_frame == 5) PlaySound(vine_boom);
                break;
        }
        DrawModelEx(murasame, m_position, Vector3{0.f, 0.f, 1.f}, m_rotation_angle.x*M_PI*18-180, Vector3{1.f, 1.f, 1.f}, GRAY);

        m_animation_frame++;
}

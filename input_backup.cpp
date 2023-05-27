#include "main_loop.hpp"
#include <raylib.h>

#include <iostream> 
#include <cmath>

void controller_test::input_loop() {
        Vector2 input_direction{0.f, 0.f};
        Vector2 input_look{0.f, 0.f};
        Vector3 movement_direction{0.f, 0.f, 0.f};

        input_direction.x = -GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y);
        input_direction.y = -GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X);

        if(IsKeyDown(KEY_W)) input_direction.x += 1;
        if(IsKeyDown(KEY_S)) input_direction.x -= 1;
        if(IsKeyDown(KEY_A)) input_direction.y += 1;
        if(IsKeyDown(KEY_D)) input_direction.y -= 1;

        if(IsKeyDown(KEY_Q) || IsKeyDown(KEY_LEFT)) {
                input_look.x += 1;
        }
        if(IsKeyDown(KEY_E) || IsKeyDown(KEY_RIGHT)) {
                input_look.x -= 1;
        }
        if(input_look != Vector2{}) {
                m_camera_target.x = m_camera_target.x*input_look.x*std::cos(m_look_sensitivity)  + m_camera_target.y*-input_look.x*std::sin(m_look_sensitivity);
                m_camera_target.y = m_camera_target.x*-input_look.x*std::sin(m_look_sensitivity) + m_camera_target.y*input_look.x*std::cos(m_look_sensitivity);
        }


        // Apply movement
        input_direction = Vector2Normalize(input_direction);
        movement_direction.x = input_direction.x*GetFrameTime()*m_movement_speed;
        movement_direction.y = input_direction.y*GetFrameTime()*m_movement_speed;
        m_position = m_position+movement_direction;
        // Camera location
        m_camera.target = m_position+m_camera_target;
        m_camera.target.z += m_camera_height;
        // Camera position
        m_camera.position = m_position+m_camera_offset;
        m_camera.position.z += m_camera_height;

        if(IsKeyPressed(KEY_SPACE) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) {
                PlaySound(vine_boom);
        }
}

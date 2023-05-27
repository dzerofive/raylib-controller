#include "main_loop.hpp"
#include <raylib.h>

#include <iostream> 
#include <cmath>

void controller_test::input_loop() {
        Vector2 input_look{0.f, 0.f};
        Vector3 movement_direction{0.f, 0.f, 0.f};

        m_input_direction.x = -GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y);
        m_input_direction.y = -GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X);

        // Gamepad Camera
        input_look.x += GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_X)*10;
        input_look.y += GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_Y)*10;
        // Mouse Camera
        input_look.x += GetMouseX() - m_mouse_position_past.x;
        input_look.y += GetMouseY() - m_mouse_position_past.y;

        m_forward_vector.x = m_camera_target.x*std::cos(m_look_sensitivity*-input_look.x) - m_camera_target.y*std::sin(m_look_sensitivity*-input_look.x);
        m_forward_vector.y = m_camera_target.x*std::sin(m_look_sensitivity*-input_look.x) + m_camera_target.y*std::cos(m_look_sensitivity*-input_look.x);
        m_camera_target.x = m_forward_vector.x;
        m_camera_target.y = m_forward_vector.y;

        // Update mouse offset for the next frame
        m_mouse_position_past.x = GetMouseX();
        m_mouse_position_past.y = GetMouseY();

        if(IsKeyDown(KEY_W)) m_input_direction = m_input_direction + m_forward_vector;
        if(IsKeyDown(KEY_S)) m_input_direction = m_input_direction + Vector2{-m_forward_vector.x, -m_forward_vector.y};
        if(IsKeyDown(KEY_A)) m_input_direction = m_input_direction + Vector2{-m_forward_vector.y, m_forward_vector.x};
        if(IsKeyDown(KEY_D)) m_input_direction = m_input_direction + Vector2{m_forward_vector.y, -m_forward_vector.x};
        m_input_direction = Vector2Normalize(m_input_direction);

        // Apply movement
        movement_direction.x = m_input_direction.x*GetFrameTime()*m_movement_speed;
        movement_direction.y = m_input_direction.y*GetFrameTime()*m_movement_speed;
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

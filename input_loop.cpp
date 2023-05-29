#include "main_loop.hpp"
#include "raymath_operators.hpp"
#include <raylib.h>

#include <iostream> 
#include <cmath>

inline Vector2 rotate(const Vector2& vec, const float degrees) {
        Vector2 res;
        res.x = vec.x*std::cos(degrees) - vec.y*std::sin(degrees);
        res.y = vec.x*std::sin(degrees) + vec.y*std::cos(degrees);
        return res;
}

void controller_test::input_loop() {
        if(IsKeyDown(KEY_UP)) m_camera_offset.y += 0.2;
        if(IsKeyDown(KEY_DOWN)) m_camera_offset.y -= 0.2;
        if(IsKeyDown(KEY_RIGHT)) {
                m_target_offset.z += 0.1;
                m_camera_offset.z += 0.1;
        }
        if(IsKeyDown(KEY_LEFT)) {
                m_target_offset.z = Clamp(m_target_offset.z-0.1f, -1.5f, 99999999.f);
                m_camera_offset.z = Clamp(m_camera_offset.z-0.1f, 0.5f, 99999999.f);
        }

        if(IsKeyDown(KEY_G)) {
                m_animation_frame = 0;
                m_animation_state = animation_states::walk;
        }

        // Mouse Camera
        Vector2 input_look{0.f, 0.f};
        input_look.x -= GetMouseX() - m_mouse_position_past.x;
        input_look.y += GetMouseY() - m_mouse_position_past.y;
        m_rotation_angle.x += input_look.x*m_look_sensitivity;
        // Update mouse offset for the next frame
        m_mouse_position_past.x = GetMouseX();
        m_mouse_position_past.y = GetMouseY();

        m_forward_vector = rotate(Vector2{0.f, 1.f}, m_rotation_angle.x);

        // Process and normalize
        m_input_direction = Vector2{};
        if(IsKeyDown(KEY_W)) m_input_direction = m_input_direction + m_forward_vector;
        if(IsKeyDown(KEY_S)) m_input_direction = m_input_direction + Vector2{-m_forward_vector.x, -m_forward_vector.y};
        if(IsKeyDown(KEY_A)) m_input_direction = m_input_direction + Vector2{-m_forward_vector.y, m_forward_vector.x};
        if(IsKeyDown(KEY_D)) m_input_direction = m_input_direction + Vector2{m_forward_vector.y, -m_forward_vector.x};
        m_input_direction = Vector2Normalize(m_input_direction);

        // Apply movement
        Vector3 movement_direction{0.f, 0.f, 0.f};
        movement_direction.x = m_input_direction.x*GetFrameTime()*m_movement_speed;
        movement_direction.y = m_input_direction.y*GetFrameTime()*m_movement_speed;
        m_position = m_position+movement_direction;

        // Apply camera
        m_camera.target = m_position+m_target_offset;
        Vector2 rotated_base = rotate(Vector2{m_camera_offset.x, m_camera_offset.y}, m_rotation_angle.x);
        m_camera.position = Vector3{rotated_base.x, rotated_base.y, m_camera_offset.z}+m_position;

        if(IsKeyPressed(KEY_SPACE) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) {
                PlaySound(vine_boom);
        }
}

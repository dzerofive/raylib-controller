#pragma once
#include <raylib.h>
#include <raymath.h>
#include <cstdint>


class controller_test {
public:
        controller_test();

        uint32_t target_fps;
        float fov = 80.f;

        void input_loop();
        void render3d_loop();
        void overlay_loop();
        void look_sensitivity(float s) {
                m_look_sensitivity = s;
        }
        Camera camera() { return m_camera; };


private:
        Sound vine_boom;

        // Mouse
        float   m_look_sensitivity = 0.005f;
        Vector2 m_mouse_position_past = Vector2{0.f, 0.f};

        // Locomotion
        float   m_movement_speed = 10.f;
        float   m_height = 1.7f;
        Vector2 m_input_direction{0.f, 0.f};
        Vector3 m_position = Vector3{4.f, 1.f, 0.f};

        // Camera
        Camera  m_camera;
        Vector2 m_forward_vector = Vector2{0.f, 0.f};
        Vector2 m_rotation_angle = Vector2{0.f, 0.f};
        Vector3 m_camera_offset = Vector3{0.f, -8.f, 4.f};
};

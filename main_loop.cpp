#include "main_loop.hpp"

controller_test::controller_test() {
        m_camera.up = Vector3{0.f, 0.f, 1.f};
        m_camera.fovy = fov;
        m_camera.projection = CAMERA_PERSPECTIVE;

        InitWindow(1280, 720, "Controller Test");
        InitAudioDevice();
        DisableCursor();
        vine_boom = LoadSound("sounds/sound.ogg");
        murasame = LoadModel("models/murasame.glb");
        murasame_ao = LoadTexture("textures/murasame_ao.png");
        murasame.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = murasame_ao;
}

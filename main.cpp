#include <raylib.h>
#include <string>
#include "main_loop.hpp"



int main(int argc, char** argv) {
        controller_test ct;
        
        if(argc==2) ct.look_sensitivity(std::stof(argv[1]));
        SetTargetFPS(90);
        while(!WindowShouldClose()) {
                ct.input_loop();
                BeginDrawing();
                ClearBackground(RAYWHITE);
                BeginMode3D(ct.camera());
                ct.render3d_loop();
                EndMode3D();
                ct.overlay_loop();
                EndDrawing();
        }
}

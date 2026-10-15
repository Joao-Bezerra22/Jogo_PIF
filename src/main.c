#include "raylib.h"
#define NUM_ESTRELAS 100

typedef struct {
    int x;
    int y;
} Estrelas;

int main(void) {
    InitWindow(800, 450, "Space Traffic");
    SetTargetFPS(60);

    Estrelas estrelas[NUM_ESTRELAS];

    for(int i = 0; i<NUM_ESTRELAS; i++){
        estrelas[i].x = GetRandomValue(0, GetScreenWidth());
        estrelas[i].y = GetRandomValue(0, GetScreenHeight());
    }

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            for(int i = 0; i<NUM_ESTRELAS; i++){
                DrawCircle(estrelas[i].x,estrelas[i].y, 1, WHITE);
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
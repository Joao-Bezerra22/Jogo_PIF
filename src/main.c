#include "raylib.h"
#include "cenario.h"

int main(void) {
    InitWindow(800, 450, "Space Traffic");
    SetTargetFPS(60);

    Estrela estrelas[NUM_ESTRELAS];
    iniciarEstrelas(estrelas);

    while (!WindowShouldClose()) {
        atualizarEstrelas(estrelas);

        BeginDrawing();
            ClearBackground(BLACK);
            desenharEstrelas(estrelas);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
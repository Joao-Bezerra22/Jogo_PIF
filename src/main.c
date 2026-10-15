#include "raylib.h"
#include "cenario.h"

typedef enum {
    TELA_INICIAL,
    JOGANDO
} EstadoJogo;

int main(void) {
    InitWindow(800, 450, "Space Traffic");
    SetTargetFPS(60);

    Estrela estrelas[NUM_ESTRELAS];
    iniciarEstrelas(estrelas);

    EstadoJogo estado = TELA_INICIAL;

    Rectangle botao = { (GetScreenWidth() - 200) / 2, 250, 200, 60 };

    while (!WindowShouldClose()) {
        atualizarEstrelas(estrelas);

        if (estado == TELA_INICIAL) {
        if (CheckCollisionPointRec(GetMousePosition(), botao) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        estado = JOGANDO;
    }
}

        BeginDrawing();
            ClearBackground(BLACK);
            desenharEstrelas(estrelas);

            if (estado == TELA_INICIAL) {
            DrawText("Space Traffic",215,130,50, WHITE);

            int larguraTitulo = MeasureText("Space Traffic", 50);
            DrawText("Space Traffic", (GetScreenWidth() - larguraTitulo) / 2, 130, 50, WHITE);

            DrawRectangleRec(botao, DARKGRAY);

            int larguraStart = MeasureText("START", 30);
            DrawText("START", botao.x + (botao.width - larguraStart) / 2, botao.y + 15, 30, WHITE);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
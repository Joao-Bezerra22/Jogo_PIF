#include "raylib.h"
#include "cenario.h"
#include "nave.h"
#include "asteroides.h"
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

    Nave nave;
    iniciarNave(&nave);

    Asteroide asteroides[MAX_ASTEROIDES] = {0};
    float tempoContagem = 3.0f;
    float tempoUltimoSpawn = 0.0f;

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        atualizarEstrelas(estrelas);
        if (estado == TELA_INICIAL) {
            if (CheckCollisionPointRec(GetMousePosition(), botao) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                estado = JOGANDO;
            }
        } 
        else if (estado == JOGANDO) {
            atualizarNave(&nave);

            if (tempoContagem > 0) {
                tempoContagem -= dt;
            } else {
                tempoUltimoSpawn += dt;
                
                if (tempoUltimoSpawn > 0.8f) { 
                    iniciarAsteroides(asteroides, MAX_ASTEROIDES);
                    tempoUltimoSpawn = 0.0f;
                }

                for (int i = 0; i < MAX_ASTEROIDES; i++) {
                    AsteroidAtualizar(&asteroides[i], dt);
                    if (asteroides[i].posicao.y > GetScreenHeight() + 100) {
                        asteroides[i].ativo = false;
                    }
                }
            }
        }

        BeginDrawing();
            ClearBackground(BLACK);
            desenharEstrelas(estrelas);

            if (estado == TELA_INICIAL) {

            int larguraTitulo = MeasureText("Space Traffic", 50);
            DrawText("Space Traffic", (GetScreenWidth() - larguraTitulo) / 2, 130, 50, WHITE);

            DrawRectangleRec(botao, DARKGRAY);

            int larguraStart = MeasureText("START", 30);
            DrawText("START", botao.x + (botao.width - larguraStart) / 2, botao.y + 15, 30, WHITE);
        }

        if(estado == JOGANDO){
            desenharNave(nave);

            if (tempoContagem > 0) {
                int numero = (int)(tempoContagem + 0.9f); 
                const char* textoTempo = TextFormat("%d", numero);
                int larguraTexto = MeasureText(textoTempo, 80);
                DrawText(textoTempo, (GetScreenWidth() - larguraTexto) / 2, GetScreenHeight() / 2 - 40, 80, RED);
            } else {
                desenharAsteroide(asteroides, MAX_ASTEROIDES);
            }
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
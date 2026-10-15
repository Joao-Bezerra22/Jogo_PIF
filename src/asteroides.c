#include "asteroides.h"
#include <raymath.h>

Asteroide criarAsteroide(AsteroideTipo tipo, Vector2 posicao, Vector2 velocidade)
{
    Asteroide asteroide = {
        .ativo = true,
        .posicao = posicao,
        .tipo = tipo,
        .rotacao = GetRandomValue(0, 360),
        .velocidaderotacao = GetRandomValue(ASTEROIDE_ROTACAO_VELOCIDADE_MIN, ASTEROIDE_ROTACAO_VELOCIDADE_MAX),
        .velocidade = velocidade
    };
};

void AsteroidAtualizar(Asteroide *asteroide, float FrameTime)
{
    asteroide->posicao = Vector2Add(asteroide->posicao,
        Vector2Scale(asteroide->velocidade, FrameTime));
    asteroide->rotacao += asteroide->velocidaderotacao * FrameTime;
}
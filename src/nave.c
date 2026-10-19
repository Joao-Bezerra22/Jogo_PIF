#include "nave.h"

void iniciarNave(Nave *nave) {
    nave->largura = 40;
    nave->altura = 40;
    nave->posicao.x = (GetScreenWidth() - nave->largura) / 2;
    nave->posicao.y = GetScreenHeight() - 40;
    nave->velocidade = 5;
}

void desenharNave(Nave nave) {
    DrawRectangle(nave.posicao.x, nave.posicao.y, nave.largura, nave.altura, WHITE);
}

void atualizarNave(Nave *nave) {
    if (IsKeyDown(KEY_LEFT)) {
        nave->posicao.x -= nave->velocidade;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        nave->posicao.x += nave->velocidade;
    }
}
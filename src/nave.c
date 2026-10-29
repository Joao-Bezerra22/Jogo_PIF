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

    if(IsKeyDown(KEY_UP)) {
        nave->posicao.y -= nave->velocidade;
    }

    if(IsKeyDown(KEY_DOWN)) {
        nave->posicao.y += nave->velocidade;
    }

    float limiteX = GetScreenWidth() - nave->largura;
    float limiteY = GetScreenHeight() - nave->altura;

    if (nave->posicao.x < 0)        nave->posicao.x = 0;
    if (nave->posicao.x > limiteX)  nave->posicao.x = limiteX;
    if (nave->posicao.y < 0)        nave->posicao.y = 0;
    if (nave->posicao.y > limiteY)  nave->posicao.y = limiteY;
}
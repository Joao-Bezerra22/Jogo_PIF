   jogo.exe: src/main.c
	gcc src/main.c -o jogo.exe -I C:\raylib\include -L C:\raylib\lib -lraylib -lopengl32 -lgdi32 -lwinmm

build:
	clang -lSDL -O3 src/main.c src/engine/*.c src/file/*.c src/gfx/*.c -o bin/game

#include <stdio.h>
#include "musiclib.h"
#include <raylib.h>

int main() {
	const int wx = 720, wy = 96;
	int padding = 12;

	InitWindow(720, 96, "AMP [Aqrypt Media Player]");
	SetTargetFPS(60);

	// Music
	char file[48];
	snprintf(file, 47, "%s/%s.mp3", dir, "euphoria");
	Music stream = LoadMusicStream(file);

	_Bool run = true;
	while (run) {
		BeginDrawing();

		ClearBackground(BLACK);
		DrawText("Paused", padding, padding, 32, WHITE);
		DrawRectangle(padding, wy - padding - 32, wx - padding * 2, wy - 32 - padding * 3, RED);

		EndDrawing();

		if (WindowShouldClose())
			run = false;
	}

	UnloadMusicStream(stream);
	CloseWindow();
}
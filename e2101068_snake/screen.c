#include "screen.h"
#include <stdio.h>
void resetColors(void) {
	printf("\033[0m");
	fflush(stdout);
}
void clearScreen(void) {
	printf("\033[2J");
	fflush(stdout);
}
void setBackground(int color) {
	printf("\033[%dm", color + 10);
	fflush(stdout);
}
void gotoXY(int x, int y) {
	printf("\033[%d;%dH", y, x);
	fflush(stdout);
}
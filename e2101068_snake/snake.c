#include "snake.h"
#include "screen.h"
#include <conio.h>

struct snake move(struct snake s, int dir) {
	struct snake ns;
	ns.length = s.length;
	ns.head = s.head;
	if (dir == UP) {
		ns.head.y--;
	}
	if (dir == LEFT) {
		ns.head.x--;
	}
	if (dir == RIGHT) {
		ns.head.x++;
	}
	if (dir == DOWN) {
		ns.head.y++;
	}
	ns.body[0] = s.head;
	for (int i = 1; i < s.length; i++) {
		ns.body[i] = s.body[i - 1];
	}return ns;
}
int input_key(void) {
	while (1) {
		int k = _getch();
		if (k == 224) {
			k = _getch();
			if (k == UP || k == LEFT || k == RIGHT || k == DOWN);
			return k;
		}
	}
}

struct snake init_snake(int len) {
	struct snake s;
	s.length = len;
	s.head.x = INITCOL;
	s.head.y = INITROW;
	for (int i = 0; i < len; i++) {
		s.body[i].x = INITCOL - 1 - i;
		s.body[i].y = INITROW;
	}
	return s;
 }

void draw(struct snake s) {
	clearScreen();
	setBackground(RED);
	gotoXY(s.head.x, s.head.y);
	printf(" ");
	setBackground(YELLOW);
	for (int i = 0; i < s.length; i++) {
		gotoXY(s.body[i].x, s.body[i].y);
		printf(" ");
	}
	resetColors();
}
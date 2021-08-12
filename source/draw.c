#include "core.h"
#include "geometry.h"
#include "BearLibTerminal.h"
#include "game.h"

#include <assert.h>

void
drawfill(int x, int y, int w, int h, color_t bg, color_t fg, int code)
{
	// TODO: Test to make sure this behaves appropriately!!!
	int hh;
	int vv;
	int termwidth;
	int termheight;
	int top;
	int right;
	int bottom;
	int left;
	color_t prevbg;
	color_t prevfg;

	/*
	if (w < 0) {
		int store;

		store = x;
		x = w;
		w = x;
	}

	if (h < 0) {
		int store;

		store = y;
		y = h;
		h = y;
	}*/

	termwidth = terminal_state(TK_WIDTH);
	termheight = terminal_state(TK_HEIGHT);
	prevbg = terminal_state(TK_BKCOLOR);
	prevfg = terminal_state(TK_COLOR);
	terminal_bkcolor(bg);
	terminal_color(fg);

	top = clamp(y, 0, termheight);
	right = clamp(x + w, x, termwidth);
	bottom = clamp(y + h, y, termheight);
	left = clamp(x, 0, termwidth);

	for (vv = top; vv < bottom; vv++) {
		for (hh = left; hh < right; hh++) {
			terminal_put(hh, vv, code);

			assert(hh >= 0);
			assert(hh < termwidth);
			assert(vv >= 0);
			assert(vv < termheight);
		}
	}

	terminal_bkcolor(prevbg);
	terminal_color(prevfg);
}

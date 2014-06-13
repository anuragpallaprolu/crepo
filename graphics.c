
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <dos.h>
#include "graphics.h"

void cursor(int x, int y) {
    union REGS r;

    r.h.ah = 2;
    r.h.bh = 0;
    r.h.dl = x;
    r.h.dh = y;
    int86(0x10, &r, &r);
}

void cursor_off(void) {
    union REGS inreg, outreg;
    inreg.h.ah = 1;
    inreg.x.cx = 0x0F00;

    int86(0x10, &inreg, &outreg);
}

void cursor_on(void) {
    union REGS inreg, outreg;
    inreg.h.ah = 1;
    inreg.x.cx = 0x0607;

    int86(0x10, &inreg, &outreg);
}

void clear_screen(void) {
    union REGS ireg;

    ireg.h.ah = 0x07;
    ireg.h.al = 0;
    ireg.h.ch = 0;
    ireg.h.cl = 0;
    ireg.h.dh = 24;
    ireg.h.dl = 79;
    ireg.h.bh = (0 << 4) | 7;

    int86(0x10, &ireg, &ireg);
}

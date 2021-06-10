#include <stdio.h>
#include <curses.h>
#include <unistd.h>

int main(void) {

    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    curs_set(0);

    char *rofl[] = {
        "           :ROFL:ROFL",
        "         _^___",
        "      __/   [] \\",
        "LOL===__        \\",
        "        \\________]",
        "         I   I",
        "        --------/",
        "  ROFL:ROFL",
        "         _^___",
        " L    __/   [] \\",
        " O ===__        \\",
        " L      \\________]",
        "         I   I",
        "        --------/"};
    int rofl_lines = 7;
    int rofl_cols = 18;

    int x = 0;
    int y = (LINES - rofl_lines)/2;
    int delay = 50;
    int nsteps = 2000/delay;

    for (int i = 0; i < nsteps; i++) {

        x = i*(COLS - rofl_cols)/nsteps;

        for (int j = 0; j < rofl_lines; j++) {
            mvaddstr(y + j, x, rofl[(i%2)*rofl_lines + j]);
        }

        refresh();
        usleep(delay*1000);

        clear();
    }

    endwin();
    return 0;
}

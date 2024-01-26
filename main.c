#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include "menu.h"

int main(int argc, char** argv) {
    Menu menu;
    char ch;
    char print_string[10000];
    char output_string[100];

    // Init ncurses
    FILE *f = fopen("/dev/tty", "r+");
    SCREEN *screen = newterm(NULL, f, f);
    set_term(screen);
    cbreak();
    noecho();
    refresh();

    init_menu(&menu, argv[1]);

    // initscr();
    // keypad(stdscr, TRUE);

    menu_to_string(&menu, print_string);

    print_menu(print_string);

    while ((ch = getch()) != '\n') {
        switch(ch) {
            case 'j':
                move_down(&menu);
                break;
            case 'k':
                move_up(&menu);
                break;

        }
        menu_to_string(&menu, print_string);
        print_menu(print_string);
    }
    endwin();

    get_current_item(&menu, output_string);

    fprintf(stdout, output_string);

    return 0;
}

int print_menu(char text[]) {
    mvprintw(0, 0, text);
    refresh();

    return 0;
}


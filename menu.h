#ifndef MENU_H
#define MENU_H

typedef struct {
    int line_count;
    int target_item;
    char lines[10000];
} Menu;

int init_menu(Menu *menu, char filepath[]);

int menu_to_string(Menu *menu, char *target_string);

int move_up(Menu *menu);

int move_down(Menu *menu);

int get_current_item(Menu *menu, char *target_string);

#endif //MENU_H

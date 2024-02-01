#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

int init_menu(Menu *menu, char filepath[]) {
    FILE *fp = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;

    if (fp == NULL)
        return 1;

    menu->line_count = 1;
    while (!feof(fp)) {
        menu->lines[i] = fgetc(fp);
        if (menu->lines[i] == '\n')
            menu->line_count = menu->line_count + 1;
        i = i+1;
    }

    fclose(fp);
    if (line)
        free(line);

    menu->target_item = 0;

    return 0;
}

int menu_to_string(Menu *menu, char *target_string) {
    char* lines = menu->lines;
    int current_item = 0;
    int target_item = menu->target_item;
    int current_index = 0;

    for (int i = 0; lines[i] != '\0'; i++) {
        target_string[current_index] = lines[i];
        current_index = current_index + 1;
        if (lines[i] == '\n') {
            current_item = current_item + 1;
            target_string[current_index] = ' ';
            current_index = current_index + 1;
            if (current_item == target_item) {
                target_string[current_index] = '>'; 
                current_index = current_index + 1;
            }
            else {
                target_string[current_index] = ' '; 
                current_index = current_index + 1;
            }
        }
    }

    return 0;
}

int move_up(Menu *menu) {
    int new_item = menu->target_item - 1;

    if (new_item < 0)
        new_item = new_item + menu->line_count;

    menu->target_item = new_item;

    return 0;
}

int move_down(Menu *menu) {
    menu->target_item = (menu->target_item + 1) % menu->line_count;

    return 0;
}

int get_current_item(Menu *menu, char *output_string) {
    int target_item = menu->target_item;
    int current_item = 0;
    int current_index = 0;

    int i = 0;

    while (menu->lines[i] != '\0' && current_item < target_item) {
        if (menu->lines[i] == '\n')
            current_item = current_item + 1;
        i = i + 1;
    }

    while (menu->lines[i] != ':' && menu->lines[i] != '\n') {
        output_string[current_index] = menu->lines[i];
        current_index = current_index + 1;
        i = i + 1;
    }


    // for (int i=0; menu->lines[i] != '\0' && current_item <=target_item; i++) {
    //     if (menu->lines[i] == '\n')
    //         current_item = current_item + 1;
    //     if (current_item == target_item) {
    //         output_string[current_index] = menu->lines[i];
    //         current_index = current_index + 1;
    //     }
    // }

    return 0;
}

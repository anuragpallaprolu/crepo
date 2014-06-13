
/* fill, repeat */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include "graphics.h"

enum {
    MAZE_BLANK,
    MAZE_WALL,
    MAZE_KEY,
    MAZE_NOKEY,
    MAZE_DOOR,
    MAZE_FINISH
};

struct sq_t {
    unsigned type : 4;
    unsigned ex : 1;
    char data;
};

struct maze_t {
    unsigned exists : 2;
    int xp, yp;
    struct sq_t sq[80][22];
} maze[13];

void main_screen(void);
void start_game(char *fn);
void start_edit(char *fn);

int read_in_mazes(FILE *fp);
void clear_mazes(void);
void play_game(void);
void play_move(int x, int y);

void edit_game(FILE *fp);

void message(char *s);
void chomp(char *s);

int main(void) {
    main_screen();

    clear_screen();
    cursor(0, 0);
    printf("Thanks for playing tmaze! :)\n");
    return 0;
}

void main_screen(void) {
    int c, quit = 0;
    char file[70];
    size_t filelen = 0;

    file[0] = 0;

    while(!quit) {
        clear_screen();
        cursor_on();
        cursor(30, 1);
        printf("TMAZE by DWK");
        
        cursor(5, 20);
        printf("%s", file);
            
        switch((c=getch())) {
        case 0:  /* extended key */
            switch((c=getch())) {
            /*case 72:  /* up */
            }
            /*cursor(0, 1);
            printf("%3i", c);*/
            break;
        case 27: quit = 1; break;  /* esc */
        case '\b':
            if(filelen > 0) {
                file[--filelen] = 0;
            }
            break;
        case '\r':
            start_game(file);
            break;
        case 10: /* ctrl-enter */
            start_edit(file);
            break;
        default:
            if(isprint(c) && filelen < 70) {
                file[filelen++] = c;
                file[filelen] = 0;
            }
        }
    }
}

void start_game(char *fn) {
    char s[20];
    FILE *fp;

    if((fp=fopen(fn, "rt")) == NULL) {
        message("Can't open file");
        return;
    }

    fgets(s, sizeof(s), fp);
    chomp(s);
    if(strcmp(s, "TMAZE")) {
        message("Invalid map file (doesn't have signature)");
        return;
    }

    if(read_in_mazes(fp)) {
        fclose(fp);
        return;
    }
    
    play_game();

    fclose(fp);
}

void start_edit(char *fn) {
    char s[20];
    FILE *fp;

    if((fp=fopen(fn, "r+t")) == NULL) {
        message("Creating new map");

        clear_mazes();
    }
    else {
        fgets(s, sizeof(s), fp);
        chomp(s);
        if(strcmp(s, "TMAZE")) {
            message("Invalid map file (doesn't have signature)");
            return;
        }

        if(read_in_mazes(fp)) {
            fclose(fp);
            return;
        }

        fclose(fp);
    }

    if((fp=fopen(fn, "wt")) == NULL) {
        message("Can't make file");
        return;
    }
    
    edit_game(fp);

    fclose(fp);
}

int read_in_mazes(FILE *fp) {
    char c;
    int x, y, z, m;

    for(z = 0; z < 13; z ++) {
        maze[z].exists = 0;
        maze[z].xp = maze[z].yp = 0;
        for(x = 0; x < 80; x ++) {
            for(y = 0; y < 22; y ++) {
                maze[z].sq[x][y].type = MAZE_BLANK;
            }
        }
    }

    clear_screen();
    cursor_on();
    cursor(0, 0);
    printf("\nLoading file . . .");
    
    while(!feof(fp)) {
        c = getc(fp);
        if(feof(fp)) break;

        if((x=getc(fp)) != '\n') {
            printf("Expected '\\n', found '%c'", x);
            getch();
            return 1;
        }

        m = (isupper(c)?c-'A':c-'a'+26);

        maze[m].exists = 1;

        for(x = y = 0; y < 22; ) {
            c = getc(fp);
            if(feof(fp)) break;

            if(x >= 80 && c != '\n') continue;

            if(c == '.') maze[m].sq[x][y].type = MAZE_WALL;
            else if(c == ' ') ;
            else if(c == '+') {
                maze[m].sq[x][y].type = MAZE_KEY;
                c = getc(fp);
                maze[m].sq[x][y].data = (isupper(c)?c-'A':c-'a'+26);
            }
            else if(c == '-') {
                maze[m].sq[x][y].type = MAZE_DOOR;
                c = getc(fp);
                maze[m].sq[x][y].data = (isupper(c)?c-'A':c-'a'+26);
            }
            else if(c == '>') {
                maze[m].sq[x][y].type = MAZE_FINISH;
                c = getc(fp);
                maze[m].sq[x][y].data = (c=='>'?-1:(isupper(c)?c-'A':c-'a'+26));
            }
            else if(isspace(c)) ;
            else if(c == ':') {
                maze[m].xp = x, maze[m].yp = y;
            }
            
            if(c == '\n') y ++, x = 0;
            else x ++;
        }
    }

    return 0;
}

void clear_mazes(void) {
    char c;
    int x, y, z, m;

    for(z = 0; z < 13; z ++) {
        maze[z].exists = 0;
        maze[z].xp = maze[z].yp = 0;
        for(x = 0; x < 80; x ++) {
            for(y = 0; y < 22; y ++) {
                maze[z].sq[x][y].type = MAZE_BLANK;
            }
        }
    }
}

void play_game(void) {
    int quit = 0, key[52], m = 0;
    int x, y, z, c, xp, yp;

    while(!quit && m >= 0) {
        xp = maze[m].xp, yp = maze[m].yp;

        for(x = 0; x < 52; x ++) key[x] = 0;
        
        for(x = 0; x < 80; x ++) {
            for(y = 0; y < 22; y ++) {
                maze[m].sq[x][y].ex = 0;
            }
        }

        clear_screen();
        cursor(0, 0);

        for(x = 0; x < 80; x ++) {
            printf("\260\260\260\260\260\260\260\260\260\260"
                "\260\260\260\260\260\260\260\260\260\260\260\260");
        }

        cursor_off();

        while(!quit) {
            cursor(0, 0);
    
            if(xp > 0) maze[m].sq[xp-1][yp].ex = 1;
            if(yp > 0) maze[m].sq[xp][yp-1].ex = 1;
            if(xp < 79) maze[m].sq[xp+1][yp].ex = 1;
            if(yp < 21) maze[m].sq[xp][yp+1].ex = 1;
            
            if(xp > 0 && yp > 0) maze[m].sq[xp-1][yp-1].ex = 1;
            if(xp > 0 && yp < 21) maze[m].sq[xp-1][yp+1].ex = 1;
            if(xp < 79 && yp > 0) maze[m].sq[xp+1][yp-1].ex = 1;
            if(xp < 79 && yp < 21) maze[m].sq[xp+1][yp+1].ex = 1;
    
            z = xp-1;
            if(z < 0) z = 0;
    
            for(y = yp-1 < 0 ? 0 : yp-1; y < yp+2 && y < 22; y ++) {
                cursor(z, y);
                
                for(x = z; x < xp+2 && x < 80; x ++) {
                    if(x == xp && y == yp) printf("\017");
                    else if(maze[m].sq[x][y].ex) {
                        switch(maze[m].sq[x][y].type) {
                        case MAZE_BLANK: printf(" "); break;
                        case MAZE_KEY: printf("\013"); break;
                        case MAZE_NOKEY: printf("\372"); break;
                        case MAZE_DOOR: printf("\376"); break;
                        case MAZE_FINISH: printf("\257"); break;
                        default: printf("\333"); break;
                        }
                    }
                }
            }
    
            switch((c=getch())) {
            case 0:  /* extended */
                switch((c=getch())) {
                case 72:  /* up */
                    if(yp > 0) {
                        switch(maze[m].sq[xp][yp-1].type) {
                        case MAZE_FINISH:
                            m = maze[m].sq[xp][yp-1].data;
                            quit = 1;
                            break;
                        case MAZE_NOKEY:
                        case MAZE_BLANK: yp --; break;
                        case MAZE_WALL: break;
                        case MAZE_KEY:
                            yp --;
                            key[maze[m].sq[xp][yp].data] = 1;
                            maze[m].sq[xp][yp].type = MAZE_NOKEY;
                            break;
                        case MAZE_DOOR:
                            if(key[maze[m].sq[xp][yp-1].data]) yp --;
                            break;
                        }
                    }
                    break;
                case 80:  /* down */
                    if(yp < 21) {
                        switch(maze[m].sq[xp][yp+1].type) {
                        case MAZE_FINISH:
                            m = maze[m].sq[xp][yp+1].data;
                            quit = 1;
                            break;
                        case MAZE_NOKEY:
                        case MAZE_BLANK: yp ++; break;
                        case MAZE_WALL: break;
                        case MAZE_KEY:
                            yp ++;
                            key[maze[m].sq[xp][yp].data] = 1;
                            maze[m].sq[xp][yp].type = MAZE_NOKEY;
                            break;
                        case MAZE_DOOR:
                            if(key[maze[m].sq[xp][yp+1].data]) yp ++;
                            break;
                        }
                    }
                    break;
                case 75:  /* left */
                    if(xp > 0) {
                        switch(maze[m].sq[xp-1][yp].type) {
                        case MAZE_FINISH:
                            m = maze[m].sq[xp-1][yp].data;
                            quit = 1;
                            break;
                        case MAZE_NOKEY:
                        case MAZE_BLANK: xp --; break;
                        case MAZE_WALL: break;
                        case MAZE_KEY:
                            xp --;
                            key[maze[m].sq[xp][yp].data] = 1;
                            maze[m].sq[xp][yp].type = MAZE_NOKEY;
                            break;
                        case MAZE_DOOR:
                            if(key[maze[m].sq[xp-1][yp].data]) xp --;
                            break;
                        }
                    }
                    break;
                case 77:  /* right */
                    if(xp < 79) {
                        switch(maze[m].sq[xp+1][yp].type) {
                        case MAZE_FINISH:
                            m = maze[m].sq[xp+1][yp].data;
                            quit = 1;
                            break;
                        case MAZE_NOKEY:
                        case MAZE_BLANK: xp ++; break;
                        case MAZE_WALL: break;
                        case MAZE_KEY:
                            xp ++;
                            key[maze[m].sq[xp][yp].data] = 1;
                            maze[m].sq[xp][yp].type = MAZE_NOKEY;
                            break;
                        case MAZE_DOOR:
                            if(key[maze[m].sq[xp+1][yp].data]) xp ++;
                            break;
                        }
                    }
                    break;
                }
                break;
            case 27: quit = 2; break;  /* esc */
            }
    
            /*cursor(0, 24);
            printf("%3i", c);*/
        }
        
        quit --;
    }

    cursor_on();
}

void edit_game(FILE *fp) {
    int quit = 0, m = 0;
    int x, y, z, a, c, xp, yp;

    while(!quit && m >= 0) {
        xp = maze[m].xp, yp = maze[m].yp;

        clear_screen();
        cursor(0, 0);

        for(y = 0; y < 22; y ++) {
            cursor(0, y);
                
            for(x = 0; x < 80; x ++) {
                if(x == xp && y == yp) printf("\017");
                else if(x == maze[m].xp && y == maze[m].yp) printf("\001");
                else {
                    switch(maze[m].sq[x][y].type) {
                    case MAZE_BLANK: printf(" "); break;
                    case MAZE_KEY: printf("\013"); break;
                    /*case MAZE_NOKEY: printf("\372"); break;*/
                    case MAZE_DOOR: printf("\376"); break;
                    case MAZE_FINISH: printf("\257"); break;
                    default: printf("\333"); break;
                    }
                }
            }
        }

        cursor_off();

        while(!quit) {
            cursor(0, 0);
    
            if(xp > 0) maze[m].sq[xp-1][yp].ex = 1;
            if(yp > 0) maze[m].sq[xp][yp-1].ex = 1;
            if(xp < 79) maze[m].sq[xp+1][yp].ex = 1;
            if(yp < 21) maze[m].sq[xp][yp+1].ex = 1;
            if(xp > 0 && yp > 0) maze[m].sq[xp-1][yp-1].ex = 1;
            if(xp > 0 && yp < 21) maze[m].sq[xp-1][yp+1].ex = 1;
            if(xp < 79 && yp > 0) maze[m].sq[xp+1][yp-1].ex = 1;
            if(xp < 79 && yp < 21) maze[m].sq[xp+1][yp+1].ex = 1;
    
            z = xp-1;
            if(z < 0) z = 0;
    
            for(y = yp-1 < 0 ? 0 : yp-1; y < yp+2 && y < 22; y ++) {
                cursor(z, y);
                
                for(x = z; x < xp+2 && x < 80; x ++) {
                    if(x == xp && y == yp) printf("\017");
                    else if(x == maze[m].xp && y == maze[m].yp) printf("\001");
                    else {
                        switch(maze[m].sq[x][y].type) {
                        case MAZE_BLANK: printf(" "); break;
                        case MAZE_KEY: printf("\013"); break;
                        /*case MAZE_NOKEY: printf("\372"); break;*/
                        case MAZE_DOOR: printf("\376"); break;
                        case MAZE_FINISH: printf("\257"); break;
                        default: printf("\333"); break;
                        }
                    }
                }
            }

            cursor(0, 22);
            printf("MAZE %c    ", m+'A');

            switch(maze[m].sq[xp][yp].type) {
            case MAZE_KEY:
                printf("Key %c ", maze[m].sq[xp][yp].data < 26 ?
                    maze[m].sq[xp][yp].data + 'A'
                    : maze[m].sq[xp][yp].data + 'a' - 26);
                break;
            case MAZE_DOOR:
                printf("Door %c", maze[m].sq[xp][yp].data < 26 ?
                    maze[m].sq[xp][yp].data + 'A'
                    : maze[m].sq[xp][yp].data + 'a' - 26);
                break;
            case MAZE_FINISH:
                printf("Fin %c ", maze[m].sq[xp][yp].data < 0 ?
                    '>' : maze[m].sq[xp][yp].data + 'A');
                break;
            default: printf("      "); break;
            }
    
            switch((c=getch())) {
            case 0:  /* extended */
                switch((c=getch())) {
                case 72:  /* up */
                    if(yp > 0) yp --;
                    break;
                case 80:  /* down */
                    if(yp < 21) yp ++;
                    break;
                case 75:  /* left */
                    if(xp > 0) xp --;
                    break;
                case 77:  /* right */
                    if(xp < 79) xp ++;
                    break;
                case 15:  /* shift-tab */
                    if(m > 0) {
                        m --;
                        quit = 1;
                    }
                    break;
                }
                break;
            case 27: quit = 2; break;  /* esc */
            case ' ': maze[m].sq[xp][yp].type = MAZE_BLANK; break;
            case '.': maze[m].sq[xp][yp].type = MAZE_WALL; break;
            case '+':
                maze[m].sq[xp][yp].type = MAZE_KEY;
                while(!isalpha(c = getch())) ;
                maze[m].sq[xp][yp].data = (isupper(c) ? c-'A' : c-'a'+26);
                break;
            case '-':
                maze[m].sq[xp][yp].type = MAZE_DOOR;
                while(!isalpha(c = getch())) ;
                maze[m].sq[xp][yp].data = (isupper(c) ? c-'A' : c-'a'+26);
                break;
            case '>':
                maze[m].sq[xp][yp].type = MAZE_FINISH;
                c = getch();
                maze[m].sq[xp][yp].data = (c>='A' && c<='M' ? c-'A' : -1);
                break;
            case 's':
                cursor(maze[m].xp, maze[m].yp);
                printf(" ");
                maze[m].xp = xp, maze[m].yp = yp;
                maze[m].sq[xp][yp].type = MAZE_BLANK;
                break;
            case 'l':
                for(x = 0; x < 80; x ++) {
                    for(y = 0; y < 22; y ++) {
                        if(maze[m].sq[x][y].type == MAZE_DOOR ||
                            maze[m].sq[x][y].type == MAZE_KEY) {

                            cursor(x, y);
                            printf("%c", maze[m].sq[x][y].data < 26 ?
                                maze[m].sq[x][y].data + 'A' :
                                maze[m].sq[x][y].data + 'a'-26);
                        }
                    }
                }

                getch();

                for(x = 0; x < 80; x ++) {
                    for(y = 0; y < 22; y ++) {
                        if(maze[m].sq[x][y].type == MAZE_DOOR) {
                            cursor(x, y);
                            printf("\376");
                        }
                        else if(maze[m].sq[x][y].type == MAZE_KEY) {
                            cursor(x, y);
                            printf("\013");
                        }
                    }
                }
                
                break;
            case '\t':
                if(m < 13) {
                    m ++;
                    quit = 1;
                }
                break;
            }

            /*cursor(0, 24);
            printf("%3i", c);*/
        }
        
        quit --;
    }

    fputs("TMAZE\n", fp);
    for(z = 0; z < 13; z ++) {
        for(x = 0; x < 80; x ++) {
            for(y = 0; y < 22; y ++) {
                if(maze[z].sq[x][y].type != MAZE_BLANK) x = 81;
            }
        }

        if(x > 80) {
            putc(z+'A', fp);
            putc('\n', fp);
            
            for(y = 0; y < 22; y ++) {
                for(a = 79; a >= 0; a --) {
                    if(maze[z].sq[a][y].type != MAZE_BLANK ||
                        (maze[z].xp == a && maze[z].yp == y)) break;
                }

                for(x = 0; x <= a; x ++) {
                    if(x == maze[z].xp && y == maze[z].yp) putc(':', fp);
                    else switch(maze[z].sq[x][y].type) {
                    case MAZE_BLANK: putc(' ', fp); break;
                    case MAZE_WALL: putc('.', fp); break;
                    case MAZE_KEY: case MAZE_NOKEY:
                        putc('+', fp);
                        putc(maze[z].sq[x][y].data < 26 ?
                            maze[z].sq[x][y].data + 'A' :
                            maze[z].sq[x][y].data + 'a'-26, fp);
                        break;
                    case MAZE_DOOR:
                        putc('-', fp);
                        putc(maze[z].sq[x][y].data < 26 ? maze[z].sq[x][y].data + 'A' :
                            maze[z].sq[x][y].data + 'a'-26, fp);
                        break;
                    case MAZE_FINISH:
                        putc('>', fp);
                        if(maze[z].sq[x][y].data == -1) putc('>', fp);
                        else putc(maze[z].sq[x][y].data + 'A', fp);
                        break;
                    }
                }

                putc('\n', fp);
            }
        }
    }

    cursor_on();
}

void message(char *s) {
    cursor_off();
    clear_screen();
    cursor(10, 10);
    printf("%s", s);
    getch();
    cursor_on();
}

void chomp(char *s) {
    while(*s && *s != '\n' && *s != '\r') s++;

    *s = 0;
}

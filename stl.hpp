//
// Created by Philipp Steckenbauer on 14.10.18.
//

#ifdef _WIN32
#error Windows not supported!
#endif

#ifndef STL_HPP
#define STL_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

namespace stl {
    //Defines for STL Color Attributes
    #define STLCA_DEFAULT             "\033[0m"
    #define STLCA_BOLD                "\033[1m"
    #define STLCA_DIM                 "\033[2m"
    #define STLCA_UNDERLINED          "\033[3m"
    #define STLCA_BLINK               "\033[5m"
    #define STLCA_REVERSE             "\033[7m"
    #define STLCA_HIDDEN              "\033[8m"

    //Defines for STL Color Foregrounds
    #define STLCF_RESET               "\033[39m"
    #define STLCF_BLACK               "\033[30m"
    #define STLCF_RED                 "\033[31m"
    #define STLCF_GREEN               "\033[32m"
    #define STLCF_YELLOW              "\033[33m"
    #define STLCF_BLUE                "\033[34m"
    #define STLCF_MAGENTA             "\033[35m"
    #define STLCF_CYAN                "\033[36m"
    #define STLCF_LIGHTGRAY           "\033[37m"
    #define STLCF_DARKGRAY            "\033[90m"
    #define STLCF_LIGHTRED            "\033[91m"
    #define STLCF_LIGHTGREEN          "\033[92m"
    #define STLCF_LIGHTYELLOW         "\033[93m"
    #define STLCF_LIGHTBLUE           "\033[94m"
    #define STLCF_LIGHTMAGENTA        "\033[95m"
    #define STLCF_LIGHTCYAN           "\033[96m"
    #define STLCF_WHITE               "\033[97m"

    //Defines for STL Color Backgrounds
    #define STLCB_RESET               "\033[49m"
    #define STLCB_BLACK               "\033[40m"
    #define STLCB_RED                 "\033[41m"
    #define STLCB_GREEN               "\033[42m"
    #define STLCB_YELLOW              "\033[43m"
    #define STLCB_BLUE                "\033[44m"
    #define STLCB_MAGENTA             "\033[45m"
    #define STLCB_CYAN                "\033[46m"
    #define STLCB_LIGHTGRAY           "\033[47m"
    #define STLCB_DARKGRAY            "\033[100m"
    #define STLCB_LIGHTRED            "\033[101m"
    #define STLCB_LIGHTGREEN          "\033[102m"
    #define STLCB_LIGHTYELLOW         "\033[103m"
    #define STLCB_LIGHTBLUE           "\033[104m"
    #define STLCB_LIGHTMAGENTA        "\033[105m"
    #define STLCB_LIGHTCYAN           "\033[106m"
    #define STLCB_WHITE               "\033[107m"

    //Defines for STL Color Reset
    #define STLCR_ALL                 "\033[0m"
    #define STLCR_BOLD                "\033[21m"
    #define STLCR_DIM                 "\033[22m"
    #define STLCR_UNDERLINED          "\033[24m"
    #define STLCR_BLINK               "\033[25m"
    #define STLCR_REVERSE             "\033[27m"
    #define STLCR_HIDDEN              "\033[28m"

    char getch(void);
    char getche(void);

    unsigned int width();
    unsigned int heigth();

    void gotoxy(unsigned int x, unsigned int y);
    unsigned int getx();
    unsigned int gety();

    void clrscr();
    void clearscreen();
    void clearline();

    void cursoron();
    void cursoroff();
    void cursorup(unsigned int c);
    void cursordown(unsigned int c);
    void cursorleft(unsigned int c);
    void cursorright(unsigned int c);
    void cursorsave();
    void cursorrestore();
};


#endif //STL_STL_HPP

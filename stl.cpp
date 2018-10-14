//
// Created by Philipp Steckenbauer on 14.10.18.
//

#include "stl.hpp"

char stl::getch(void) {
    struct termios oldattributes, newattributes;
    int character;

    tcgetattr( STDIN_FILENO, &oldattributes);
    newattributes = oldattributes;
    newattributes.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattributes);
    character = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattributes);

    return character;
}

char stl::getche(void) {
    struct termios oldattributes, newattributes;
    int character;

    tcgetattr( STDIN_FILENO, &oldattributes);
    newattributes = oldattributes;
    newattributes.c_lflag &= ~(ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattributes);
    character = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattributes);

    return character;
}

unsigned int stl::width() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    return w.ws_col;
}
unsigned int stl::heigth() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    return w.ws_row;
}

void stl::gotoxy(unsigned int x, unsigned int y) {
    std::cout << "\033[" << y << ";" << x << "H";
}

unsigned int stl::gety() {
    std::string s, y;

    std::cout << "\033[6n";

    for(unsigned char key = 0; key != 'R';) {
        key = stl::getch();

        s.push_back(key);
    }

    for(unsigned int i = 0; i < s.length(); i++) {
        if(s[i] == '[') {
            for(i++; s[i] != ';' && i < s.length(); i++) {
                y.push_back(s[i]);
            }
        }
    }

    std::stringstream sstr(y);
    unsigned int coord_y;
    sstr >> coord_y;

    return coord_y - 1;
}

unsigned int stl::getx() {
    std::string s, x;

    std::cout << "\033[6n";

    for(unsigned char key = 0; key != 'R';) {
        key = stl::getch();

        s.push_back(key);
    }

    for(unsigned int i = 0; i < s.length(); i++) {
        if(s[i] == ';') {
            for(i++; s[i] != 'R' && i < s.length(); i++) {
                x.push_back(s[i]);
            }
        }
    }

    std::stringstream sstr(x);
    unsigned int coord_x;
    sstr >> coord_x;

    return coord_x - 1;
}


void stl::clrscr() {
    std::cout << "\033[2J";
}
void stl::clearscreen() {
    std::cout << "\033[2J";
}
void stl::clearline() {
    std::cout << "\033[K";
}

void stl::cursoron() {
    system("setterm -cursor on");
}
void stl::cursoroff() {
    system("setterm -cursor off");
}
void stl::cursorup(unsigned int c) {
    std::cout << "\033[" << c << "A";
}
void stl::cursordown(unsigned int c) {
    std::cout << "\033[" << c << "B";
}
void stl::cursorleft(unsigned int c) {
    std::cout << "\033[" << c << "D";
}
void stl::cursorright(unsigned int c) {
    std::cout << "\033[" << c << "C";
}
void stl::cursorsave() {
    std::cout << "\033[s";
}
void stl::cursorrestore() {
    std::cout << "\033[u";
}

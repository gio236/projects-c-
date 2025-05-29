#include <ncurses.h>
#include <fstream>
#include <string>
#include <vector>
#include <signal.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

void disableFlowControl() {
    termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_iflag &= ~(IXON);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

int main() {
    signal(SIGINT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);

    vector<string> righe;
    vector<string> righe1;
    int x;
    int y;
    int ch;

    cout << "1. create new file\n2. open file\n";
    string choice;
    cin >> choice;

    if(choice == "1"){
        cout << "enter file name : ";
        string Nomefile;
        cin >> Nomefile;
        system("clear");

        x = 0;
        y = 0;
        righe.push_back("");

        initscr();
        noecho();
        keypad(stdscr, TRUE);
        cbreak();
        disableFlowControl();
        nodelay(stdscr, TRUE);

        while((ch = getch()) != 24){
            if(x >= 212){
                x = 0;
                y++;
                righe.push_back("");
                move(y,x);
                refresh();
            }
            if(ch == KEY_UP){
                if(y > 0){
                    y--;
                    if(y < righe.size()){
                        x = righe[y].length();
                    }
                    move(y, x);
                }
            }else if(ch == KEY_DOWN){
                if (y < LINES - 1) {
                    y += 1;
                    x = righe[y].length();
                    if(y >= righe.size()){
                        x = 0;
                        righe.push_back("");
                    }
                    move(y,x);
                    refresh();
                }
            }else if(ch == KEY_LEFT){
                if(x > 0){
                    x--;
                    move(y, x);
                }else if (x == 0 && y > 0){
                    y--;
                    x = righe[y].length();
                    move(y, x);
                }
            }else if(ch == KEY_RIGHT){
                if(x < COLS - 1) x++;
                move(y, x);
            }

            if(ch == 23){
                ofstream file(Nomefile);
                if(file.is_open()){
                    for(int i = 0; i < righe.size(); i++){
                        file << righe[i] << endl;
                    }
                    file.close();
                }else{
                    x = 0;
                    mvprintw(x, y +10, "ERR");
                    refresh();
                }
                mvprintw(LINES - 1, COLS / 2 + 5, "S");
                refresh();
            }

            if(ch == '\n'){
                y++;
                if(righe.size() > y){
                    x = righe[y].length();	
                    move (y,x);
                    refresh();
                }else{
                    righe.push_back("");	
                    x = 0;
                    move (y,x);
                    refresh();
                }
            }else if(ch == KEY_BACKSPACE || ch == 127){
                if(x > 0){
                    x--;
                    righe[y].pop_back();
                    mvaddch(y, x, ' ');
                    move(y, x);
                }else if (x == 0 && y > 0){
                    y--;
                    x = righe[y].length();
                    move(y, x);
                }
            }else if(isprint(ch)){
                righe[y] += (char)ch;
                mvaddch(y, x, ch);
                x++;
            }
        }
        endwin();
    }else if(choice == "2"){
        cout << "enter file name : ";
        string Nomefile;
        cin >> Nomefile;
        vector<string> righe1;

        ifstream file(Nomefile);
        if(file.is_open()){
            string line;
            while(getline(file, line)){
                righe1.push_back(line);
            }
            file.close();
        }

        initscr();
        noecho();
        keypad(stdscr, TRUE);
        cbreak();
        disableFlowControl();

        for(int i = 0; i < righe1.size(); i++){
            mvprintw(i, 0, "%s", righe1[i].c_str());
        }

        y = righe1.size();
        x = 0;
        righe1.push_back("");
        move(y,x);
        refresh();

        while((ch = getch()) != 24){
            if(ch == KEY_UP){
                if(y > 0){
                    y--;
                    if(y < righe1.size()){
                        x = righe1[y].length();
                    }
                    move(y, x);
                }
            }else if(ch == KEY_DOWN){
                if (y < LINES - 1) {
                    y += 1;
                    x = righe1[y].length();	
                    if(y >= righe1.size()){
                        x = 0;
                        righe1.push_back("");
                    }
                    move(y,x);
                    refresh();
                }
            }else if(ch == KEY_LEFT){
                if(x > 0){
                    x--;
                    move(y, x);
                }else if (x == 0 && y > 0){
                    y--;
                    x = righe1[y].length();
                    move(y, x);
                }
            }else if(ch == KEY_RIGHT){
                if(x < COLS - 1) x++;
                move(y, x);
            }

            if(x >= 212){
                x = 0;
                y++;
                righe1.push_back("");
                move(y,x);
                refresh();		
            }

            if(ch == 23){
                ofstream file(Nomefile);
                if(file.is_open()){
                    for(int i = 0; i < righe1.size(); i++){
                        file << righe1[i] << endl;
                    }
                    file.close();
                }else{
                    x = 0;
                    mvprintw(x, y + 10, "ERR");
                    refresh();
                }
                mvprintw(LINES - 1, COLS / 2 + 5, "S");
                refresh();
            }

            if(ch == '\n'){
                y++;
                if(righe1.size() > y){
                    x = righe1[y].length();	
                    move (y,x);
                    refresh();
                }else{
                    righe1.push_back("");	
                    x = 0;
                    move (y,x);
                    refresh();
                }	
            }else if(ch == KEY_BACKSPACE || ch == 127){
                if(x > 0){
                    x--;
                    righe1[y].pop_back();
                    mvaddch(y, x, ' ');
                    move(y, x);
                }else if (x == 0 && y > 0){
                    y--;
                    x = righe1[y].length();
                    move(y, x);
                }
            }else if(isprint(ch)){
                righe1[y] += (char)ch;
                mvaddch(y, x, ch);
                x++;
            }
        }
        endwin();
    }
}

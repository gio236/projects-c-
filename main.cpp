#include <fstream>
#include <string>
#include <vector>
#include <signal.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <ncurses.h>

//tasks x codice : 
//FATTO implementare overlow delle righe e delle colonne in automatico cioè x >=  COL , 
//DA FARE implementare anche es : ./main ciao.txt per aprire file , scopirire in giro :| , anche scorrimento automatico linee quando y > LINES
//scrivere in uno stato x , mandando avanti di uno in uno stato x+=1 


void disableFlowControl() {
    termios t;				// dichiara t per salvare la configurazione della flag 
    tcgetattr(STDIN_FILENO, &t);	// ribaltata con ~ (not in c) ribalta i bit della flag
    t.c_iflag &= ~(IXON);		// nella zona IXON che attiva l'input dei caratteri ctrl+s ecc..
    tcsetattr(STDIN_FILENO, TCSANOW, &t); // e poi lo risalvo con settattribut immediatamente con tcs.
}
 



using namespace std;

int main() {

signal(SIGINT, SIG_IGN);
signal(SIGTSTP, SIG_IGN);
signal(SIGQUIT, SIG_IGN);


vector<string> righe;//dichiaro riga
vector<string> righe1;//dichiaro riga


int x ;
int y ;
int ch;
cout << "1. create new file\n2. open file\n";
string choice;
cin >> choice; //prendo la scelta dell'utente

if(choice == "1"){ //se la scelta è 1
	cout << "enter file name : ";
	string Nomefile ; //dichiarazione del nome del file
	cin >> Nomefile; //prendo il nome del file
	system("clear");
	
	x = 0;
	y = 0;
	righe.push_back(""); //riga 0

	initscr();	     //inizializzo ncurses
	noecho();	     //disattivo i tasti mostrati a schermo 
	keypad(stdscr, TRUE);//attivo tasti speciali
	cbreak();
	disableFlowControl();
	nodelay(stdscr, TRUE); //non bloccare il programma in attesa di input
	

	while((ch = getch()) != 24) {//se ch diverso da ctrl+x lo faccio entrare altrimenti salta tutto e finisce il programma

			if(x >= 212){
				x = 0;
				y++;
				righe.push_back(""); //aggiungo una riga vuota
				move(y,x);
				refresh();
			}
		if(ch == KEY_UP){
			if(y > 0){
				y--;
				if(y < righe.size()){
					x = righe[y].length();
				}move(y, x);
			}
		}else if(ch == KEY_DOWN){
			if (y < LINES - 1) {
				y += 1;
				x = righe[y].length();
				if(y >= righe.size()){
					x = 0;
					righe.push_back(""); //aggiungo una riga vuota
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

		if(ch == 23){ //ctrl+w = 23 , ctrl+o = 15
			ofstream file(Nomefile);
			if(file.is_open()){
				for(int i = 0; i < righe.size(); i++){
					file << righe[i] << endl; //scrivo il file
				}
				file.close();
			}else{
				x = 0;
				mvprintw(x, y +10, "ERR");
				refresh();
			}
			mvprintw(LINES - 1, COLS / 2 + 5, "S"); //stampo S per avvenuta scrittura
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
			}					//		x = 0;	
		}else if(ch == KEY_BACKSPACE || ch == 127){ //controllo se ch è backspace e tolgo un carattere
			if(x > 0){
				x--;
			  //	righe[y].pop_back();
         if (y >= 0 && y < righe.size() && x >= 0 && x < righe[y].size()) {
           righe[y].erase(righe[y].begin() + x);                                             
         }
				mvaddch(y, x, ' '); //muovo il cursore cancello il carattere
				move(y, x); //sposto il cursore
			}else if (x == 0 && y > 0){
				y--;
				x = righe[y].length();
				move(y, x);
			}
		}else if(isprint(ch)){

      righe[y].insert(x, 1, (char)ch);
      move(y, 0);
      clrtoeol();
      mvprintw(y, 0, "%s", righe[y].c_str());
      move (y, x);
      x++;
		}
	}
	endwin();
}else if(choice == "2"){ //se la scelta è 2
	cout << "enter file name : ";
	string Nomefile ; //dichiarazione del nome del file
	cin >> Nomefile; //prendo il nome del file
	vector<string> righe1;

	ifstream file(Nomefile);
	if(file.is_open()){
		string line;
		while(getline(file, line)){
			righe1.push_back(line); //leggo il file e lo metto in righe1
		}
		file.close();
	}

	initscr();	     //inizializzo ncurses
	noecho();	     //disattivo i tasti mostrati a schermo 
	keypad(stdscr, TRUE);//attivo tasti speciali
	cbreak();
	disableFlowControl();

	for(int i = 0; i < righe1.size(); i++){
		mvprintw(i, 0, "%s", righe1[i].c_str());
	}
	y = righe1.size() ;
	x = 0;
	righe1.push_back(""); //aggiungo una riga vuota per l'editing
	move(y,x);
	refresh();

	while((ch = getch()) != 24) {//se diverso da ctrl+x lo faccio entrare altrimenti salta tutto e finisce il programma
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
					righe1.push_back(""); //aggiungo una riga vuota
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
			righe1.push_back(""); //aggiungo una riga vuota
			move(y,x);
			refresh();		
		}


		if(ch == 23){	//ctrl+w
			ofstream file(Nomefile);
			if(file.is_open()){
				for(int i = 0; i < righe1.size(); i++){
					file << righe1[i] << endl; //scrivo il file
				}
				file.close();
			}else{
				x = 0;
				mvprintw(x, y + 10, "ERR");
				refresh();
			}
			mvprintw(LINES - 1, COLS / 2 + 5, "S"); //stampo S per avvenuta scrittura
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
		}else if(ch == KEY_BACKSPACE || ch == 127){ //controllo se ch è backspace e tolgo un carattere
			if(x > 0){
				x--;
			 if (y >= 0 && y < righe1.size() && x >= 0 && x < righe1[y].size()) {
           righe1[y].erase(righe1[y].begin() + x);                                             
         }
				mvaddch(y, x, ' '); //muovo il cursore cancello il carattere
				move(y, x); //sposto il cursore
			}else if (x == 0 && y > 0){
				y--;
				x = righe1[y].length();
				move(y, x);
			}
		}else if(isprint(ch)){
	    righe1[y].insert(x, 1, (char)ch);
      move(y, 0);
      clrtoeol();
      mvprintw(y, 0, "%s", righe1[y].c_str());
      move (y, x);
      x++;
	}
	}
	endwin();
}
}

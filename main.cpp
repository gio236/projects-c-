#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(){
	string comando = "swaybg -i ";
	string comando1 = " -m stretch &";
	string comandoconfig = "exec_always swaybg -i ";  
	string comandowallust = "wallust run ";
	string comandojp2a = "jp2a --width=80 --height=40 ";
	string percorsosfondo;
	cout << "1) per inserire sfondi esistenti\n2) per inserire nuovi sfondi" << endl;
 	int choice;
	cin >> choice;
	if(choice == 1){
//*************************************************************//
	ifstream file1("/home/gioele/scriptc++/sfondo/sfondo.txt");
	if(file1.is_open()){
		vector <string> riga;
		string riga1;
		int i = 0;
		while(getline(file1, riga1)){

			riga.push_back(riga1);

			string commandviu = "viu -w 40 -h 20 " + riga1;
			system(commandviu.c_str());

		 	/***********************************	
			string numero = to_string(i);
			string commperascii = comandojp2a + riga1 + " > " + i + ".txt" ;
			cout << commperascii;
		
			//creare comando per inserire immagine dentro il file
			//creare immagine inserendola dentro quel file
			//mandare in output con ifstream

		  	***********************************/					
			cout << i << "." << riga[i] << endl;	
			i++;
		}
		int numsfondo;
		cout << "inserisci numero sfondo che vuoi applicare" << endl;
		cin >> numsfondo;
		percorsosfondo = riga[numsfondo];	
		string comandoS1= comando + percorsosfondo + comando1;
		string comandowallust1 = comandowallust + percorsosfondo;
		system(comandoS1.c_str());
		system(comandowallust1.c_str());
		
	}
//*************************************************************//	
	}else{
	cout << "inserisci percorso nuovo sfondo :";
	cin >> percorsosfondo;

//*************************************************************//
	ofstream file("/home/gioele/scriptc++/sfondo/sfondo.txt", ios::app);
	if(file.is_open()){
		file << "\n" << percorsosfondo;
		file.close();
	}else{
		cout << "ERRORE NELL'APRIRE FILE" << endl;
	}
//*************************************************************//	



	string  comandoSC = comandoconfig + percorsosfondo + comando1;
	string	comandoS = comando + percorsosfondo + comando1;
	system(comandoS.c_str()); 				//essendo funzione c bisogna transformare string to char = .c_str()

	char scelta;	
	cout << "vuoi aggiungere al config di i3 lo sfondo ? [y/n]" << endl;
	cin >> scelta;
	if(scelta == 'y'){
		ofstream file("/home/gioele/.config/i3/config", ios::app);
		if(file.is_open()){
			file << comandoSC;
			file.close();
		}else{
			cout << "ERRORE NELL'APRIRE FILE" << endl;
		}
	}
}
}

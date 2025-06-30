#include <iostream>
#include <fstream>
#include <filesystem>
#include <map>

using namespace std;

namespace fs = std::filesystem;

int main(){
	
	string path;
	string immagini;
	string documenti;
	string video;
	string compressi;

	ifstream file("/home/gioele/g++/opath/config");
		if(file.is_open()){
			string riga;
			int i = 0;
			while(getline(file, riga)){
				if (i == 0) path = riga;
				if (i == 1) immagini = riga;
				if (i == 2) documenti = riga;
				if (i == 3) video = riga;
				if (i == 4) compressi = riga;
				i++;
			}
			file.close();
		}

	map <string, string> categories = {
		{".jpg", immagini},
		{".png", immagini},
		{".webp", immagini},
		{".txt", documenti},
		{".pdf", documenti},
		{".mp4", video},
		{".gz", compressi},   //metto .gz e non .tar.gz perche la funzione extension() restituisce solo .gz  
		{".tar", compressi}
	};

	for (const auto& entry : fs::directory_iterator(path)) {
    		std::cout << entry.path() << '\n';
		if (!fs::is_regular_file(entry)) continue;
		string extension = entry.path().extension().string();
		string filename = entry.path().filename().string();

		string dest_folder = categories.contains(extension) ?    // if categories.contains(.)
				     categories[extension] : "altro";    // true  : false ;


		fs::create_directory(path + "/" + dest_folder);
        	fs::rename(entry.path(), path + "/" + dest_folder + "/" + filename);

        	std::cout << "moved: " << filename << " → " << dest_folder << '\n';
 
		

	}

}


#include <iostream>
#include <map>
#include <fstream>
#include <windows.h>

std::string fileExtens;

int canExit = 0;

int exitCallBack(std::map<int, std::string> a) {
	for (int f = 0; f < a.size(); f++) {
		//FOR DEBUG PROCCESSESS
		std::cout << a[f] << "\n";
	};
	canExit = 1;
	return 1;
};

class editor {
	private:
		int VERSION = 0.1;
	public:
		enum EDITOR_EXIT_CODE {
			EDITOR_EXIT_CODE_COLON_Q = 1,
			EDITOR_EXIT_CODE_COLON_WQ = 2,
			EDITOR_EXIT_CODE_COLON_QUIT = 3
		};
		void setEditorExitCode(EDITOR_EXIT_CODE A, std::map<int, std::string> d, std::string inp) {
			switch (A) {
				case 1:
					if (inp == ":q" || inp == ":Q")
					exitCallBack(d);
					break;
				case 2:
					if (inp == ":wq" || inp == ":WQ")
					exitCallBack(d);
					break;
				case 3:
					if (inp == ":QUIT" || inp == ":quit")
					exitCallBack(d);
					break;
				default:
					std::cout << "ERROR\n";
					break;
			}
		}
		void setFileContent(std::map<int, std::string> osf) {
			std::ofstream afile(fileExtens);
			for (int as = 0; as < osf.size(); as++) {
				afile << osf[as];
			}
			Sleep(500);
			std::ifstream arfile(fileExtens);
			std::string CONTENTS;
			while(std::getline(arfile, CONTENTS)) {
				afile << CONTENTS;
			};
			afile.close();
			arfile.close();
		};
};

int main() {
	std::map<int,std::string> LINES;
	std::cout << "EDITOR\n";
	std::cout << "FILE NAME (Including Extension  ex...(.txt) ): \n";
	std::cin >> fileExtens;
	for (int cline = 0;;cline++) {
		std::string input;
		std::getline(std::cin, input);
		editor al;
		al.setEditorExitCode(al.EDITOR_EXIT_CODE_COLON_Q, LINES, input);
		al.setFileContent(LINES);
		if (canExit == 1) {
			goto EXT;
		};
		LINES.insert({cline, input});
		input.assign("\n");
	};
	EXT:
	return 0;
}

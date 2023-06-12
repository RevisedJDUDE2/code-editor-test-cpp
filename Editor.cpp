#include <iostream>
#include <vector>
#include <unistd.h>
#include <fstream>
#include <string>
#define SUB_VER "PRE-RELEASE -- 2.1"

int counter = 2;

void af(std::vector<std::string> cont);

class Editor {
	private:

	public:
	void setCallBack(std::vector<std::string> a ,void(*Function)(std::vector<std::string> b)) {
		Function(a);
	}
	void makeFile(std::string name, std::vector<std::string> Contents) {
		std::ofstream file(name);
		for (int lines = 0; lines < Contents.size(); lines++) {
			file << Contents[lines];
		}
		sleep(1);
		file.close();
	}
};

void af(std::vector<std::string> cont) {
    counter--;
    std::string STATUSCODE = (counter == 0) ? "You Can Now Exit" : "$ Left To Exit!";
	std::cout << counter << STATUSCODE << "\n";
    if (counter == 0) {
        system("title SAVED DOCUMENT!");
    }
}

int main(int argc, char *argv[]) {
    system("title BAsic Code Editor (BACE) && cls");
	std::vector<std::string> LINES;
	std::cout << "Editor " << SUB_VER << counter+".A" <<"\n";
	std::cout << "To Exit: $ and hit enter\n";

	for (int loop = 0;;loop++) {
		std::string inputs;
		std::getline(std::cin, inputs, '$');
		Editor Obj;
		Obj.setCallBack(LINES, af);
        std::string filename_getargv = (argv[1] == "" || argv[1] == NULL) ? "SAMPLE.txt" : argv[1];
		Obj.makeFile(filename_getargv, LINES);
		LINES.push_back(inputs);
		inputs.assign("");
        sleep(1);
	};
    sleep(10);
	return 0;
}

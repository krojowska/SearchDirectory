#include <fstream>
#include <iostream>
#include <filesystem>
#include <fstream>
#include<string>

using namespace std;

int noLetters(string nameOfFile)
{
	ifstream  myfile(nameOfFile);
	char letter;
	int counter = 0;
	while (myfile)
	{
		myfile.get(letter);
		if ((letter > 63 && letter < 91) || (letter > 96 && letter < 123))
			counter++;
	}

	return counter;
}

int noWords(string nameOfFile)
{
	ifstream myfile;
	string word;
	int counter = 0;

	myfile.open(nameOfFile.c_str());

	while (!myfile.eof())
	{
		myfile >> word;
		++counter;
	}
	myfile.close();
	return counter;
}


int noLines(string nameOfFile) {
	int counter = 0;
	string line;
	ifstream myfile(nameOfFile);
	string word;
	int count = 0;

	if (myfile.is_open()) {
		while (!myfile.eof()) {
			getline(myfile, line);
			counter++;
		}
		myfile.close();

		return counter;
	}
}

void searchDirectory(std::filesystem::path p1) {
    int fileCount = 0;
	int letters;
	int words;
	int lines;

    for (auto& p : std::filesystem::directory_iterator(p1)) {
        std::cout << p.path() << '\n';
        const auto filenameStr = p.path().filename().string();
        if (p.is_directory()) {
            std::cout << "dir:  " << filenameStr << '\n';
			searchDirectory(p.path());
        }
        else if (p.is_regular_file()) {
            if (p.path().extension().string() == ".txt") {
                std::cout << "txt:  " << filenameStr << '\n';
                std::string path_string{ p.path().u8string() };
				lines = noLines(path_string);
				cout << "Number of lines in txt file: " << lines << endl;
				words = noWords(path_string);
				cout << "Number of words in file is " << words << endl;
				letters = noLetters(path_string);
				cout << "Number of characters in file : " << letters << endl;
            }
        }
        ++fileCount;
    }
	cout << "Plikow w folderze: " << fileCount << endl;
}


int main()
{
    std::filesystem::path p1{ "C:/Users/Dzban/Desktop/folder1" };
    searchDirectory(p1);

    return 0;
}
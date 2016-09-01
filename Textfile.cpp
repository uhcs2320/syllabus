#include <iostream>

#include <string>
#include <fstream>

using namespace std;

class Textfile {
	public:
	Textfile() {
		cout << "default constructor" << endl;
	}

	Textfile(string name) {
		Textfile(); // call the default constructor
		cout << "constructor with 1 parameter" << endl;
		setFilename(name);
	}

	void setFilename(string name) {
		filename = name;
	}

	void details() {
		cout << "Filename: " << filename << endl;
	}

	void readFileContents() {
		ifstream olaf(filename);
		string str;
		int count = 0;
		while(getline(olaf, str)) {
			count++;
		}
		olaf.close();
		numberOfLines = count;
		lines = new string[numberOfLines];

		// open the file again
		olaf.open(filename);
		int i = 0;
		while(getline(olaf, str)) {
			lines[ i ] = string(str);
			i++;
		}
	}

	string lineAt(int i) {
		return lines[ i ];
	}

	~Textfile() {
		if(NULL != lines) {
			delete[] lines;
		}
	}

	private:
	string *lines = NULL;
	string filename;
	int numberOfLines = 0;
};

int main( int argc, char** argv )
{
	Textfile a;
	a.setFilename( "LICENSE" );
	a.details();
	a.readFileContents();

	cout << "Next, output lines 4 to 7"<< endl;
	for( int i = 4; i < 8; i++ ) {
		cout << a.lineAt(i) << endl;
	}
	cout <<"Done with lines 4 to 7"<< endl;
	cout << endl;

	Textfile *other = new Textfile("LICENSE");
	(*other).details();
	other->details();
}


#include <iostream>

#include <string>

using namespace std;

int main( int argc, char** argv )
{
	// verify that there was 1 parameter passed.
	if( argc != 2 ) {
		cout << "Error, please specify parameter correctly. This program needs a parameter to work." << endl;
		return 0;
	}
	// initialize the variable 'parameter' with the argument 1
	string parameter(argv[1]);

	// find the position of the semicolon
	string::size_type position = parameter.find(';');
	// next line is for display purposes only.
	cout << "position: " << position << endl;

	// get only the filename via substring. The value of 10 is fixed for hw1 because the parameter always starts with: inputfile=
	string filename = parameter.substr(10, position - 10);
	// next line is for display purposes only.
	cout << "Filename: " << filename << endl;


	// find the position of the second equals sign (the second parameter indicates where in the string to start searching).
	string::size_type position2 = parameter.find('=', position);
	// next line is for display purposes only.
	cout << "position2: " << position2 << endl;

	// get only the numerical value via substring. (the '+ 1' is to get the substring after the equals sign).
	string number = parameter.substr(position2 + 1);
	// next line is for display purposes only.
	cout << "number: " << number << endl;

}

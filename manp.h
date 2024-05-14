#include <iostream>

using namespace std;

void manp()
{
	cout << "\nthis is a work in progress, some features aren't fully implemented yet, stay tuned :)" << endl;

	cout << "USAGE: ./t152h1 [PARAM1] [PARAM2] [PARAM3 (Conditional)]\n" << endl;

	cout << "\nValid [PARAM1] Values & Their Purpose: \n" << "1. realtime: encode/decode text after being prompted in the terminal itself. \n" << "2. readfile: encode/decode text sampled from a plain text file." << endl;

	cout << "\nValid [PARAM2] Values & Their Purpose: \n" << "1. encode: encode the sampled input string using the 4-digit numeric key. \n" << "2. decode: decode the sampled input string using the 4-digit numeric key." << endl;

	cout << "\n[PARAM3] is only used when [PARAM1] == readfile. Use [PARAM3] to specify the input file." << endl;

	cout << "\nKEY: The key is a 4-digit numeric PIN which is used to encode/decode. While encoding, it is recommended to not repeat digits, although it has marginal impact in most cases." << endl;

}

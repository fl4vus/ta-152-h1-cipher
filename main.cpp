#include <iostream>
#include <fstream>
#include <cstring>

#include "functions.h"
#include "manp.h"

using namespace std;

#define EXIT_INVALID_ARGS 0x01
#define EXIT_INVALID_ARG_MODE 0x02

#define SAMPLE_LIMIT 4096

const char characters[] = 
    {
        '\0','\a','\b', '\t', '\n', '\v', '\f', '\r', ' ',
        '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/',
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>',
        '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[',
        ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
        'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        '{', '|', '}', '~'
    };

int mainsize = sizeof(characters)/sizeof(characters[0]);

int main(int argc, char** argv)
{
	int index[mainsize];
    int key;
    int key0, key1, key2, key3;

    int mode;

    char sample[SAMPLE_LIMIT];

    if (!(argc == 2))
    {
        fprintf(stderr, "ERROR: Invalid Arguments!\n");
        manp();
        exit(EXIT_INVALID_ARGS);
    }

    else
    {
        if (strcmp(argv[1], "realtime") == 0)
        {
            mode = 0;
            cout << "Ta-152-H Encrypter\n" << string(18, '-') << endl << "By RIYAN DAHIYA :]\n" << endl;
            cout << "Using User Input for Sampling" << endl;
        }
        
        else if (strcmp(argv[1], "readfile") == 0)
        {
            mode = 1;
            cout << "Ta-152-H Encrypter\n" << string(18, '-') << endl << "By RIYAN DAHIYA :]\n" << endl;
            cout << "Using Text File for Sampling" << endl;
        }

        else
        {
            fprintf(stderr, "ERROR: Invalid Arguments!\n");
            manp();
            exit(EXIT_INVALID_ARG_MODE);
        }
    }

    switch (mode)
    {
    case 0:
        cout << "\nEnter Input String: \n";
        fgets(sample, SAMPLE_LIMIT, stdin);
        cout << "\nINPUT: \n" << sample << endl;
        break;

    case 1:
        manp();
        break;

    default:
        cout << "\nOk... Enter Input String: \n";
        fgets(sample, SAMPLE_LIMIT, stdin);
        cout << "\nINPUT: " << sample << endl;
        break;
    }

    
	return 0;
}
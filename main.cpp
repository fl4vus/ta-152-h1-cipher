#include <iostream>
#include <fstream>
#include <cstring>

#include "functions.h"
#include "manp.h"

using namespace std;

#define EXIT_INVALID_ARGS 0x01
#define EXIT_INVALID_ARG_MODE 0x02
#define EXIT_INVALID_KEY 0x03

#define SAMPLE_LIMIT 4096

char characters[] = 
    {
        '\0', '\t', '\n', ' ', '\\',
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
    int keyArr[4];
    int decKey;
    int decKeyArr[4] = {0, 0, 0, 0};

    int mode;
    int effectivesize;
    int iterator;

    char sample[SAMPLE_LIMIT];
    char scrambled[SAMPLE_LIMIT];

    if (!((argc == 3)&&(strcmp(argv[1], "realtime") == 0)||(argc == 4)&&(strcmp(argv[1], "readfile") == 0)))
    {
        fprintf(stderr, "ERROR: Invalid Arguments!\n");
        manp();
        exit(EXIT_INVALID_ARGS);
    }

    else
    {
        if ((strcmp(argv[1], "realtime") == 0) && (strcmp(argv[2], "encode") == 0))
        {
            mode = 0;
            cout << "Ta-152-H1 Encrypter\n" << string(19, '-') << endl << "By: RIYAN DAHIYA :]\n" << endl;
            cout << "Using User Input for Encoding" << endl;
        }
        else if ((strcmp(argv[1], "realtime") == 0) && (strcmp(argv[2], "decode") == 0))
        {
            mode = 1;
            cout << "Ta-152-H1 Encrypter\n" << string(19, '-') << endl << "By: RIYAN DAHIYA :]\n" << endl;
            cout << "Using User Input for Decoding" << endl;
        }
        
        
        else if (strcmp(argv[1], "readfile") == 0)
        {
            mode = 2;
            cout << "Ta-152-H1 Encrypter\n" << string(19, '-') << endl << "By: RIYAN DAHIYA :]\n" << endl;
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
        break;

    case 1:
        cout << "\nEnter Input String: \n";
        fgets(sample, SAMPLE_LIMIT, stdin);
        break;

    case 2:
        manp();
        break;

    default:
        mode = 0;
        cout << "\nOk... Enter Input String: \n";
        fgets(sample, SAMPLE_LIMIT, stdin);
        //cout << "\nINPUT: " << sample << endl;
        break;
    }

    iterator = 0;
    effectivesize = 0;
    while (sample[iterator] != '\0')
    {
        effectivesize++;
        iterator++;
    }

    cout << "\nINPUT: \n" << sample << "\nSIZE: "<< effectivesize << endl;

    for (int i= 0; i < mainsize; i++)
    {
        *(index + i) = i;
    }

    cout << "\nEnter Cipher Key: ";
    scanf("%d", &key);

    if (key < 1000 || key > 9999)
    {
        fprintf(stderr, "Invalid Key Format!\n");
        exit(EXIT_INVALID_KEY);
    }

    keyArr[0] = key/1000;
    keyArr[1] = (key%1000)/100;
    keyArr[2] = (key%100)/10;
    keyArr[3] = key%10;

    if (mode == 0)
    {
        for (int i = 0; i < 4; i++)
        {
            superShuffle(index, keyArr[i], mainsize);
        }
        
        for (int i = 0; i < effectivesize - 1; i++)
        {
            int buf1 = findCharPosition(characters, mainsize, sample[i]);
            int buf2 = findMapPosition(index, mainsize, buf1);
            char buf3 = characters[buf2];
            //cout << i << "\t";
            scrambled[i] = buf3;
            //cout << sample[i] << "\t" << scrambled[i] << "\n";
        }
    }

    if (mode == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            decKeyArr[0] = keyArr[3-i];

            //cout << "\n" << decKeyArr[0] << decKeyArr[1] << decKeyArr[2] << decKeyArr[3] << endl;
            strcpy(scrambled, sample);

            for (int i = 0; i < 4; i++)
            {
                superShuffle(index, decKeyArr[i], mainsize);
            }
            
            for (int i = 0; i < effectivesize - 1; i++)
            {
                int buf1 = findCharPosition(characters, mainsize, scrambled[i]);
                int buf2 = findMapPosition(index, mainsize, buf1);
                char buf3 = characters[buf2];
                //cout << i << "\t";
                scrambled[i] = buf3;
                //cout << sample[i] << "\t" << scrambled[i] << "\n";
            }

            //cout << "\nOUTPUT: \n" << scrambled << endl;
        }

    }
    cout << "\nOUTPUT: \n" << scrambled << endl;

    return 0;
}

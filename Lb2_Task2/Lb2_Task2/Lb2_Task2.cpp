#include <iostream>
#include <bitset>
#include <string>
#include <fstream>

int main() {
    std::string text[8];
    short i, j, l, m;
    for (int i = 0; i < 8; i++) {
        std::cout << "enter line " << i + 1 << ":";
        std::getline(std::cin, text[i]);
    }
    for (i = 0; i < 8; i++) {
        while (text[i].length() < 8) {
            text[i] += '0';
        }
    }
    unsigned short rez[8][8];
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            unsigned char c;
            unsigned short r, t, b;
            r = 0;
            c = text[i][j];

            r |= i;// номер рядка
            r |= ((int)c << 3);// аскіі код на 3 біт по 10


            t = 1;
            b = 0;
            for (l = 0; l < 12; l++) {
                if (r & t) {
                    if (b == 0) {
                        b = 1;
                    }
                    else {
                        b = 0;
                    }
                }
                t <<= 1;
            }
            r |= b << 11;// перший біт парності на 11 біті
            r |= j << 12;// позиція елемента в рядку

            t = 1;
            b = 0;
            for (m = 14; m < 16; m++) {
                if (r & t) {
                    if (b == 0) {
                        b = 1;
                    }
                    else {
                        b = 0;
                    }
                }
                t <<= 1;
            }
            r |= b << 15;
            rez[i][j] = r;

        }
    }
    std::cout << std::endl;

    std::ofstream inf("binary.txt", std::ios::binary);
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            std::bitset<16> binary(rez[i][j]);
            std::cout << binary << std::endl;
            inf << binary << std::endl;
        }
    }
    inf.close();
    return 0;
}

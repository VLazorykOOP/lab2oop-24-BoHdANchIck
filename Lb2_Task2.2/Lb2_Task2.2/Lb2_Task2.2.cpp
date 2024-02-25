#include <iostream>
#include <fstream>
#include <bitset>

int main() {
    unsigned short Text[8][8]; 
    std::ifstream code("binary.txt", std::ios::binary);
    if (!code) {
        std::cout << "Error!" << std::endl;
        return 1;
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::bitset<16> binary;
            code >> binary;
            Text[i][j] = static_cast<unsigned short>(binary.to_ulong()); // перетворення в ціле число
        }
    }
    code.close();

    // розшифровка
    char Rez[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            unsigned short data = Text[i][j];
            char r = static_cast<char>((data >> 3) & 0x7F); // аскіі
            Rez[i][j] = r;
        }
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (Rez[i][j] == '0') { 
                Rez[i][j] = ' '; 
            }
        }
    }

    std::ofstream Result("Result.txt");
    if (!Result) {
        std::cerr << "Error!" << std::endl;
        return 1;
    }
    std::cout << "Decrypted Text:" << std::endl;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            Result << Rez[i][j]; // файл
            std::cout << Rez[i][j]; // консоль
        }
        Result << std::endl;
        std::cout << std::endl; 
    }
    Result.close();
    return 0;
}


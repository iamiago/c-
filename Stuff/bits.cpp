#include <iostream>
#include <bitset>

using namespace std;

void testBits()
{
    int n = 3;
    auto binary = std::bitset<8>(n).to_string();
    cout << "Int to String of binary: " << binary << endl;

    int binaryInt = stoi(binary);
    cout << "String to Int: " << binaryInt << endl;

    string binaryString = to_string(binaryInt);
    cout << "Int to String: " << binaryString << endl;

    auto decimal = std::bitset<8>(binary).to_ulong();
    cout << "String binary to Unsigned long: " << decimal << endl;
}

void printHex(unsigned int value)
{
    printf("%x\n", value);
}

int main()
{

    // testBits();
    //      0x1234
    //    & 0x0
    int value = 0x1234;
    // int a = value & 0x00ff; // on masque les nombres 1 et 2 avec l'operateur & et 0
    // int a = value & 0xff00;
    int a = (value & 0xFF00) >> 8;
    printHex(a);

    int color = 0xFF00FF;
    cout << std::bitset<24>(color).to_string() << endl;

    //extracting RGB
    int red = (color & 0xFF0000) >> 16;
    cout << std::bitset<8>(red).to_string() << endl;
    int green = (color & 0xFF00) >> 8;
    int blue = (color & 0xFF) >> 0;
    printHex(red);
    printHex(green);
    printHex(blue);

    //reconverting to hex
    // red -= 50;
    // green += 50;
    // blue -= 50;

    int result = red << 16 | green << 8 | blue;
    printHex(result);

    int aa = 0x12;
    int bb = 0x7;

    cout << std::bitset<8>(aa).to_string() << endl;      // 00010010
    cout << std::bitset<8>(bb).to_string() << endl;      // 00000111
                                                         // --------  XOR
    cout << std::bitset<8>(aa ^ bb).to_string() << endl; // 00010101

    cout << std::bitset<8>(~bb).to_string() << endl;
    return 0;
}
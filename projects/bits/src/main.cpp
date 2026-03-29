#include "../include/bits.hpp"

int main()
{
    cout << " Bit read " << endl;
    int val = 180;
    cout << "value: " << val << "  bin: " << decToBin(val) << endl;
    for (int i = 0; i <= 4; i++)
        cout << "  bit[" << i << "] = " << readBit(val, i) << endl;

    cout << "\n Set / clear " << endl;
    int original = 0b01101010;
    int after_set   = enableBit(original, 0);
    int after_clear = disableBit(original, 4);
    cout << "original:    " << decToBin(original)    << "  (" << original    << ")" << endl;
    cout << "set   bit 0: " << decToBin(after_set)   << "  (" << after_set   << ")" << endl;
    cout << "clear bit 4: " << decToBin(after_clear) << "  (" << after_clear << ")" << endl;

    cout << "\n XOR swap " << endl;
    int a = 57, b = 13;
    cout << "before: a=" << a << "  b=" << b << endl;
    swapValues(a, b);
    cout << "after:  a=" << a << "  b=" << b << endl;

    cout << "\n Converter " << endl;
    int num = 210;
    string s = decToBin(num);
    cout << num << " => " << s << " => " << binToDec(s) << endl;

    cout << "\n XOR cipher " << endl;
    string msg   = "World";
    char   key   = 'X';
    string enc   = encrypt(msg, key);
    string dec   = encrypt(enc, key);
    cout << "message:   " << msg << endl;
    cout << "key:       " << key << " (" << (int)key << ")" << endl;
    cout << "encrypted: " << enc << endl;
    cout << "decrypted: " << dec << endl;

    return 0;
}
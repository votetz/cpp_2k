#pragma once

#include <iostream>
#include <string>

using namespace std;

int readBit(int value, int index)
{
    return 1 & (value >> index);
}

int enableBit(int value, int index)
{
    return value | (1 << index);
}

int disableBit(int value, int index)
{
    return value & ~(1 << index);
}

void swapValues(int& x, int& y)
{
    x ^= y;
    y ^= x;
    x ^= y;
}

string decToBin(int value)
{
    string bin = "";
    for (int bit = 7; bit >= 0; bit--)
        bin += char('0' + readBit(value, bit));
    return bin;
}

int binToDec(const string& bin)
{
    int total = 0;
    for (int i = 0; i < (int)bin.size(); i++)
        total = total * 2 + (bin[i] - '0');
    return total;
}

string encrypt(const string& input, char secret)
{
    string output = input;
    for (int i = 0; i < (int)output.size(); i++)
        output[i] ^= secret;
    return output;
}
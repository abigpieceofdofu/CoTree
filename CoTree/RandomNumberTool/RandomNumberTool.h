#pragma once
#include <random>

using namespace std;

class RandomNumberTool
{
public:
    RandomNumberTool();
    ~RandomNumberTool();

    static enum class CharsetType
    {
        Digits,
        Letters,
        SpecialChars
    };

    static int generateRandomIntNumber(int min, int max);
    static double generateRandomDoubleNumber(double min, double max);
    static string generateRandomString(int length, const std::vector<CharsetType>& charsetTypes = { CharsetType::Digits, CharsetType::Letters });
    static string generateRandomBytes(int length);

    static string generateUUID();
    static string generatePassword(int length);

private:
    static string getCharset(CharsetType charsetType);
};

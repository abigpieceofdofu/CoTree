#include "RandomNumberTool.h"

// public
RandomNumberTool::RandomNumberTool()
{}

RandomNumberTool::~RandomNumberTool()
{}

int RandomNumberTool::generateRandomIntNumber(int min, int max)
{
    random_device rd;

    mt19937 gen(rd());

    uniform_int_distribution<> dis(min, max);

    return dis(gen);
}

double RandomNumberTool::generateRandomDoubleNumber(double min, double max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(min, max);
    return dis(gen);
}

string RandomNumberTool::generateRandomString(int length, const vector<CharsetType>& charsetTypes) {
    if (length <= 0 || charsetTypes.empty()) {
        throw invalid_argument("Invalid length or charsetTypes.");
    }

    string combinedCharset;
    for (const auto& type : charsetTypes) {
        combinedCharset += getCharset(type);
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, combinedCharset.size() - 1);

    string randomString;
    randomString.reserve(length);

    for (int i = 0; i < length; ++i) {
        char randomChar = combinedCharset[dis(gen)];
        randomString += randomChar;
    }

    return randomString;
}

string RandomNumberTool::generateRandomBytes(int length) {
    static const char hexChars[] = "0123456789abcdef";
    std::string bytes;
    bytes.reserve(length);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    for (int i = 0; i < length; ++i) {
        unsigned char byte = dis(gen);
        bytes += hexChars[byte >> 4];
        bytes += hexChars[byte & 0x0F];
    }

    return bytes;
}


string RandomNumberTool::generateUUID()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 15);
    uniform_int_distribution<> dis_for_12(8, 11);

    const char* v = "0123456789abcdef";
    string uuid = string(36, ' ');

    uuid[8] = uuid[13] = uuid[18] = uuid[23] = '-';
    uuid[14] = '4';

    for (int i = 0; i < 36; i++) {
        if (uuid[i] == ' ') {
            if (i == 19) {
                uuid[i] = v[dis_for_12(gen)];
            }
            else {
                uuid[i] = v[dis(gen)];
            }
        }
    }

    return uuid;
}

string RandomNumberTool::generatePassword(int length)
{
    vector<CharsetType> charsetTypes = { CharsetType::Digits, CharsetType::Letters, CharsetType::SpecialChars };
    generateRandomString(length, charsetTypes);
}


// private
string RandomNumberTool::getCharset(CharsetType charsetType) {
    switch (charsetType) {
    case CharsetType::Digits:
        return "0123456789";
    case CharsetType::Letters:
        return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    case CharsetType::SpecialChars:
        return "!@#$%^&*()-_=+[]{}|;:',.<>?/`~";
    default:
        throw invalid_argument("Unknown charset type.");
    }
}

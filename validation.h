#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>
#include <string>
#include <regex>
using namespace std;

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool isLower(char ch) {
    return ch >= 'a' && ch <= 'z';
}

bool isUpper(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

bool isPasswordValid(const string& password) {
    bool hasDigit = false;
    bool hasLower = false;
    bool hasUpper = false;

    for (char ch : password) {
        if (isDigit(ch)) {
            hasDigit = true;
        } else if (isLower(ch)) {
            hasLower = true;
        } else if (isUpper(ch)) {
            hasUpper = true;
        }
    }

    return password.length() >= 8 && hasDigit && hasLower && hasUpper;
}

bool validUsername(const string& username, const string& userId){
    bool usernameValid = false;
    if (username != userId)
    {
        return usernameValid;
    }
    return usernameValid = true;
}

bool isValidEmail(string email) {
    const regex pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    return regex_match(email, pattern);
}


#endif
#ifndef HELPERS_H
#define HELPERS_H

class Helpers {
private:
    static std::string reverseString(std::string& str) {
    int left = 0;
    int right = str.length() - 1;

        while (left < right) {
            std::swap(str[left], str[right]);
            left++;
            right--;
        }

        return str;
    }
public:
    static std::string size_tToString(size_t number) {
        std::string result = "";
        while(number != 0) {
            result += (number % 10);
            number /= 10;
        }

        return reverseString(result);
    }
};

#endif
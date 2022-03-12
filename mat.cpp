#include "mat.hpp"
#include <iostream>
using namespace ariel;


#include <iostream>
#include <string>
#include <vector>

using namespace std;



string ariel::mat(int w, int h, char a, char b) {
    const int s = 33;
    const int e = 126;
    if (a < s || a > e || b < s || b > e) {
        throw "char isn't valid";
    }
    if (w < 0 || h < 0) {
        throw "negative number isn't valid";
    }
    if (w % 2 == 0 || h % 2 == 0) {
        throw "Mat size is always odd";
    }
    vector<vector<char>> mat(w,vector<char>(h));
    int rows = w;
    int cols = h;
    char ch = a;
    int gap = 0;
    while (rows > 0 && cols > 0) {
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                if (i == 0 || i == cols - 1) {
                    mat[j + gap][i + gap] = ch;
                }
                if (j == 0 || j == rows - 1) {
                    mat[j + gap][i + gap] = ch;
                }
            }
        }
        rows = rows - 2;
        cols = cols - 2;
        gap = gap + 1;
        if (ch == a) {
            ch = b;
        } else {
            ch = a;
        }
    }
    int counter = 0;
    string str;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            str += mat[j][i];
        }
        if (i != h - 1) {
            str += '\n';
        }    
    }
    return str;
}

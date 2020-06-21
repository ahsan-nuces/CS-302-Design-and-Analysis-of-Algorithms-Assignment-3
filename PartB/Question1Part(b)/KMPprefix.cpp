#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    cout << "starting prefix program";
    return 0;
}

int* calculatePrefixFunction(string str) {
    int n = str.length();
    int * arr = new int[n];

    int j = 0;
    int i =1;
    while (i < n){
        while (j >0 && str[j] != str[i]){
            j = arr[j-1];
        }

        if (str[j] == str[i]){
            j = j+1;
        }
        arr[i] = j;
    }
    return arr;

}


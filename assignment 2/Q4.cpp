#include <iostream>   //Q4(a)
#include <string>
using namespace std;

int main() {
    string str1 = "Hello ";
    string str2 = "World!";

    string result = str1 + str2; 

    cout << "Concatenated String: " << result << endl;
    return 0;
}


//Q4 (b)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str = "Hello";

    reverse(str.begin(), str.end());

    cout << "Reversed String: " << str << endl;
    return 0;
}


//Q4 (c)
#include <iostream>
using namespace std;

int main() {
    char str[100] = "Hello World";
    char result[100];
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
              ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')) {
            result[j] = ch; // copy non-vowel
            j++;
        }
    }
    result[j] = '\0';

    cout << "String without vowels: " << result << endl;
    return 0;
}
//Q4(d)
#include <iostream>
using namespace std;

int main() {
    char str[100] = "hello";
    char temp;

    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = i + 1; str[j] != '\0'; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    cout << "String in alphabetical order: " << str << endl;
    return 0;
}

//Q4(e)
#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter an uppercase letter: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32; // Convert to lowercase
    }

    cout << "Lowercase letter: " << ch << endl;
    return 0;
}



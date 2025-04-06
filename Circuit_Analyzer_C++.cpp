#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t = ""; // t is used to store the resistance value
    int z, p_count = 0, s_count = 0, flag = 0;  // p_count is used to store the number of parallel resistances, s_count is used to store the number of series resistances, flag is used to detect errors
    float r = 0; // r is used to store the sum of the resistances
    getline(cin, s); // Get the input string
    for (int j = 0; j < 20; j++) { // Loop to reduce the series and parallel resistances
        for (int o = 0; o < s.length(); o++) { // Checker loop to pass by all the characters in the string 
            if (s[o] == 'S' || s[o] == 'P' || s[o] == 'p' || s[o] == 's') z = o; // 'z' is used to store the index of the character that has a value of s,p,S or P
            else if (s[o] == ' ' || s[o] == ',' || s[o] == '.' || s[o] == 'e' || isdigit(s[o])) continue; // Check if the characters are suitable for this function
            else flag = 2; // When the user puts invalid characters
        }
        for (int i = z; i <= s.length(); i++) { // Loop to calculate the sum of series and parallel
            if (isdigit(s[i]) || s[i] == '.') t += s[i]; // Condition done to store the Resistance as a value
            else if (isspace(s[i]) || s[i] == ',') { 
                if ((s[z] == 'P' || s[z] == 'p') && t != "") {
                    r += 1 / stof(t); // Convert string to float to be able to add it to the sum of parallel
                    p_count++; 
                } else if ((s[z] == 'S' || s[z] == 's') && t != "") {
                    r += stof(t); // Convert string to float to be able to add it to the sum of series
                    s_count++;
                }
                t = ""; // Empty the resistance to be able to store new values inside it
            } 
            else if (s[i] == 'e') { // Finding the first e in the code to be able to replace the reduced resistance
                if (s[z] == 'P' || s[z] == 'p') {
                    if (t != "") {
                        r += 1 / stof(t);
                        p_count++;
                    }
                    s.replace(z, i - z + 1, to_string(1 / r));
                    if (p_count < 2) flag = 1; 
                } else if (s[z] == 'S' || s[z] == 's') {
                    if (t != "") {
                        r += stof(t);
                        s_count++;
                    }
                    s.replace(z, i - z + 1, to_string(r));
                    if (s_count < 1) flag = 1; 
                }
                t = "";  
                r = 0;   
                break;   
            }
        }
    }
    if (flag == 2) cout << "Wrong Description"; // When the user puts invalid characters
    else if (flag == 1) cout << "Incorrect Input"; // When the user puts less than the needed amount of values in the branch
    else cout << "The total resistance = " << stof(s);
    return 0;
}
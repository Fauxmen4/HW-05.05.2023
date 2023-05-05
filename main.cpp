#include <iostream>
#include <string>
#include <vector>

std::vector<int> z_function(const std::string &s) {
    int n = int(s.length());
    std::vector<int> z(n);
    int left = 0, right = 0;
    for (int i = 1; i < n; i++) {
		if (i <= right) z[i] = std::min(right - i + 1, z[i-left]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i+z[i]-1 > right) left = i,  right = i + z[i] - 1;
	}
    return z;
}

std::vector<int> z_function_trivial(const std::string &s) {
    int n = int(s.length());
    std::vector<int> z(n);
    for (int i = 1; i < n; i++) 
        while (i + z[i] < n && s[z[i]] == s[z[i]+i])
            z[i]++;
    return z;
}

void substring_z_function(const std::string &text, const std::string &pattern) {
    int entryCount = 0;
    int s_len = int(text.length());
    int sub_s_len = int(pattern.length());
    std::vector<int> z = z_function(pattern+"$"+text);
    for (int i = 0; i < s_len; i++) {
        if (z[i] == sub_s_len) {
            entryCount++;
            std::cout << "Starting position: " << i - int(pattern.length()) - 1 << 
            " --> Subsrting count: " << entryCount << '\n';   
        }
    }
}

void substring_trivial(const std::string &text, const std::string &pattern) {
    int entryCount = 0;
    int s_len = int(text.length());
    int sub_s_len = int(pattern.length());
    for (int i = 0; i < s_len; i++) {
        int i1 = 0, i2 = i;
        while (text[i2] == pattern[i1]) {
            i1++; i2++;
            if (i1 == sub_s_len) {
                entryCount++;
                std::cout << "Starting position: " << i << 
                " --> Subsrting count: " << entryCount << '\n';               
            }
        }
    }
}

int main() {
    std::string string = "hjkldajpovtrkebakjsickakndjkoekjndkpovtrljczhk";
    std::string substring = "povtr";

    substring_trivial(string, substring);
    substring_z_function(string, substring);

    return 0;    
}

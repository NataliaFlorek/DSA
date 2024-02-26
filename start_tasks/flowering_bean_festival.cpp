#include <iostream>
#include <string>
#include <cctype>

std::string toLowerCase(std::string str) {
    for(int i = 0; i < str.length(); i++) {
        str[i] = std::tolower(str[i]);
    }
    return str;
}
int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::string lyrics;
    getline(std::cin, lyrics, '^');
    std::string lowerCaseLyrics = toLowerCase(lyrics);
    unsigned int tab[26] = {0};// a b c d ...
    unsigned int n = lowerCaseLyrics.size();
    lowerCaseLyrics.erase(n);
    for(int i = 0; i < n; i++){
        if(lowerCaseLyrics[i] >= 'a' &&  lowerCaseLyrics[i] <= 'z'){
            tab[lowerCaseLyrics[i] - 'a'] += 1;
        }
    }
    int maxIndex = 0;
    int minIndex = 0;
    int min = 2000000;
    int max = 0;

    for (int i = 0; i < 26; i++) {
        if (tab[i] > max ) {
            maxIndex = i;
            max = tab[i];
        }
        if (tab[i] < min && tab[i] > 0 ) {
            minIndex = i;
            min = tab[i];
        }
    }
    char minChar = minIndex + 'a';
    char maxChar = maxIndex + 'a';
    std::cout << maxChar << " " << minChar;
    return 0;
}

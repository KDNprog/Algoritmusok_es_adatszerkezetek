#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> countGeneticCodes(const string& sequence, int K) {
    map<string, int> freq;
    for (size_t i = 0; i < sequence.size(); i += K) {
        string code = sequence.substr(i, K);
        freq[code]++;
    }
    return freq;
}

int main() {
    int M, K;
    cin >> M >> K;

    for (int i = 0; i < M; ++i) {
        string code1, code2;
        cin >> code1 >> code2;

        map<string, int> freq1 = countGeneticCodes(code1, K);
        map<string, int> freq2 = countGeneticCodes(code2, K);

        if (freq1 == freq2) {
            cout << "IGEN" << endl;
        } else {
            cout << "NEM" << endl;
        }
    }

    return 0;
}


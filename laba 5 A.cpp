/**************
Мхеян Роман   *
ПИ - 261      *
Вар 16        *
**************/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int k;
    if (!(cin >> k) || k < 0) { cout << "INVALID\n"; return 0; }

    map<string, int> dict;
    for (int i = 0; i < k; ++i) {
        string key; int val;
        if (!(cin >> key >> val)) { cout << "INVALID\n"; return 0; }
        dict[key] = val;          // повторный ключ перезаписывает значение
    }

    if (dict.empty()) { cout << "NONE\n"; return 0; }

    auto best = dict.begin();
    for (auto it = dict.begin(); it != dict.end(); ++it) {
        if (it->second < best->second) best = it;  // строго <, чтобы при равенстве
        // остался лексикографически меньший
    }
    cout << best->first << ' ' << best->second << '\n';
    return 0;
}

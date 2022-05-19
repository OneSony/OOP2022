#include <iostream>
#include <map>



void choiceC(std::map<std::string, int> m) {
    auto result = m.find("May");
    auto tmp = result == m.end();
    std::cout << tmp << std::endl; // (5)
}

void choiceD(std::map<std::string, int> m) {
    m.erase(++m.begin(), --m.end());
    std::cout << m.size() << std::endl; // (6)
}

void choiceE(std::map<std::string, int> m) {
    for (auto element: m) {
        std::cout << element.first << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::map<std::string, int> m;
    m["1"] = 0;
    m["6"] = 1;
    m["88"] = 2;
    m["3"] = 3;
    m["5"] = 4;
    m["4"] = 5;
    m["Saturday"] = 6;

    choiceC(m);
    choiceD(m);
    choiceE(m);
    return 0;
}
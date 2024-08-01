#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>

int main() {
    std::string pattern = R"(mailto:([a-zA-Z0-9]{1,20})@([a-zA-Z0-9]{1,20}\.[a-z]{1,5})(?:,([a-zA-Z0-9]{1,20})@([a-zA-Z0-9]{1,20}\.[a-z]{1,5}))*$)";
    std::string pattern2 = R"(([a-zA-Z0-9]{1,20})@([a-zA-Z0-9]{1,20}\.[a-z]{1,5}))";

    std::regex re(pattern, std::regex::icase);
    std::regex re2(pattern2, std::regex::icase);

    std::map<std::string, int> recipientCount;

    std::ifstream file("../GEN/output.txt");

    // std::ifstream file("input.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (std::regex_match(line, re)) {

            auto begin = std::sregex_iterator(line.begin(), line.end(), re2),    end = std::sregex_iterator();
            for(auto i = begin; i != end; ++i)
            {
                std::smatch match = *i;
                recipientCount[match.str(1)]++;
            }       
        }
        else {
        }
    }

    file.close();

    std::cout << "Recipient statistics:" << std::endl;
    for (const auto& pair : recipientCount) {
        std::cout << pair.first << " - " << pair.second << " occurrences" << std::endl;
    }

    return 0;
}
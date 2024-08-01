#include <iostream>
#include <FlexLexer.h>
#include <fstream>
#include <string>
#include <map>

int main()
{

std::map<std::string, int> recipientCount;
std::map<std::string, int> recipientCorrect;

std::ifstream file("../GEN/output.txt");

// std::ifstream file("input.txt");
if (!file.is_open()) {
    std::cerr << "Error opening file." << std::endl;
    return 1;
}

yyFlexLexer ftp(&file, &std::cout);
int res = ftp.yylex();
while (res == 0 || res == 1) {
    while(res==1){
        auto cur = ftp.YYText();
        // std::cout << cur << std::endl;
        recipientCorrect[cur]++;
        res = ftp.yylex();
    }
    if(res==0){
        recipientCorrect.clear();
    }
    else if(res==2){
    for (auto const& pair : recipientCorrect) {
        // Проверяем, содержится ли ключ уже в существующей map
        auto it = recipientCount.find(pair.first);
        if(it != recipientCount.end()) {
            // Если ключ уже существует, увеличиваем счетчик на значение из tempMap
            it->second += pair.second;
        } else {
            // Если ключ уникален, добавляем его в существующую map
            recipientCount.insert(pair);
        }
    }
    }
    recipientCorrect.clear();
    res = ftp.yylex();
}
file.close();

    std::cout << "Recipient statistics:" << std::endl;
    for (const auto& pair : recipientCount) {
        std::cout << pair.first << " - " << pair.second << " occurrences" << std::endl;
    }

return 0;
}

#ifndef _H_THECONTEXT
#define _H_THECONTEXT


#include "AppClass_sm.h"
#include <map>

#ifdef CRTP
class AppClass : public AppClassContext<AppClass>
#else
class AppClass
#endif
{
private:
#ifndef CRTP
    AppClassContext _fsm;
#endif

    bool isAcceptable;
        // If a string is acceptable, then this variable is set to YES;
        // NO, otherwise.
    const std::string mail = "mailto:";
    std::string buffer = "";
    size_t buffer_size = 0;
    size_t char_num = 0;

    std::map<std::string, int> recipientCorrect_in_smc;

    // size_t symbols_in_name = 20;
    // size_t symbols_in_ost = 5;


public:
    AppClass();
        // Default constructor.

    ~AppClass() {};
        // Destructor.

    bool isCmdSymbol(char smb) {
        return ('a' <= smb && smb <= 'z')
        || ('A' <= smb && smb <= 'Z')
        || ('0' <= smb && smb <= '9')
        || (smb == '.')
        || (smb == '/');
    }
    bool isSymbol(char smb) {
        return ('a' <= smb && smb <= 'z')
               || ('A' <= smb && smb <= 'Z')
               || ('0' <= smb && smb <= '9');
    }
    bool isInMail(char smb) {
        if(smb == mail[char_num]){
            // char_num++;
            return true;
        }
        else{
            // char_num++;
            return false;
        }
    }
    bool mailNotEnded() {
        if(buffer_size<=6){
            return true;
        }
        else{
            return false;
        }
    }
    bool isAt(char smb) {
        if(smb == '@'){
            return true;
        }
        else{
            return false;
        }
    }
    bool isDot(char smb) {
        if(smb == '.'){
            return true;
        }
        else{
            return false;
        }
    }
    bool isComma(char smb) {
        if(smb == ','){
            return true;
        }
        else{
            return false;
        }
    }
    bool nameNotEnded() {
        if(buffer_size<=20){
            return true;
        }
        else{
            return false;
        }
    }
    bool firstOstNotEnded() {
        if(buffer_size<=20){
            return true;
        }
        else{
            return false;
        }
    }
    bool secondOstNotEnded() {
        if(buffer_size<=5){
            return true;
        }
        else{
            return false;
        }
    }

    void addSymbolToBuffer(char s){
        buffer += s;
        buffer_size++;
    }
    void addAtMap(){
        recipientCorrect_in_smc[buffer]++;
    }
    void clearMap(){
        recipientCorrect_in_smc.clear();
    }
    void clearBuffer(){
        buffer="";
        buffer_size=0;
    }


    bool CheckString(const std::string &, std::map<std::string, int> &);
        // Checks if the string is acceptable.

    inline void Acceptable()
    { isAcceptable = true; };

    inline void Unacceptable()
    { isAcceptable = false; };
        // State map actions.
};

#endif

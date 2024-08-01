//
// The contents of this file are subject to the Mozilla Public
// License Version 1.1 (the "License"); you may not use this file
// except in compliance with the License. You may obtain a copy of
// the License at http://www.mozilla.org/MPL/
// 
// Software distributed under the License is distributed on an "AS
// IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
// implied. See the License for the specific language governing
// rights and limitations under the License.
// 
// The Original Code is State Machine Compiler (SMC).
// 
// The Initial Developer of the Original Code is Charles W. Rapp.
// Portions created by Charles W. Rapp are
// Copyright (C) 2000 - 2003 Charles W. Rapp.
// All Rights Reserved.
// 
// Contributor(s): 
//
// Function
//	Main
//
// Description
//  This routine starts the finite state machine running.
//
// RCS ID
// $Id$
//
// CHANGE LOG
// $Log$
// Revision 1.10  2014/09/07 07:19:00  fperrad
// exception const reference
//
// Revision 1.9  2014/09/06 19:53:15  fperrad
// remove hard tab
//
// Revision 1.8  2014/07/12 10:48:49  fperrad
// remove _rcs_id
//
// Revision 1.7  2006/06/03 19:39:24  cwrapp
// Final v. 4.3.1 check in.
//
// Revision 1.6  2006/04/22 12:45:24  cwrapp
// Version 4.3.1
//
// Revision 1.5  2005/06/08 11:09:12  cwrapp
// + Updated Python code generator to place "pass" in methods with empty
//   bodies.
// + Corrected FSM errors in Python example 7.
// + Removed unnecessary includes from C++ examples.
// + Corrected errors in top-level makefile's distribution build.
//
// Revision 1.4  2005/05/28 13:31:16  cwrapp
// Updated C++ examples.
//
// Revision 1.1  2004/09/06 15:23:39  charlesr
// Updated for SMC v. 3.1.0.
//
// Revision 1.0  2003/12/14 19:12:12  charlesr
// Initial revision
//

#include "AppClass.h"
#include <fstream>
#include <map>

using namespace std;
using namespace statemap;

int main()
{
    // AppClass thisContext;
    std::map<std::string, int> recipientCount;
    std::map<std::string, int> recipientCorrect;

    std::ifstream file("../../GEN/output.txt");

    // std::ifstream file("input.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    // std::getline(file, line);
    while (std::getline(file, line)) {
        AppClass thisContext;
        if(thisContext.CheckString(line, recipientCorrect) == true){
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
    }
    file.close();
        for (const auto& pair : recipientCount) {
            std::cout << pair.first << " - " << pair.second << " occurrences" << std::endl;
        }



    return 0;
}

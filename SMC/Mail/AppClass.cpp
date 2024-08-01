//
// The contents of this file are subject to the Mozilla Public
// License Version 1.1 (the "License"); you may not use this file
// except in compliance with the License. You may obtain a copy
// of the License at http://www.mozilla.org/MPL/
// 
// Software distributed under the License is distributed on an
// "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
// implied. See the License for the specific language governing
// rights and limitations under the License.
// 
// The Original Code is State Machine Compiler (SMC).
// 
// The Initial Developer of the Original Code is Charles W. Rapp.
// Portions created by Charles W. Rapp are
// Copyright (C) 2000 - 2009. Charles W. Rapp.
// All Rights Reserved.
// 
// Contributor(s): 
//
// Class
//	AppClass
//
// Inline Member Functions
//	AppClass()				   - Default constructor.
//	CheckString(const char *)  - Is this string acceptable?
//
// RCS ID
// $Id$
//
// CHANGE LOG
// $Log$
// Revision 1.10  2015/08/02 19:44:34  cwrapp
// Release 6.6.0 commit.
//
// Revision 1.9  2014/09/07 17:16:44  fperrad
// explicit condition
//
// Revision 1.8  2014/09/06 19:53:15  fperrad
// remove hard tab
//
// Revision 1.7  2014/09/06 09:02:18  fperrad
// pragma only for MS compiler
//
// Revision 1.6  2014/07/12 10:48:49  fperrad
// remove _rcs_id
//
// Revision 1.5  2009/03/01 18:20:37  cwrapp
// Preliminary v. 6.0.0 commit.
//
// Revision 1.4  2005/05/28 13:31:16  cwrapp
// Updated C++ examples.
//
// Revision 1.0  2003/12/14 19:06:42  charlesr
// Initial revision
//

#ifdef _MSC_VER
#pragma warning(disable: 4355)
#endif

#include "AppClass.h"
#include <map>

AppClass::AppClass()
#ifdef CRTP
: isAcceptable(false)
#else
: _fsm(*this),
  isAcceptable(false)
#endif
{
#ifdef FSM_DEBUG
#ifdef CRTP
    setDebugFlag(true);
#else
    _fsm.setDebugFlag(true);
#endif
#endif
}

bool AppClass::CheckString(const std::string &theString, std::map<std::string, int> &recipientCorrect)
{

    if (theString.empty()) return false;
    
    _fsm.enterStartState();

    for (; theString[char_num] != '\0'; ) {
        _fsm.Symbol(theString[char_num]);
        char_num++;
    }
    for (auto const& pair : recipientCorrect_in_smc) {
                // Проверяем, содержится ли ключ уже в существующей map
        auto it = recipientCorrect.find(pair.first);
        if(it != recipientCorrect.end()) {
                // Если ключ уже существует, увеличиваем счетчик на значение из tempMap
            it->second += pair.second;
        } else {
                // Если ключ уникален, добавляем его в существующую map
            recipientCorrect.insert(pair);
                }
            }
    
    // end of string has been reached - send the EOS transition.
    _fsm.EOS();
    return isAcceptable;
}

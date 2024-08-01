//
// ex: set ro:
// DO NOT EDIT.
// generated by smc (http://smc.sourceforge.net/)
// from file : AppClass.sm
//


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
// State Map
//	This state map is recognizes the regular expression 0*1*.
//
// RCS ID
// $Id$
//
// CHANGE LOG
// $Log$
// Revision 1.5  2005/05/28 13:31:16  cwrapp
// Updated C++ examples.
//
// Revision 1.1  2005/02/21 14:19:18  charlesr
// Added spaces around header file name to test SMC.
//
// Revision 1.0  2003/12/14 19:11:57  charlesr
// Initial revision
//


#include "AppClass.h"
#include "AppClass_sm.h"

using namespace statemap;

// Static class declarations.
Map1_Start Map1::Start("Map1::Start", 0);
Map1_Zeros Map1::Zeros("Map1::Zeros", 1);
Map1_Ones Map1::Ones("Map1::Ones", 2);
Map1_OK Map1::OK("Map1::OK", 3);
Map1_Error Map1::Error("Map1::Error", 4);

void AppClassState::EOS(AppClassContext& context)
{
    Default(context);
}

void AppClassState::One(AppClassContext& context)
{
    Default(context);
}

void AppClassState::Unknown(AppClassContext& context)
{
    Default(context);
}

void AppClassState::Zero(AppClassContext& context)
{
    Default(context);
}

void AppClassState::Default(AppClassContext& context)
{
    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "TRANSITION   : Default"
            << std::endl;
    }

    throw (
        TransitionUndefinedException(
            context.getState().getName(),
            context.getTransition()));

}

void Map1_Start::EOS(AppClassContext& context)
{
    AppClass& ctxt = context.getOwner();

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "LEAVING STATE   : Map1::Start"
                << std::endl;
    }

    context.getState().Exit(context);
    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "ENTER TRANSITION: Map1::Start::EOS()"
            << std::endl;
    }

    context.clearState();
    try
    {
        ctxt.Acceptable();
        if (context.getDebugFlag())
        {
            std::ostream& str = context.getDebugStream();

            str << "EXIT TRANSITION : Map1::Start::EOS()"
                << std::endl;
        }

        context.setState(Map1::OK);
    }
    catch (...)
    {
        context.setState(Map1::OK);
        throw;
    }
    context.getState().Entry(context);


}

void Map1_Start::One(AppClassContext& context)
{

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "LEAVING STATE   : Map1::Start"
                << std::endl;
    }

    context.getState().Exit(context);
    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "ENTER TRANSITION: Map1::Start::One()"
            << std::endl;
    }

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "EXIT TRANSITION : Map1::Start::One()"
            << std::endl;
    }

    context.setState(Map1::Ones);
    context.getState().Entry(context);


}

void Map1_Start::Unknown(AppClassContext& context)
{

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "LEAVING STATE   : Map1::Start"
                << std::endl;
    }

    context.getState().Exit(context);
    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "ENTER TRANSITION: Map1::Start::Unknown()"
            << std::endl;
    }

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "EXIT TRANSITION : Map1::Start::Unknown()"
            << std::endl;
    }

    context.setState(Map1::Error);
    context.getState().Entry(context);


}

void Map1_Start::Zero(AppClassContext& context)
{

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "LEAVING STATE   : Map1::Start"
                << std::endl;
    }

    context.getState().Exit(context);
    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "ENTER TRANSITION: Map1::Start::Zero()"
            << std::endl;
    }

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "EXIT TRANSITION : Map1::Start::Zero()"
            << std::endl;
    }

    context.setState(Map1::Zeros);
    context.getState().Entry(context);


}

void Map1_Zeros::EOS(AppClassContext& context)
{
    AppClass& ctxt = context.getOwner();

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "LEAVING STATE   : Map1::Zeros"
                << std::endl;
    }

    context.getState().Exit(context);
    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "ENTER TRANSITION: Map1::Zeros::EOS()"
            << std::endl;
    }

    context.clearState();
    try
    {
        ctxt.Acceptable();
        if (context.getDebugFlag())
        {
            std::ostream& str = context.getDebugStream();

            str << "EXIT TRANSITION : Map1::Zeros::EOS()"
                << std::endl;
        }

        context.setState(Map1::OK);
    }
    catch (...)
    {
        context.setState(Map1::OK);
        throw;
    }
    context.getState().Entry(context);


}

void Map1_Zeros::One(AppClassContext& context)
{

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "LEAVING STATE   : Map1::Zeros"
                << std::endl;
    }

    context.getState().Exit(context);
    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "ENTER TRANSITION: Map1::Zeros::One()"
            << std::endl;
    }

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "EXIT TRANSITION : Map1::Zeros::One()"
            << std::endl;
    }

    context.setState(Map1::Ones);
    context.getState().Entry(context);


}

void Map1_Zeros::Unknown(AppClassContext& context)
{

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "LEAVING STATE   : Map1::Zeros"
                << std::endl;
    }

    context.getState().Exit(context);
    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "ENTER TRANSITION: Map1::Zeros::Unknown()"
            << std::endl;
    }

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "EXIT TRANSITION : Map1::Zeros::Unknown()"
            << std::endl;
    }

    context.setState(Map1::Error);
    context.getState().Entry(context);


}

void Map1_Zeros::Zero(AppClassContext& context)
{

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "LEAVING STATE   : Map1::Zeros"
                << std::endl;
    }

    context.getState().Exit(context);
    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "ENTER TRANSITION: Map1::Zeros::Zero()"
            << std::endl;
    }

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "EXIT TRANSITION : Map1::Zeros::Zero()"
            << std::endl;
    }

    context.setState(Map1::Zeros);
    context.getState().Entry(context);


}

void Map1_Ones::EOS(AppClassContext& context)
{
    AppClass& ctxt = context.getOwner();

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "LEAVING STATE   : Map1::Ones"
                << std::endl;
    }

    context.getState().Exit(context);
    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "ENTER TRANSITION: Map1::Ones::EOS()"
            << std::endl;
    }

    context.clearState();
    try
    {
        ctxt.Acceptable();
        if (context.getDebugFlag())
        {
            std::ostream& str = context.getDebugStream();

            str << "EXIT TRANSITION : Map1::Ones::EOS()"
                << std::endl;
        }

        context.setState(Map1::OK);
    }
    catch (...)
    {
        context.setState(Map1::OK);
        throw;
    }
    context.getState().Entry(context);


}

void Map1_Ones::One(AppClassContext& context)
{

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "LEAVING STATE   : Map1::Ones"
                << std::endl;
    }

    context.getState().Exit(context);
    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "ENTER TRANSITION: Map1::Ones::One()"
            << std::endl;
    }

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "EXIT TRANSITION : Map1::Ones::One()"
            << std::endl;
    }

    context.setState(Map1::Ones);
    context.getState().Entry(context);


}

void Map1_Ones::Unknown(AppClassContext& context)
{

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "LEAVING STATE   : Map1::Ones"
                << std::endl;
    }

    context.getState().Exit(context);
    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "ENTER TRANSITION: Map1::Ones::Unknown()"
            << std::endl;
    }

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "EXIT TRANSITION : Map1::Ones::Unknown()"
            << std::endl;
    }

    context.setState(Map1::Error);
    context.getState().Entry(context);


}

void Map1_Ones::Zero(AppClassContext& context)
{

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "LEAVING STATE   : Map1::Ones"
                << std::endl;
    }

    context.getState().Exit(context);
    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "ENTER TRANSITION: Map1::Ones::Zero()"
            << std::endl;
    }

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "EXIT TRANSITION : Map1::Ones::Zero()"
            << std::endl;
    }

    context.setState(Map1::Error);
    context.getState().Entry(context);


}

void Map1_Error::EOS(AppClassContext& context)
{
    AppClass& ctxt = context.getOwner();

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "LEAVING STATE   : Map1::Error"
                << std::endl;
    }

    AppClassState& endState = context.getState();

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "ENTER TRANSITION: Map1::Error::EOS()"
            << std::endl;
    }

    context.clearState();
    try
    {
        ctxt.Unacceptable();
        if (context.getDebugFlag())
        {
            std::ostream& str = context.getDebugStream();

            str << "EXIT TRANSITION : Map1::Error::EOS()"
                << std::endl;
        }

        context.setState(endState);
    }
    catch (...)
    {
        context.setState(endState);
        throw;
    }


}

void Map1_Error::One(AppClassContext& context)
{

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "LEAVING STATE   : Map1::Error"
                << std::endl;
    }



}

void Map1_Error::Unknown(AppClassContext& context)
{

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "LEAVING STATE   : Map1::Error"
                << std::endl;
    }



}

void Map1_Error::Zero(AppClassContext& context)
{

    if (context.getDebugFlag())
    {
        std::ostream& str = context.getDebugStream();

        str << "LEAVING STATE   : Map1::Error"
                << std::endl;
    }



}

//
// Local variables:
//  buffer-read-only: t
// End:
//

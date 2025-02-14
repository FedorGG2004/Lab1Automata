//
// ex: set ro:
// DO NOT EDIT.
// generated by smc (http://smc.sourceforge.net/)
// from file : AppClass.sm
//

#ifndef APPCLASS_SM_H
#define APPCLASS_SM_H


#define SMC_USES_IOSTREAMS

#include <statemap.h>

// Forward declarations.
class Map1;
class Map1_Start;
class Map1_Mail;
class Map1_Name;
class Map1_At;
class Map1_FirstOst;
class Map1_Dot;
class Map1_SecondOst;
class Map1_Comma;
class Map1_Error;
class Map1_OK;
class Map1_Default;
class AppClassState;
class AppClassContext;
class AppClass;

class AppClassState :
    public statemap::State
{
public:

    AppClassState(const char * const name, const int stateId)
    : statemap::State(name, stateId)
    {};

    virtual void Entry(AppClassContext&) {};
    virtual void Exit(AppClassContext&) {};

    virtual void EOS(AppClassContext& context);
    virtual void Reset(AppClassContext& context);
    virtual void Symbol(AppClassContext& context, char smb);

protected:

    virtual void Default(AppClassContext& context);
};

class Map1
{
public:

    static Map1_Start Start;
    static Map1_Mail Mail;
    static Map1_Name Name;
    static Map1_At At;
    static Map1_FirstOst FirstOst;
    static Map1_Dot Dot;
    static Map1_SecondOst SecondOst;
    static Map1_Comma Comma;
    static Map1_Error Error;
    static Map1_OK OK;
};

class Map1_Default :
    public AppClassState
{
public:

    Map1_Default(const char * const name, const int stateId)
    : AppClassState(name, stateId)
    {};

    virtual void Symbol(AppClassContext& context, char smb);
    virtual void EOS(AppClassContext& context);
    virtual void Reset(AppClassContext& context);
};

class Map1_Start :
    public Map1_Default
{
public:
    Map1_Start(const char * const name, const int stateId)
    : Map1_Default(name, stateId)
    {};

    virtual void EOS(AppClassContext& context);
    virtual void Symbol(AppClassContext& context, char smb);
};

class Map1_Mail :
    public Map1_Default
{
public:
    Map1_Mail(const char * const name, const int stateId)
    : Map1_Default(name, stateId)
    {};

    virtual void EOS(AppClassContext& context);
    virtual void Symbol(AppClassContext& context, char smb);
};

class Map1_Name :
    public Map1_Default
{
public:
    Map1_Name(const char * const name, const int stateId)
    : Map1_Default(name, stateId)
    {};

    virtual void EOS(AppClassContext& context);
    virtual void Symbol(AppClassContext& context, char smb);
};

class Map1_At :
    public Map1_Default
{
public:
    Map1_At(const char * const name, const int stateId)
    : Map1_Default(name, stateId)
    {};

    virtual void EOS(AppClassContext& context);
    virtual void Symbol(AppClassContext& context, char smb);
};

class Map1_FirstOst :
    public Map1_Default
{
public:
    Map1_FirstOst(const char * const name, const int stateId)
    : Map1_Default(name, stateId)
    {};

    virtual void EOS(AppClassContext& context);
    virtual void Symbol(AppClassContext& context, char smb);
};

class Map1_Dot :
    public Map1_Default
{
public:
    Map1_Dot(const char * const name, const int stateId)
    : Map1_Default(name, stateId)
    {};

    virtual void EOS(AppClassContext& context);
    virtual void Symbol(AppClassContext& context, char smb);
};

class Map1_SecondOst :
    public Map1_Default
{
public:
    Map1_SecondOst(const char * const name, const int stateId)
    : Map1_Default(name, stateId)
    {};

    virtual void EOS(AppClassContext& context);
    virtual void Symbol(AppClassContext& context, char smb);
};

class Map1_Comma :
    public Map1_Default
{
public:
    Map1_Comma(const char * const name, const int stateId)
    : Map1_Default(name, stateId)
    {};

    virtual void EOS(AppClassContext& context);
    virtual void Symbol(AppClassContext& context, char smb);
};

class Map1_Error :
    public Map1_Default
{
public:
    Map1_Error(const char * const name, const int stateId)
    : Map1_Default(name, stateId)
    {};

    virtual void EOS(AppClassContext& context);
};

class Map1_OK :
    public Map1_Default
{
public:
    Map1_OK(const char * const name, const int stateId)
    : Map1_Default(name, stateId)
    {};

};

class AppClassContext :
    public statemap::FSMContext
{
public:

    explicit AppClassContext(AppClass& owner)
    : FSMContext(Map1::Start),
      _owner(owner)
    {};

    AppClassContext(AppClass& owner, const statemap::State& state)
    : FSMContext(state),
      _owner(owner)
    {};

    virtual void enterStartState()
    {
        getState().Entry(*this);
        return;
    }

    inline AppClass& getOwner()
    {
        return (_owner);
    };

    inline AppClassState& getState()
    {
        if (_state == NULL)
        {
            throw statemap::StateUndefinedException();
        }

        return dynamic_cast<AppClassState&>(*_state);
    };

    inline void EOS()
    {
        setTransition("EOS");
        getState().EOS(*this);
        setTransition(NULL);
    };

    inline void Reset()
    {
        setTransition("Reset");
        getState().Reset(*this);
        setTransition(NULL);
    };

    inline void Symbol(char smb)
    {
        setTransition("Symbol");
        getState().Symbol(*this, smb);
        setTransition(NULL);
    };

private:
    AppClass& _owner;
};


#endif // APPCLASS_SM_H

//
// Local variables:
//  buffer-read-only: t
// End:
//

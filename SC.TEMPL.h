//Created by David Tran (UnsignedZero)
//for the simple purpose of stream checking
//Verison 0.1.4.1

#ifndef SC_H
 #include "SC.H"
 #ifndef SC_H
  #error SC.H does not exist.\
   SC HEADER/DECLARATION Missing!
 #endif
#endif

#ifndef SC_TEMPL_H
 #define SC_TEMPL_H true

namespace zx{
///Prototype Function//////////////////////////////////////////////////

//--
  template <class type> void StreamFix( type& var , type defaultval);
  // Fixes CIN and write "default" value into var
    // Call Aliases
    template <class type>
    void StreamFix( type& var , type* defaultval ){
      if ( defaultval == NULL ) { defaultval = new type(); }
      StreamFix( var , *defaultval );
      }
    template <class type>
    void SF( type& var , type defaultval ){
      StreamFix( var , defaultval );
      }
    template <class type>
    void SF( type& var , type* defaultval ){
      if ( defaultval == NULL ) { defaultval = new type(); }
      StreamFix( var , *defaultval );
      }
    #if(ZX_SC_CONST==true)
      template <class type>
      void StreamFix( type& var , const type constvar ){
        try{ type defaultval = constvar;}
        catch (...){std::cout << ZX_SC_ERROREQUAL;}
        StreamFix( var , defaultval );
        }
      template <class type>
      void StreamFix( type& var , type* const constvar ){
        try{ type* defaultval = constvar;}
        catch (...){std::cout << ZX_SC_ERROREQUAL;}
        StreamFix( var , *defaultval );
        }
      template <class type>
      void SF( type& var , const type constvar ){
        try{ type defaultval = constvar;}
        catch (...){std::cout << ZX_SC_ERROREQUAL;}
        StreamFix( var , defaultval );
        }
      template <class type>
      void SF( type& var , type* const constvar ){
        try{ type* defaultval = constvar;}
        catch (...){std::cout << ZX_SC_ERROREQUAL;}
        StreamFix( var , *defaultval );
        }
    #endif

//--
  template <class type> void StreamFix( std::istream&, type&, type);
  // Fixes IFSTREAM and write "default" value into var
    // Call Aliases
    template <class type>
    void StreamFix( std::istream& stream, type& var , type* defaultval){
      if ( defaultval == NULL ) { defaultval = new type(); }
      StreamFix( stream , var , *defaultval );
      }
    template <class type>
    void SF( std::istream& stream , type& var, type defaultval){
      StreamFix( stream , var , defaultval );
      }
    template <class type>
    void SF( std::istream& stream, type& var , type* defaultval){
      if ( defaultval == NULL ) { defaultval = new type(); }
      StreamFix( stream , var , *defaultval );
      }
    #if(ZX_SC_CONST==true)
      template <class type>
      void StreamFix( std::istream& stream, type& var , const type constvar ){
        try{ type defaultval = constvar;}
        catch (...){std::cout << ZX_SC_ERROREQUAL;}
        StreamFix( stream, var , defaultval );
        }
      template <class type>
      void StreamFix( std::istream& stream, type& var , type* const constvar ){
        try{ type* defaultval = constvar;}
        catch (...){std::cout << ZX_SC_ERROREQUAL;}
        StreamFix( stream, var , *defaultval );
        }
      template <class type>
      void SF( std::istream& stream, type& var , const type constvar ){
        try{ type defaultval = constvar;}
        catch (...){std::cout << ZX_SC_ERROREQUAL;}
        StreamFix( stream, var , defaultval );
        }
      template <class type>
      void SF( std::istream& stream, type& var , type* const constvar ){
        try{ type* defaultval = constvar;}
        catch (...){std::cout << ZX_SC_ERROREQUAL;}
        StreamFix( stream, var , *defaultval );
        }
    #endif

//--
  template <class type> void StreamFix( std::ifstream&, type&, type);
  // Fixes IFSTREAM and write "default" value into var
    // Call Aliases
    template <class type>
    void StreamFix( std::ifstream& stream, type& var , type* defaultval){
      if ( defaultval == NULL ) { defaultval = new type(); }
      StreamFix( stream , var , *defaultval );
      }
    template <class type>
    void SF( std::ifstream& stream , type& var, type defaultval){
      StreamFix( stream , var , defaultval );
      }
    template <class type>
    void SF( std::ifstream& stream, type& var , type* defaultval){
      if ( defaultval == NULL ) { defaultval = new type(); }
      StreamFix( stream , var , *defaultval );
      }
    #if(ZX_SC_CONST==true)
      template <class type>
      void StreamFix( std::ifstream& stream, type& var , const type constvar ){
        try{ type defaultval = constvar;}
        catch (...){std::cout << ZX_SC_ERROREQUAL;}
        StreamFix( stream, var , defaultval );
        }
      template <class type>
      void StreamFix( std::ifstream& stream, type& var , type* const constvar ){
        try{ type* defaultval = constvar;}
        catch (...){std::cout << ZX_SC_ERROREQUAL;}
        StreamFix( stream, var , *defaultval );
        }
      template <class type>
      void SF( std::ifstream& stream, type& var , const type constvar ){
        try{ type defaultval = constvar;}
        catch (...){std::cout << ZX_SC_ERROREQUAL;}
        StreamFix( stream, var , defaultval );
        }
      template <class type>
      void SF( std::ifstream& stream, type& var , type* const constvar ){
        try{ type* defaultval = constvar;}
        catch (...){std::cout << ZX_SC_ERROREQUAL;}
        StreamFix( stream, var , *defaultval );
        }
    #endif

//--

///Prototype Function//////////////////////////////////////////////////

///Template Functions//////////////////////////////////////////////////

///--------------------------------------------------------------------
template <class type>
void StreamFix( type& var, type defaultval){

  if(!std::cin) {
    std::string error;
    #if(ZX_SC_WARNING==true)
    try{
      std::cout
        << ZX_SC_DEBUGBORDER
        << ZX_SC_CLI
        << "Bad Input Detected. Recovering CINStream.\n"
        << "Input replaced with " << defaultval
        << ZX_SC_DEBUGBORDER;}
      catch(...){ std::cout << ZX_SC_CLI << ZX_SC_ERRORDLEFT; }
    #endif
    std::cin.clear();
    std::cin >> error;
    try{ var = defaultval; }
    catch(...){ std::cout << ZX_SC_CLI << ZX_SC_ERROREQUAL; }
    }

  #if(ZX_SC_WARNING==true)
    if (std::cin) { std::cout << "\n!! CINStream Sent !Nothing Happened!!\n"; }
    try{
      std::cout
        << ZX_SC_CLI
        << "The value is now "
        << var
        << ZX_SC_DEBUGBORDER;
      }
    catch(...){ std::cout << ZX_SC_CLI << ZX_SC_ERRORDLEFT; }
  #endif

  #if((ZOS_H==true)&&(ZX_SC_WARNING==true))
    OSP(1);
  #endif
}
///--------------------------------------------------------------------
template <class type>
void StreamFix(std::istream& stream, type& var, type defaultval){

  if(!stream) {
    std::string error;
    #if(ZX_SC_WARNING==true)
      try{
        std::cout
        << ZX_SC_DEBUGBORDER
        << ZX_SC_CLI
        << "Bad Input Detected. Recovering IStream.\n"
        << "Input replaced with" << defaultval
        << ZX_SC_DEBUGBORDER;
        }
      catch(...){ std::cout << ZX_SC_CLI << ZX_SC_ERRORDLEFT; }
    #endif
    stream.clear();
    stream >> error;
    try{ var = defaultval; }
    catch(...){ std::cout << ZX_SC_CLI << ZX_SC_ERROREQUAL; }
    }

  #if(ZX_SC_WARNING==true)
    if (stream) { std::cout << "\n!!IStream GOOD!Nothing Happened!!\n"; }
    try{
      std::cout
        << ZX_SC_CLI
        << "The value is now "
        << var
        << ZX_SC_DEBUGBORDER;
      }
    catch(...){ std::cout << ZX_SC_CLI << ZX_SC_ERRORDLEFT; }
  #endif

  #if((ZOS_H==true)&&(ZX_SC_WARNING==true))
    OSP(1);
  #endif

}
///--------------------------------------------------------------------
template <class type>
void StreamFix(std::ifstream& stream, type& var, type defaultval){

  if(!stream) {
    std::string error;
    #if(ZX_SC_WARNING==true)
      try{
        std::cout
        << ZX_SC_DEBUGBORDER
        << ZX_SC_CLI
        << "Bad Input Detected. Recovering IFStream.\n"
        << "Input replaced with" << defaultval
        << ZX_SC_DEBUGBORDER;
        }
      catch(...){ std::cout << ZX_SC_CLI << ZX_SC_ERRORDLEFT; }
    #endif
    stream.clear();
    stream >> error;
    try{ var = defaultval; }
    catch(...){ std::cout << ZX_SC_CLI << ZX_SC_ERROREQUAL; }
    }

  #if(ZX_SC_WARNING==true)
    if (stream) { std::cout << "\n!!IFStream GOOD !Nothing Happened!!\n"; }
    try{
      std::cout
        << ZX_SC_CLI
        << "The value is now "
        << var
        << ZX_SC_DEBUGBORDER;
      }
    catch(...){ std::cout << ZX_SC_CLI << ZX_SC_ERRORDLEFT; }
  #endif

  #if((ZOS_H==true)&&(ZX_SC_WARNING))
    OSP(1);
  #endif

}
///--------------------------------------------------------------------

}
///Template Functions//////////////////////////////////////////////////

#endif

//Created by David Tran (UnsignedZero)
//for the simple purpose of stream checking
//Verison 0.1.4.1 Build 2

/* This program was built so that
 * it could check if a stream is down.
 * These function are made to "recovery"
 * downed streams due to a bad input/output.
 *
 * There is a CPP for this file!
 */

#ifndef SC_H
 #define SC_H true

//Warning Mode by default is OFF
#ifndef ZX_SC_CONST
 #define ZX_SC_CONST false
#endif

#ifndef ZX_SC_WARNING
 #define ZX_SC_WARNING false
#endif

#define ZX_SC_CLI "SC> "

//ERROR STRINGS
#define ZX_SC_ERROREQUAL  "\n!!No operator =  defined for var !!\n"
#define ZX_SC_ERRORDLEFT  "\n!!No operator << defined for var !!\n"
#define ZX_SC_DEBUGBORDER "\n<>!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!<>\n"

#include <iostream>
#include <fstream>
#include <cstdlib> // FOR NULL
#include <string>

namespace zx{

#if(ZOS_H==false)
 void OSP( int );
#endif

#ifndef ZOS_H
 #define ZOS_H false
 void OSP( int );
#endif

///NON-TEMPLATE FUNCTIONS

///Prototype Function//////////////////////////////////////////////////

//--
  void StreamCheck();
  // Fixes bad CIN Stream
    // Call Aliases
    void SC(){ StreamCheck(); }

//--
  void StreamCheck( std::istream& );
  // Fixes bad IStream
    // Call Aliases
    void SC( std::istream& stream ){ StreamCheck( stream ); }

//--
  void StreamCheck( std::ifstream& );
  // Fixes bad IFSTREAM
    // Call Aliases
    void SC( std::ifstream& stream ){ StreamCheck( stream ); }

//--
  void StreamRecover( std::string& );
  // Recovers bad CIN stream and sends that bad data into a string
    // Call Aliases
    void StreamRecover( std::string* error ){
      if ( error == NULL ) { error = new std::string; }
      StreamRecover( *error );
      }
    void SR( std::string& error ){ StreamRecover( error ); }
    void SR( std::string* error ){
      if ( error == NULL ) { error = new std::string; }
      StreamRecover( error );
      }
    #if(ZX_SC_CONST==true)
      void StreamRecover( std::string* const input ){
        std::string* error = input;
        StreamRecover( error );
        }
      void SR( std::string* const input ){
        std::string* error = input;
        StreamRecover( error );
        }
    #endif

//--
  void StreamRecover( std::istream&, std::string& );
  // Recovers bad IFSTREAM and sends that bad data into a
  // string
    // Call Aliases
    void StreamRecover( std::istream& stream , std::string* error ){
      if ( error == NULL ) { error = new std::string; }
      StreamRecover( stream , *error );
      }
    void SR( std::istream& stream, std::string& error ){
      StreamRecover( stream , error );
      }
    void SR( std::istream& stream, std::string* error ){
      if ( error == NULL ) { error = new std::string; }
      StreamRecover( stream , *error );
      }
    #if(ZX_SC_CONST==true)
      void StreamRecover( std::istream& stream , std::string* const input ){
        std::string* error = input;
        StreamRecover( stream , *error );
        }
      void SR( std::istream& stream , std::string* const input ){
        std::string* error = input;
        StreamRecover( stream , *error );
        }
    #endif

//--
  void StreamRecover( std::ifstream&, std::string& );
  // Recovers bad IFSTREAM and sends that bad data into a
  // string
    // Call Aliases
    void StreamRecover( std::ifstream& stream , std::string* error ){
      if ( error == NULL ) { error = new std::string; }
      StreamRecover( stream , *error );
      }
    void SR( std::ifstream& stream, std::string& error ){
      StreamRecover( stream , error );
      }
    void SR( std::ifstream& stream, std::string* error ){
      if ( error == NULL ) { error = new std::string; }
      StreamRecover( stream , *error );
      }
    #if(ZX_SC_CONST==true)
      void StreamRecover( std::ifstream& stream , std::string* const input ){
        std::string* error = input;
        StreamRecover( stream , *error );
        }
      void SR( std::ifstream& stream , std::string* const input ){
        std::string* error = input;
        StreamRecover( stream , *error );
        }
    #endif


///Prototype Function//////////////////////////////////////////////////

}

#ifndef SC_TEMPL_H
 #include "SC.TEMPL.h"
 #ifndef SC_TEMPL_H
  #error SC.TEMPL.H does not exist.\
  SC Template Functions Missing!
 #endif
#endif

#ifndef SC_CPP
 #include "SC.cpp"
 #ifndef SC_CPP
  #error SC.CPP does not exist.\
  SC IMPLEMENTATION Missing!
 #endif
#endif

#endif

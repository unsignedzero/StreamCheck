//Created by David Tran (UnsignedZero)
//for the simple purpose of stream checking
//Verison 0.1.4.1 Build 2

/* This program was built so that
 * it could check if a stream is down.
 * These function are made to "recovery"
 * downed streams due to a bad input/output.
 *
 * There is a H for this file!
 */

#ifndef SC_CPP
 #define SC_CPP true

#ifndef SC_H
 #include "SC.H"
 #ifndef SC_H
  #error SC.H does not exist.\
   SC HEADER/DECLARATION Missing!
 #endif
#endif

namespace zx{

///--------------------------------------------------------------------
void StreamCheck() {

  if(!std::cin) {
    std::string error;
    #if(ZX_SC_WARNING==true)
      std::cout
        << ZX_SC_DEBUGBORDER
        << ZX_SC_CLI
        << "Bad Input Detected. Recovering CINStream.\n"
        << "No Character Replaced"
        << ZX_SC_DEBUGBORDER;
    #endif
    std::cin.clear();
    std::cin >> error;
    }

  #if(ZX_SC_WARNING==true)
    if (std::cin) { std::cout << ZX_SC_CLI << "\n!!CIN was GOOD!Nothing Happened!!\n"; }
    std::cout
      << ZX_SC_CLI
      << "CINStream fixed"
      << ZX_SC_DEBUGBORDER;
  #endif

  #if((ZOS_H==true)&&(ZX_SC_WARNING==true))
    zx::OSP(1);
  #endif

}
///--------------------------------------------------------------------
void StreamCheck( std::istream& stream ) {

  if(!stream) {
    std::string error;
    #if(ZX_SC_WARNING==true)
    std::cout
      << ZX_SC_DEBUGBORDER
      << ZX_SC_CLI
      << "Bad Input Detected. Recovering IStream.\n"
      << "No Character Replaced"
      << ZX_SC_DEBUGBORDER;
    #endif
    stream.clear();
    stream >> error;
    }

  #if(ZX_SC_WARNING==true)
    if (stream) { std::cout << ZX_SC_CLI << "\n!!IStream was GOOD!Nothing Happened!!\n"; }
    std::cout
      << ZX_SC_CLI
      << "IStream fixed"
      << ZX_SC_DEBUGBORDER;
    #endif

  #if((ZOS_H==true)&&(ZX_SCWARNING==true))
    zx::OSP(1);
  #endif

}
///--------------------------------------------------------------------
void StreamCheck( std::ifstream& stream ) {

  if(!stream) {
    std::string error;
    #if(ZX_SC_WARNING==true)
    std::cout
      << ZX_SC_DEBUGBORDER
      << ZX_SC_CLI
      << "Bad Input Detected. Recovering IFStream.\n"
      << "No Character Replaced"
      << ZX_SC_DEBUGBORDER;
    #endif
    stream.clear();
    stream >> error;
    }

  #if(ZX_SC_WARNING==true)
    if (stream) { std::cout << ZX_SC_CLI << "\n!!Good Stream Sent !Nothing Happened!!\n"; }
    std::cout
      << ZX_SC_CLI
      << "IFStream fixed"
      << ZX_SC_DEBUGBORDER;
  #endif

  #if((ZOS_H==true)&&(ZX_SC_WARNING==true))
    zx::OSP(1);
  #endif

}
///--------------------------------------------------------------------
void StreamRecover( std::string& error ){

  if(!std::cin) {
    #if(ZX_SC_WARNING==true)
    std::cout
      << ZX_SC_DEBUGBORDER
      << ZX_SC_CLI
      << "Bad Input Detected. Recovering CINStream.\n"
      << "No Character Replaced"
      << ZX_SC_DEBUGBORDER;
    #endif
    std::cin.clear();
    std::cin >> error;
    }

  #if(ZX_SC_WARNING==true)
    if (std::cin) { std::cout << "\n!!CIN was GOOD!Nothing Happened!!\n"; }
    std::cout
      << ZX_SC_CLI
      << "CINStream fixed"
      << ZX_SC_DEBUGBORDER;
  #endif

  #if((ZOS_H==true)&&(ZX_SC_WARNING==true))
    zx::OSP(1);
  #endif

}
///--------------------------------------------------------------------
void StreamRecover( std::istream& stream, std::string& error ){

  if(!stream) {
    #if(ZX_SC_WARNING==true)
    std::cout
      << ZX_SC_DEBUGBORDER
      << ZX_SC_CLI
      << "Bad Input Detected. Recovering IStream.\n"
      << "No Character Replaced"
      << ZX_SC_DEBUGBORDER;
    #endif
    stream.clear();
    stream >> error;
    }

  #if(ZX_SC_WARNING==true)
    if (stream) { std::cout << "\n!!IStream was GOOD!Nothing Happened!!\n"; }
    std::cout
      << ZX_SC_CLI
      << "IStream fixed"
      << ZX_SC_DEBUGBORDER;
  #endif

  #if((ZOS_H==true)&&(ZX_SC_WARNING==true))
    zx::OSP(1);
  #endif

}
///--------------------------------------------------------------------
void StreamRecover( std::ifstream& stream,  std::string& error ){

  if(!stream) {
    #if(ZX_SC_WARNING==true)
    std::cout
      << ZX_SC_DEBUGBORDER
      << ZX_SC_CLI
      << "Bad Input Detected. Recovering IFStream.\n"
      << "No Character Replaced"
      << ZX_SC_DEBUGBORDER;
    #endif
    stream.clear();
    stream >> error;
    }

  #if(ZX_SC_WARNING==true)
    if (stream) { std::cout << "\n!!IFStream was GOOD!Nothing Happened!!\n"; }
    std::cout
      << ZX_SC_CLI
      << "IFStream fixed"
      << ZX_SC_DEBUGBORDER;
  #endif

  #if((ZOS_H==true)&&(ZX_SC_WARNING==true))
    zx::OSP(1);
  #endif

}
///--------------------------------------------------------------------

}
#endif


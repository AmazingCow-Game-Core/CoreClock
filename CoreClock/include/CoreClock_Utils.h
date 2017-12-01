//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : CoreClock_Utils.h                                             //
//  Project   : CoreClock                                                     //
//  Date      : Nov 29, 2015                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2015 - 2017                                      //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

#pragma once

//----------------------------------------------------------------------------//
// Namespace                                                                  //
//----------------------------------------------------------------------------//
//All classes of this core is placed inside this namespace.
//We use MACROS so is easier to change if needed.
//Is (in our opinion) more explicit.
//And finally the editors will not reformat the code.
#define NS_CORECLOCK_BEGIN namespace CoreClock {
#define NS_CORECLOCK_END   }
#define USING_NS_CORECLOCK using namespace CoreClock


//----------------------------------------------------------------------------//
// Version                                                                    //
//----------------------------------------------------------------------------//
//The core version number.
#define COW_CORECLOCK_VERSION_MAJOR    "0"
#define COW_CORECLOCK_VERSION_MINOR    "4"
#define COW_CORECLOCK_VERSION_REVISION "4"

#define COW_CORECLOCK_VERSION       \
    COW_CORECLOCK_VERSION_MAJOR "." \
    COW_CORECLOCK_VERSION_MINOR "." \
    COW_CORECLOCK_VERSION_REVISION

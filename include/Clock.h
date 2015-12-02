//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        Clock.h                                   //
//             ████████████         CoreClock                                 //
//           █              █       Copyright (c) 2015 AmazingCow             //
//          █     █    █     █      www.AmazingCow.com                        //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
//                                                                            //
//                                                                            //
//                  This software is licensed as GPLv3                        //
//                 CHECK THE COPYING FILE TO MORE DETAILS                     //
//                                                                            //
//    Permission is granted to anyone to use this software for any purpose,   //
//   including commercial applications, and to alter it and redistribute it   //
//               freely, subject to the following restrictions:               //
//                                                                            //
//     0. You **CANNOT** change the type of the license.                      //
//     1. The origin of this software must not be misrepresented;             //
//        you must not claim that you wrote the original software.            //
//     2. If you use this software in a product, an acknowledgment in the     //
//        product IS HIGHLY APPRECIATED, both in source and binary forms.     //
//        (See opensource.AmazingCow.com/acknowledgment.html for details).    //
//        If you will not acknowledge, just send us a email. We'll be         //
//        *VERY* happy to see our work being used by other people. :)         //
//        The email is: acknowledgmentopensource@AmazingCow.com               //
//     3. Altered source versions must be plainly marked as such,             //
//        and must notbe misrepresented as being the original software.       //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//

#ifndef __CoreClock_include_Clock_h__
#define __CoreClock_include_Clock_h__

//COWTODO: Add doxygen comments.

//std
#include <functional>
//CoreClock
#include "CoreClock_Utils.h"

NS_CORECLOCK_BEGIN

class Clock
{
    // Constants/Enums/Typedefs //
public:
    static const int kRepeatForever;
    typedef std::function<void ()> Callback;

    // CTOR / DTOR //
public:
    Clock();

    Clock(float interval);
    Clock(float interval, int repeat);

    Clock(float interval, const Callback &callback);
    Clock(float interval, int repeat, const Callback &callback);

    virtual ~Clock();

    // Public Methods //
public:
    //Action Methods.
    void start();
    void stop();

    void update(float dt);

    //Setters/Getters.
    void setInterval(float interval);
    float getInterval() const;

    void setRepeatCount(int count);
    int getRepeatCount() const;
    int getTickCount() const;

    void setTickCallback(const Callback &callback);
    const Callback& getTickCallback() const;

    // iVars //
public:
    float m_interval;

    int m_repeatCount;
    int m_tickCount;

    Callback m_callback;

    bool  m_enabled;
    float m_updateTime;
};

NS_CORECLOCK_END
#endif // defined(__CoreClock_include_Clock_h__) //

//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        Clock.h                                   //
//            █ █        █ █        CoreClock                                 //
//             ████████████                                                   //
//           █              █       Copyright (c) 2015, 2016                  //
//          █     █    █     █      AmazingCow - www.AmazingCow.com           //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
//                                                                            //
//                  This software is licensed as GPLv3                        //
//                 CHECK THE COPYING FILE TO MORE DETAILS                     //
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

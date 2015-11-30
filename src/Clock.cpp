//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        Clock.cpp                                 //
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


//Header
#include "../Clock.h"

//Usings
USING_NS_CORECLOCK;

// Constants/Enums/Typedefs //
const int BasicClock::kRepeatForever = -1;

// CTOR / DTOR //
BasicClock::BasicClock() :
    BasicClock(0)
{
    //Empty...
}
BasicClock::BasicClock(float interval) :
    BasicClock(interval, BasicClock::kRepeatForever)
{
    //Empty...
}
BasicClock::BasicClock(float interval, int repeat):
    BasicClock(interval, BasicClock::kRepeatForever, Callback())
{
    //Empty...
}

BasicClock::BasicClock(float interval, const Callback &callback) :
    BasicClock(interval, BasicClock::kRepeatForever, Callback())
{
    //Empty...
}

BasicClock::BasicClock(float interval, int repeat, const Callback &callback) :
    m_interval   (interval),
    m_repeatCount(repeat),
    m_tickCount  (0),
    m_callback   (callback),
    m_enabled    (false),
    m_updateTime (interval)
{
    //Empty...
}


BasicClock::~BasicClock()
{
    //Empty...
}

// Public Methods //
//Action Methods.
void BasicClock::start()
{
    m_tickCount = 0;

    m_enabled    = true;
    m_updateTime = m_interval;
}
void BasicClock::stop()
{
    m_enabled = false;
}

void BasicClock::update(float dt)
{
    if(!m_enabled)
        return;
    
    m_updateTime -= dt;
    if(m_updateTime <= 0)
    {
        m_updateTime = m_interval;
        ++m_tickCount;
        
        if(m_callback)
            m_callback();
    }
}

//Setters/Getters.
void BasicClock::setInterval(float interval)
{
    m_interval = interval;
}
float BasicClock::getInterval() const
{
    return m_interval;
}

void BasicClock::setRepeatCount(int count)
{
    m_repeatCount = count;
}
int BasicClock::getRepeatCount() const
{
    return m_repeatCount;
}
int BasicClock::getTickCount() const
{
    return m_tickCount;
}

void BasicClock::setTickCallback(const Callback &callback)
{
    m_callback = callback;
}
const BasicClock::Callback& BasicClock::getTickCallback() const
{
    return m_callback;
}

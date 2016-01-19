//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        Clock.cpp                                 //
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


//Header
#include "../include/Clock.h"

//Usings
USING_NS_CORECLOCK;

// Constants/Enums/Typedefs //
const int Clock::kRepeatForever = -1;

// CTOR / DTOR //
Clock::Clock() :
    Clock(0)
{
    //Empty...
}
Clock::Clock(float interval) :
    Clock(interval, Clock::kRepeatForever)
{
    //Empty...
}
Clock::Clock(float interval, int repeat):
    Clock(interval, Clock::kRepeatForever, Callback())
{
    //Empty...
}

Clock::Clock(float interval, const Callback &callback) :
    Clock(interval, Clock::kRepeatForever, Callback())
{
    //Empty...
}

Clock::Clock(float interval, int repeat, const Callback &callback) :
    m_interval   (interval),
    m_repeatCount(repeat),
    m_tickCount  (0),
    m_callback   (callback),
    m_enabled    (false),
    m_updateTime (interval)
{
    //Empty...
}


Clock::~Clock()
{
    //Empty...
}

// Public Methods //
//Action Methods.
void Clock::start()
{
    m_tickCount = 0;

    m_enabled    = true;
    m_updateTime = m_interval;
}
void Clock::stop()
{
    m_enabled = false;
}

void Clock::update(float dt)
{
    if(!m_enabled)
        return;

    if(m_repeatCount != Clock::kRepeatForever && m_tickCount >= m_repeatCount)
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
void Clock::setInterval(float interval)
{
    m_interval = interval;
}
float Clock::getInterval() const
{
    return m_interval;
}

void Clock::setRepeatCount(int count)
{
    m_repeatCount = count;
}
int Clock::getRepeatCount() const
{
    return m_repeatCount;
}
int Clock::getTickCount() const
{
    return m_tickCount;
}

void Clock::setTickCallback(const Callback &callback)
{
    m_callback = callback;
}
const Clock::Callback& Clock::getTickCallback() const
{
    return m_callback;
}

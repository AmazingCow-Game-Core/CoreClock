//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Clock.cpp                                                     //
//  Project   : CoreClock                                                     //
//  Date      : Nov 29, 2015                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2015 - 2017                                      //
//                                                                            //
//  Description :                                                             //
//                                                                            //
//---------------------------------------------------------------------------~//

// Header
#include "../include/Clock.h"

// Usings
USING_NS_CORECLOCK;

//----------------------------------------------------------------------------//
// Constants / Enums / Typedefs                                               //
//----------------------------------------------------------------------------//
const int Clock::kRepeatForever = -1;


//----------------------------------------------------------------------------//
// CTOR / DTOR                                                                //
//----------------------------------------------------------------------------//
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
    Clock(interval,
          repeat,
          Callback(), //Tick
          Callback()) //Done
{
    //Empty...
}

Clock::Clock(float            interval,
             const Callback &tickCallback,
             const Callback &doneCallback /* = Callback() */ ) :
    Clock(interval,
          Clock::kRepeatForever,
          tickCallback,
          doneCallback)
{
    //Empty...
}

Clock::Clock(float           interval,
             int             repeat,
             const Callback &tickCallback,
             const Callback &doneCallback /* = Callback() */) :
    // Members.
    m_interval    (    interval),
    m_repeatCount (      repeat),
    m_tickCount   (           0),
    m_tickCallback(tickCallback),
    m_doneCallback(doneCallback),
    m_enabled     (       false),
    m_updateTime  (    interval)
{
    //Empty...
}


//----------------------------------------------------------------------------//
// Action Methods                                                             //
//----------------------------------------------------------------------------//
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

        if(m_tickCallback)
            m_tickCallback();

        if(m_tickCount == m_repeatCount && m_doneCallback)
            m_doneCallback();
    }
}


//----------------------------------------------------------------------------//
// Interval Methods                                                           //
//----------------------------------------------------------------------------//
void Clock::setInterval(float interval)
{
    m_interval = interval;
}

float Clock::getInterval() const
{
    return m_interval;
}


//----------------------------------------------------------------------------//
// Repeat Count Methods                                                       //
//----------------------------------------------------------------------------//
void Clock::setRepeatCount(int count)
{
    m_repeatCount = count;
}
int Clock::getRepeatCount() const
{
    return m_repeatCount;
}


//----------------------------------------------------------------------------//
// Tick Count / Query Methods                                                 //
//----------------------------------------------------------------------------//
int Clock::getTickCount() const
{
    return m_tickCount;
}

bool Clock::isDone() const
{
    return m_tickCount == m_repeatCount;
}


//----------------------------------------------------------------------------//
// Callback Methods                                                           //
//----------------------------------------------------------------------------//
void Clock::setTickCallback(const Callback &callback)
{
    m_tickCallback = callback;
}

const Clock::Callback& Clock::getTickCallback() const
{
    return m_tickCallback;
}

void Clock::setDoneCallback(const Callback &callback)
{
    m_doneCallback = callback;
}

const Clock::Callback& Clock::getDoneCallback() const
{
    return m_doneCallback;
}

//~---------------------------------------------------------------------------//
//                     _______  _______  _______  _     _                     //
//                    |   _   ||       ||       || | _ | |                    //
//                    |  |_|  ||       ||   _   || || || |                    //
//                    |       ||       ||  | |  ||       |                    //
//                    |       ||      _||  |_|  ||       |                    //
//                    |   _   ||     |_ |       ||   _   |                    //
//                    |__| |__||_______||_______||__| |__|                    //
//                             www.amazingcow.com                             //
//  File      : Clock.h                                                       //
//  Project   : CoreClock                                                     //
//  Date      : Nov 29, 2015                                                  //
//  License   : GPLv3                                                         //
//  Author    : n2omatt <n2omatt@amazingcow.com>                              //
//  Copyright : AmazingCow - 2015 - 2017                                      //
//                                                                            //
//  Description :                                                             //
//                                                                            //
///---------------------------------------------------------------------------~/

#pragma once

// std
#include <functional> // std::function
// CoreClock
#include "CoreClock_Utils.h"


NS_CORECLOCK_BEGIN

class Clock
{
    //------------------------------------------------------------------------//
    // Constants / Enums / Typedefs                                           //
    //------------------------------------------------------------------------//
public:
    ///-------------------------------------------------------------------------
    /// @brief
    ///   Makes the clock ticks forever.
    ///   The stop control must be manually set.
    static const int kRepeatForever;

    ///-------------------------------------------------------------------------
    /// @brief
    ///   Just to ease the typing the type.
    ///   This is the signature of the function that will be called when
    ///   the Clock's interval/repeat count is reached.
    typedef std::function<void ()> Callback;


    //------------------------------------------------------------------------//
    // CTOR / DTOR                                                            //
    //------------------------------------------------------------------------//
public:
    ///-------------------------------------------------------------------------
    /// @brief
    ///   Constructs the Clock as:                 \n
    ///     interval     = 0.                      \n
    ///     repeat       = Clock::kRepeatForever.  \n
    ///     tickCallback = "none".                 \n
    ///     doneCallback = "none".                 \n
    /// @note
    ///   The Clock must be started manually.
    /// @see
    ///   Clock::setInterval(), Clock::setRepeatCount(),
    ///   Clock::setTickCallback(), Clock::setDoneCallback().
    Clock();

    ///-------------------------------------------------------------------------
    /// @brief
    ///   Constructs the Clock as:                 \n
    ///     interval     = as given.               \n
    ///     repeat       = Clock::kRepeatForever.  \n
    ///     tickCallback = "none".                 \n
    ///     doneCallback = "none".                 \n
    /// @param interval
    ///   A positive value.
    /// @note
    ///   The Clock must be started manually.
    /// @warning
    ///   No checks are made by the CTORs - Is the caller responsibility
    ///   of give consistent and valid values.
    /// @see
    ///   Clock::setInterval(), Clock::setRepeatCount(),
    ///   Clock::setTickCallback(), Clock::setDoneCallback().
    Clock(float interval);

    ///-------------------------------------------------------------------------
    /// @brief
    ///   Constructs the Clock as:    \n
    ///     interval     = as given.  \n
    ///     repeat       = as given.  \n
    ///     tickCallback = "none".    \n
    ///     doneCallback = "none".    \n
    /// @param interval
    ///   A positive value.
    /// @param repeat
    ///   A positive value or Clock::kRepeatForever.
    /// @note
    ///   The Clock must be started manually.
    /// @warning
    ///   No checks are made by the CTORs - Is the caller responsibility
    ///   of give consistent and valid values.
    /// @see
    ///   Clock::setInterval(), Clock::setRepeatCount(),
    ///   Clock::setTickCallback(), Clock::setDoneCallback().
    Clock(float interval, int repeat);

    ///-------------------------------------------------------------------------
    /// @brief
    ///   Constructs the Clock as:                   \n
    ///       interval     = as given.               \n
    ///       repeat       = Clock::kRepeatForever.  \n
    ///       tickCallback = as given.               \n
    ///       doneCallback = "none".                 \n
    /// @param interval
    ///   A positive value.
    /// @param callback
    ///   The function that will be called when
    ///   interval is reached.
    /// @note
    ///   The Clock must be started manually.
    /// @warning
    ///   No checks are made by the CTORs - Is the caller responsibility
    ///   of give consistent and valid values.
    /// @see
    ///   Clock::setInterval(), Clock::setRepeatCount(),
    ///   Clock::setTickCallback(), Clock::setDoneCallback().
    Clock(float           interval,
          const Callback &tickCallback,
          const Callback &doneCallback = Callback());

    ///-------------------------------------------------------------------------
    /// @brief
    ///   Constructs the Clock with the given arguments.
    /// @param interval
    ///   A positive value.
    /// @param repeat
    ///   A positive value or Clock::kRepeatForever.
    /// @param tickCallback
    ///   The function that will be called when interval is reached.
    /// @param doneCallback
    ///   The function that will be called when repeatCount is reached.
    /// @note
    ///   The Clock must be started manually.
    /// @warning
    ///   No checks are made by the CTORs - Is the caller responsibility
    ///   of give consistent and valid values.
    /// @see
    ///   Clock::setInterval(), Clock::setRepeatCount(),
    ///   Clock::setTickCallback(), Clock::setDoneCallback().
    Clock(float           interval,
          int             repeat,
          const Callback &tickCallback,
          const Callback &doneCallback = Callback());


    //------------------------------------------------------------------------//
    // Action Methods                                                         //
    //------------------------------------------------------------------------//
public:
    ///-------------------------------------------------------------------------
    /// @brief
    ///   Starts the clock, i.e it will be enabled in Clock::update.
    ///   If the current tick count is less the repeat count,
    ///   the Clock will call the callback when the interval is reached.
    /// @note
    ///   This will reset the Clock internal structure, so if you want
    ///   to inspect the previous state of the object, you must do
    ///   this before call the Clock::start() method.
    /// @see
    ///   Clock::stop(), Clock::update(), Clock::getInterval(),
    ///   Clock::getTickCount(), Clock::getRepeatCount(),
    ///   Clock::getTickCallback(), Clock::getDoneCallback()
    void start();

    ///-------------------------------------------------------------------------
    /// @brief
    ///   Stops the clock, i.e it will not be enabled in Clock::update.
    /// @see
    ///   Clock::start(), Clock::update(), Clock::getInterval(),
    ///   Clock::getTickCount(), Clock::getRepeatCount(),
    ///   Clock::getTickCallback(), Clock::getDoneCallback()
    void stop();


    //------------------------------------------------------------------------//
    // Update Methods                                                         //
    //------------------------------------------------------------------------//
public:
    ///-------------------------------------------------------------------------
    /// @brief
    ///   Updates the current amount of "time" (The unit is irrelevant, but
    ///   must be consistent at the same object) and possibly fire the
    ///   callback if the conditions are met, otherwise the update method
    ///   is just a early return call.
    /// @note
    ///   The callback is fired if:                       \n
    ///     1 - Clock is enabled                          \n
    ///     2 - Tick count is < than Repeat Count or      \n
    ///         Clock::kRepeatForever is set.
    ///     3 - Interval is reached - Pretty obvious.     \n
    ///     4 - Callback is set     - Pretty obvious too. \n
    /// @see
    ///   Clock::start(), Clock::stop(), Clock::getInterval(),
    ///   Clock::getTickCount(), Clock::getRepeatCount(),
    ///   Clock::getTickCallback(), Clock::getDoneCallback()
    void update(float dt);


    //------------------------------------------------------------------------//
    // Interval Methods                                                       //
    //------------------------------------------------------------------------//
public:
    ///-------------------------------------------------------------------------
    /// @brief
    ///   Sets the interval (the unit is irrelevant, but must be consistent at
    ///   the same object) time for the Clock.
    /// @param interval
    ///   A positive value.
    /// @see
    ///   Clock::getInterval().
    void setInterval(float interval);

    ///-------------------------------------------------------------------------
    /// @brief
    ///   Gets the current interval.
    /// @returns
    ///   The current interval.
    /// @see
    ///   Clock::setInterval().
    float getInterval() const;


    //------------------------------------------------------------------------//
    // Repeat Count Methods                                                   //
    //------------------------------------------------------------------------//
public:
    ///-------------------------------------------------------------------------
    /// @brief
    ///   Sets the Repeat Count.
    /// @note
    ///   When the Clock::getTickCount() value is greater than the
    ///   Clock::getRepeatCount() the update method will stop fire
    ///   the tickCallback.
    /// @note
    ///   Whem the Clock::getTickCount() value is equal to the
    ///   Clock::getRepeatCount() the update method will fire a doneCallback
    ///   if it set.
    /// @param count
    ///   A positive value or Clock::kRepeatForever.
    /// @see
    ///   Clock::getTickCount(), Clock::getRepeatCount().
    void setRepeatCount(int count);

    ///-------------------------------------------------------------------------
    ///@brief
    ///     Gets the current Repeat Count.
    ///@returns
    ///     The current Repeat Count.
    ///@see
    ///     Clock::getTickCount(), Clock::setRepeatCount().
    int getRepeatCount() const;


    //------------------------------------------------------------------------//
    // Tick Count / Query Methods                                             //
    //------------------------------------------------------------------------//
public:
    ///-------------------------------------------------------------------------
    /// @brief
    ///   Gets the current Tick Count.
    /// @returns
    ///   The current Tick Count.
    /// @see
    ///   Clock::getRepeatCount().
    int getTickCount() const;

    ///-------------------------------------------------------------------------
    /// @brief Return if the Clock::getTickCount() == Clock::getRepeatCount();
    bool isDone() const;


    //------------------------------------------------------------------------//
    // Callback Methods                                                       //
    //------------------------------------------------------------------------//
public:
    ///-------------------------------------------------------------------------
    /// @brief
    ///   Set the function that will be called when the conditions are met
    ///   in Clock::update().
    /// @param callback
    ///   A valid callback function.
    void setTickCallback(const Callback &callback);

    ///-------------------------------------------------------------------------
    /// @brief Gets the const ref for the callback.
    const Callback& getTickCallback() const;

    ///-------------------------------------------------------------------------
    /// @brief
    ///   Set the function that will be called when the
    ///   Clock::getTickCount() == Clock::getRepeatCount().
    /// @param callback
    ///   A valid callback function.
    void setDoneCallback(const Callback &callback);

    ///-------------------------------------------------------------------------
    /// @brief Gets the const ref for the callback.
    const Callback& getDoneCallback() const;


    //------------------------------------------------------------------------//
    // iVars                                                                  //
    //------------------------------------------------------------------------//
public:
    float m_interval;

    int m_repeatCount;
    int m_tickCount;

    Callback m_tickCallback;
    Callback m_doneCallback;

    bool  m_enabled;
    float m_updateTime;
};

NS_CORECLOCK_END

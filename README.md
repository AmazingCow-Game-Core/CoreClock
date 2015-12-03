Core Coord 
====
Made with <3 by [Amazing Cow](http://www.amazingcow.com).

<!-- ####################################################################### -->

## Intro:

In some games we need to perform some operation repeatedly, or after some time, 
so instead of messing with ```ivars``` to keep track of time and all other "low-level"
stuff we decide to create the ```Clock``` class to keep it very encapsulated.

For example, let's assume that we want to trigger some operation 3 times with 
1 second between them. One possible implementation could be:

```
//In SomeClass.h
...
float m_timeSinceLastTick;
float m_timeToTick; 
float m_repeatTickCount;
...

//In SomeClass.cpp
void SomeClass::initClock()
{
    m_timeSinceLastTick = 0;
    m_timeToTick        = 1000; //Milliseconds...
    m_repeatTickCount   = 3;    //We gonna decrement it...
}

void SomeClass::update(float dt)
{
    m_timeSinceLastTick += dt;
    if(m_repeatTickCount > 0 && m_timeSinceLastTick >= m_timeToTick)
    {
        m_timeSinceLastUpdate -= m_timeToTick;
        
        this->doSomethingCool(); //Trigger the tick action.

        --m_repeatTickCount;
    }
}
```

We find this very, very cumbersome, not clear, ugly...    
We prefer:

```
//In SomeClass.h
...
CoreClock::Clock m_clock;
...

//In SomeClass.cpp
void SomeClass::initClock()
{
    m_clock.setInterval(1000);
    m_clock.setRepeatCount(3);
    
    //This can be a lambda, a Functor etc...
    m_clock.setCallback(std::bind(&SomeClass::doSomethingCool,this));

    m_clock.start();
}

void SomeClass::update(float dt)
{
    //Clock will ignore updates after 3 ticks...
    m_clock.update(dt);
}
```

Much more easier hun???

You are welcome to use, hack and share it :)

<!-- ####################################################################### -->

## Files:

We tried to separated the files in a very organized form.   
Here is a list of them:

* ```CoreClock.h```
* ```CoreClock_Utils.h```
* ```Clock.h```


<!-- ####################################################################### -->

## Usage:

#COWTODO

<!-- ####################################################################### -->

## More info:

We tried to document the Core extensively, so we think that is pretty ease to 
get what the Core is doing, the API calls and stuff.   
Anyway if you didn't understand something let us know sending a mail to 
***help_opensource@amazingcow.com***  with the subject filled with the
name of this repo.


<!-- ####################################################################### -->

## License:
This software is released under GPLv3.


<!-- ####################################################################### -->

## TODO:
Check the TODO file.


<!-- ####################################################################### -->

## Others:
Check our repos and take a look at our [open source site](http://opensource.amazingcow.com).

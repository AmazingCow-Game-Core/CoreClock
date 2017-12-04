# CoreClock

**Made with <3 by [Amazing Cow](http://www.amazingcow.com).**


<!-- ####################################################################### -->
<!-- Websites                                                                -->
<!-- ####################################################################### -->

## Websites:

General:
* [Amazing Cow's page](http://www.amazingcow.com).
* [Amazing Cow's Github](https://github.com/AmazingCow).

Libs:
* [Amazing Cow's Libs page](https://github.com/AmazingCow-Libs).
* [Amazing Cow's Libs Github](http://www.amazingcow.com/libs).



<!-- ####################################################################### -->
<!-- Description                                                             -->
<!-- ####################################################################### -->

## Description:

```CoreClock``` is a small library intended to easy the time tracking in games,
but it general enough to be used in a myriad of situations.  
It can be used to _fire events_ after some time, giving a very flexible way 
to handle animations, callbacks and other stuff. 

As usual, you are **very welcomed** to **share** and **hack** it.

### Motivation:

In some games we need to perform some operation repeatedly, or after some time.    
So instead of messing with _ivars_ to keep track of time and all other _"low-level"_
stuff we decide to create the ```CoreClock``` class to keep it very encapsulated.


<!-- ####################################################################### -->
<!-- Examples                                                                -->
<!-- ####################################################################### -->

## Examples:

Let's imagine a scenario that we want to trigger some operation 3 times with 
1 second between them. This will let us appreciate how CoreClock will ease our lives.

#### One possible implementation could be:

```c++
///////////////////////////
//In SomeClass.h         //
///////////////////////////
float m_timeSinceLastTick;
float m_timeToTick; 
float m_repeatTickCount;


///////////////////////////
//In SomeClass.cpp       //
///////////////////////////
void SomeClass::initClock()
{
    m_timeSinceLastTick = 0;
    m_timeToTick        = 1000; //Milliseconds...
    m_repeatTickCount   = 3;    //We gonna decrement it...
}

void SomeClass::update(float dt)
{
    //This is straightforward, but we don't like to have to 
    //do this every time that we need a timer of some sort.
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

#### With CoreClock:

```c++
/////////////////////////
//In SomeClass.h       //
/////////////////////////
CoreClock::Clock m_clock;
...

///////////////////////////
//In SomeClass.cpp       //
///////////////////////////
void SomeClass::initClock()
{
    m_clock.setInterval(1000); //Ms, but can be anything that you like.
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


<!-- ####################################################################### -->
<!-- Building                                                                -->
<!-- ####################################################################### -->

## Building:

```CoreClock``` is intended to be include as source in your project.  
So to use it, just grab the whole CoreClock directory, put it in your 
project and setup the include paths in the compiler.

As example, let's imagine that you are copying it to a directory called ```libs```.
In your build script you need to do just the following:

``` bash
g++ -I /path/to/libs/CoreClock \
    ... Other stuff ...        \
    /path/to/libs/CoreClock/CoreClock/src/Clock.cpp 
```


<!-- ####################################################################### -->
<!-- Documentation                                                           -->
<!-- ####################################################################### -->

## Documentation:

We strive to make our source code fully documented.   
While there are a myriad of comments, one might find useful take a look at:

* [Doxygen Docs](http://www.amazingcow.com/docs/CoreClock/).

Anyway if you didn't understand something let us know sending a mail to  
[help_floss@amazingcow.com]() with the subject filled with the name of this repo.



<!-- ####################################################################### -->
<!-- Dependencies                                                            -->
<!-- ####################################################################### -->

## Dependencies:

There is no dependency for ```CoreClock```.



<!-- ####################################################################### -->
<!-- License                                                                 -->
<!-- ####################################################################### -->

## License:

This software is **proudly** released under [GPLv3](https://www.gnu.org/licenses/gpl-3.0.en.html).


<!-- ####################################################################### -->
<!-- BUGS                                                                    -->
<!-- ####################################################################### -->

## BUGS:

We strive to make all our code the most bug-free as possible - But we know 
that few of them can pass without we notice ;).

Please if you find any bug report to [bugs_floss@amazingcow.com]() 
with the name of this project and/or create an issue here in Github.


<!-- ####################################################################### -->
<!-- TODO                                                                    -->
<!-- ####################################################################### -->

## TODO:

Check the TODO file for general things.

This projects uses the COWTODO tags.   
So install [cowtodo](http://www.github.com/AmazingCow-Tools/COWTODO) and run:

``` bash
$ cd path/to/the/project
$ cowtodo 
```

That's gonna give you all things to do :D.


<!-- ####################################################################### -->
<!-- Others                                                                  -->
<!-- ####################################################################### -->

## Others:

Check our other Free Software repos and take a look at our 
[free software site](http://www.amazingcow.com/floss).


#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>
#include <algorithm>

class Timer
{
public:
    Timer();
    ~Timer();

    //Compute delta time as the number of milliseconds since the last frame
    unsigned int computeDeltaTime();
    //Wait if the game runs faster than the decided FPS
    void delayTime();
    //Get time since the game started, in seconds
    static double getTimeSinceStart()
    {
        return timeSinceStart;
    }

private:
    const static int FPS = 60;
    const static int frameDelay = 1000 / FPS;
    const unsigned int MAX_DT = 50;

    //Time in milliseconds when frame starts
    unsigned int frameStart;

    //Last frame start time in milliseconds
    unsigned int lastFrame;

    //Time it took to run the loop. Used to cap framerate
    unsigned int frameTime;

    //Time in seconds since the game started
    static double timeSinceStart;
};
#endif
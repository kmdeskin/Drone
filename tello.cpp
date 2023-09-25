/*
my code essentially establishes a connection to the Tello drone, sends it a series of commands 
(takeoff, spin, land), and includes delays to ensure that the drone has time to perform these actions.
*/

#include <iostream>
#include "ctello.h"
//include ctello to acess the tello drone library 

using namespace ctello;
//i used the tello funcionality 

int main() {
    Tello tello;

    if (!tello.Bind()) {
        std::cerr << "failed to bind to Tello" << std::endl;
        return 1;
        //this line of code gives a warning that the drone failed to bind 
        //return with exit code of 1
    }

    tello.SendCommand("takeoff");
    //takeoff drone
    
    std::this_thread::sleep_for(std::chrono::seconds(5));
    //delay for a couple seconds and have tello sleep so it can take off 


    tello.SendCommand("cw 360");
    //have the drone perform a 360 spin

    std::this_thread::sleep_for(std::chrono::seconds(5));

    tello.SendCommand("land");
    //have tello drone land

    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}

#include <bits/stdc++.h>
int findAngle(int hour, int minute){
    //convert hour to 12 hour format 
    hour = hour % 12;
    //hour hand angle each hour cover 30 degree and 
    //each minute move 0.5 degree 
    float hourangle = hour*30 + (minute*0.5);
    //on each minute the minute angle move 6 degree
    float minuteangle = minute * 6;
    //calculate minimum angle
    float angle = abs(hourangle - minuteangle);
    //take minimum angle
    angle = min(angle, 360-angle);
    //return floor value
    return floor(angle);
}
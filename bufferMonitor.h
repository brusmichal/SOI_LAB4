//
// Created by mbrus on 20/12/2020.
//

#ifndef LAB4_BUFFERMONITOR_H
#define LAB4_BUFFERMONITOR_H

#include "queue"
#include "string"
#include "iostream"
#include "monitor.h"

#define MAX_DELAY 10 //maximum delay in seconds
#define MAX_BUFFER_SIZE 10
#define PORTION_SIZE 50 //portion weight in grams


class BufferMonitor{
private:
    std::queue <int> buffer;
    std::string name;
    int portion;
    Monitor monitor;
    Condition fullAvailable;
    Condition emptyAvailable;
public:
    BufferMonitor(const std::string& name);

    void produce();
    void consume();
};



#endif //LAB4_BUFFERMONITOR_H

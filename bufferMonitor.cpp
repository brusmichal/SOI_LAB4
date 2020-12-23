//
// Created by mbrus on 20/12/2020.
//

#include "bufferMonitor.h"

BufferMonitor::BufferMonitor(const std::string& name) : name(name), portion(
        PORTION_SIZE), fullAvailable(Condition()), emptyAvailable(Condition()) {};

void BufferMonitor::produce() {
    monitor.enter();
    if(buffer.size() == MAX_BUFFER_SIZE){
        monitor.wait(emptyAvailable);
    }
    else if (buffer.size() < MAX_BUFFER_SIZE){
        std::cout<<"=====================================================================" << std::endl;
        std::cout << name << " portions: "<< buffer.size()  <<std::endl;
        buffer.push(portion);
        std::cout << "Added a portion of " << name << " to buffer." << std::endl;
        std::cout << name << " portions: "<< buffer.size()  <<std::endl;
        monitor.signal(fullAvailable);
    };
    monitor.leave();
}

void BufferMonitor::consume() {
    monitor.enter();
    if(buffer.empty()){
        monitor.wait(fullAvailable);
    }
    else{

        std::cout << name << " portions: "<< buffer.size()  <<std::endl;
        buffer.pop();
        std::cout << "Removed a portion of " << name << " from buffer." << std::endl;
        std::cout << name << " portions: "<< buffer.size()  <<std::endl;
        monitor.signal(emptyAvailable);
    };
    monitor.leave();


}


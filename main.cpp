#include "bufferMonitor.h"
#include "thread"
#include "chrono"
#include "string"


BufferMonitor bufferDough("Dough");
BufferMonitor bufferMeat("Meat");
BufferMonitor bufferCheese("Cheese");
BufferMonitor bufferCabbage("Cabbage");

void ProduceMeat();
void ProduceDough();
void ProduceCheese();
void ProduceCabbage();
void ConsumeMD();
void ConsumeCHD();
void ConsumeCD();

std::chrono::seconds RandomDelay();

int main(int argc, char* argv[]){
    int nProducers, nConsumers;
    if(argc == 1) {
        nProducers = 1;
        nConsumers = 1;
    }
    else if (argc == 3){
            nProducers = std::stoi(argv[1]);
            nConsumers = std::stoi(argv[2]);
        }
    else
        throw "Give me no or two parameters.\n";

    std::vector <std::thread> threadsVector;


    for(int i=0; i < nProducers; i++){
        threadsVector.emplace_back(std::thread(ProduceDough));
        threadsVector.emplace_back(std::thread(ProduceMeat));
        threadsVector.emplace_back(std::thread(ProduceCheese));
        threadsVector.emplace_back(std::thread(ProduceCabbage));
    };
    for(int i=0; i < nConsumers; i++){
       threadsVector.emplace_back(std::thread(ConsumeMD));
       threadsVector.emplace_back(std::thread(ConsumeCHD));
       threadsVector.emplace_back(std::thread(ConsumeCD));

    };
    for(auto &it: threadsVector){
        it.join();
    }

}

std::chrono::seconds RandomDelay() {
    auto delay = std::chrono::seconds(rand() % MAX_DELAY + 1);
    return delay;
};

void ProduceDough(){
    while (true){
        std::this_thread::sleep_for(RandomDelay() % 5);
        bufferDough.produce();
    }
}
void ProduceMeat(){
    while (true){
        std::this_thread::sleep_for(RandomDelay());
        bufferMeat.produce();
    }
};
void ProduceCheese(){
    while (true){
        std::this_thread::sleep_for(RandomDelay());
        bufferCheese.produce();
    }
};
void ProduceCabbage(){
    while (true){
        std::this_thread::sleep_for(RandomDelay());
        bufferCabbage.produce();
    }
};
void ConsumeMD(){
    while (true){
        std::this_thread::sleep_for(RandomDelay());
        std::cout<<"=====================================================================" << std::endl;
        std::cout << "Eating meat dumpling." << std::endl;
        bufferDough.consume();
        bufferMeat.consume();
    }
}
void ConsumeCHD(){
    while (true){
        std::this_thread::sleep_for(RandomDelay());
        std::cout<<"=====================================================================" << std::endl;
        std::cout << "Eating cheese dumpling." << std::endl;
        bufferDough.consume();
        bufferCheese.consume();
    }
}
void ConsumeCD(){
    while (true){
        std::this_thread::sleep_for(RandomDelay());
        std::cout<<"=====================================================================" << std::endl;
        std::cout << "Eating cabbage dumpling." << std::endl;
        bufferDough.consume();
        bufferCabbage.consume();
    }
}








#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <stdio.h>

void t(std::string url){
    std::string cmd  = "curl " + url;
    while(1){    

        system(cmd.c_str());
        
    }
}

int main() {

    std::vector<std::thread*> threads;
    
    int THREAD_COUNT;
    std::string url;

    std::cout << "Enter URL: ";
    std::cin >> url;

    std::cout << "Number of Threads: ";

    std::cin >> THREAD_COUNT;

    std::cout << "Now running " << THREAD_COUNT << " threads at " << url << std::endl;

    std::thread* temp;

    for (int i = 0; i<THREAD_COUNT; i++){
        temp = new std::thread(t, url);
        threads.push_back(temp);
    }

    for (int i = 0; i<THREAD_COUNT; i++){
        threads[i]->join();
    }

    return 0;
}
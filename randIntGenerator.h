#pragma once
#include <random>
std::random_device rd; 
std::mt19937 mersenne(rd());
int generateInt(){
    return mersenne();
}

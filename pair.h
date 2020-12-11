#pragma once

#include <string>

struct pair {
    std::string word;
    int distance;
};

bool operator<(const pair& x, const pair& y)
{
    if (x.distance < y.distance) return true;
    else return false;
}

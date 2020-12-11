#include "pair.h"
#include "min_bucket.h"
#include <iostream>

int main()
{
    min_bucket<pair> bkt(2);
    bkt.insert({"bubble",1});
    bkt.insert({"apple",3});
    bkt.insert({"bugle",1});

    std::cout << bkt[0].word << " " << bkt[0].distance << std::endl;
    std::cout << bkt[1].word << " " << bkt[1].distance << std::endl;
}
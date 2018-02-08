//
// Created by virgil on 08.02.2018.
//

#include <cstdint>
#include <cstdio>
#include <cstring>

struct S
{
    uint8_t a1;
    uint16_t a2;
    uint32_t a3;
    int64_t a4;
    float x;
    float y;
    float z;
    uint64_t val;
};

int main()
{
    // brace initializer
    S s1;
    s1 = {};

    // memset
    S s3;
    memset(&s3, 0, sizeof(s3));

    return 0;
}
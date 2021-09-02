#include "Bitmask.hpp"

Bitmask::Bitmask() : bits(0)
{

}

Bitmask::Bitmask(uint32_t bits) : bits(bits)
{
    
}

void Bitmask::setMask(Bitmask& other)
{
    bits = other.getMask();
}

uint32_t Bitmask::getMask() const
{
    return bits;
}

bool Bitmask::getBit(int pos) const
{
    return (bits & (1 << pos)) != 0;
}

// A simple helper method that calls set or clear bit
void Bitmask::setBit(int pos, bool on)
{
    if (on)
    {
        setBit(pos);
    }
    else
    {
        clearBit(pos);
    }
}

void Bitmask::setBit(int pos)
{
    bits = bits | 1 << pos;
}

void Bitmask::clearBit(int pos)
{
    bits = bits & ~(1 << pos);
}

void Bitmask::clear()
{
    bits = 0;
}
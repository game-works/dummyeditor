#include <cstdint>
#include "dummy/startingpoint.h"

Dummy::StartingPoint::StartingPoint()
{

}

Dummy::StartingPoint::StartingPoint(const char* mapName,
                                    std::uint16_t x,
                                    std::uint16_t y)
    : m_mapName(mapName), m_x(x), m_y(y)
{

}

Dummy::StartingPoint& Dummy::StartingPoint::setMapName(const char* mapName)
{
    m_mapName = mapName;
    return *this;
}

Dummy::StartingPoint& Dummy::StartingPoint::setX(std::uint16_t x)
{
    m_x = x;
    return *this;
}

Dummy::StartingPoint& Dummy::StartingPoint::setY(std::uint16_t y)
{
    m_y = y;
    return *this;
}

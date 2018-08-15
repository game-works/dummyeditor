#include <QDebug>
#include <QDataStream>

#include "layer.h"

Dummy::Layer::Layer(std::uint16_t width, std::uint16_t height) :
    std::vector<std::tuple<std::int16_t, std::int16_t>>(width * height),
    m_width(width), m_height(height)
{
    reset();
}

void Dummy::Layer::reset() {
    for (auto it = begin(); it != end(); ++it) {
        *it = std::make_tuple(-1, -1);
    }
}

void Dummy::Layer::resizeMap(std::uint16_t width, std::uint16_t height) {
    m_width = width;
    m_height = height;
    resize(m_width * m_height);
}

void Dummy::Layer::_loadFromStream(QDataStream& stream) {
    for (auto it = begin(); it != end(); ++it) {
        quint16 i, j;
        stream >> i >> j;
        *it = std::make_tuple(i, j);
    }
}

void Dummy::Layer::_writeToStream(QDataStream& stream) const {
    for (auto it = begin(); it != end(); ++it) {
        qDebug() << std::get<0>(*it) << std::get<1>(*it);
        stream << std::get<0>(*it) << std::get<1>(*it);
    }
}

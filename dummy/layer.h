#ifndef LAYER_H
#define LAYER_H

#include <QDataStream>
#include <cstdint>
#include <tuple>
#include <vector>


namespace Dummy {
    class Layer : public std::vector<std::tuple<std::int16_t, std::int16_t>>
    {
    public:
        Layer(std::uint16_t, std::uint16_t);

        void reset();

        void resizeMap(std::uint16_t, std::uint16_t);

        friend QDataStream& operator>>(QDataStream& stream,
                                       Dummy::Layer& layer) {
            layer._loadFromStream(stream);
            return stream;
        }

        friend QDataStream& operator<<(QDataStream& stream,
                                       const Dummy::Layer& layer) {
            layer._writeToStream(stream);
            return stream;
        }

        Layer& setTile(quint16 x, quint16 y, qint16 chipsetX, qint16 chipsetY);

    private:
        void _writeToStream(QDataStream&) const;
        void _loadFromStream(QDataStream&);

        std::uint16_t m_width, m_height;
    };

}

#endif // LAYER_H

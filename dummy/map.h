#pragma once

#include <QVector>
#include <QString>
#include <QtGlobal>

#include <cstdint>
#include <string>
#include <memory>

#include "dummy/layer.h"

class QDataStream;
class QFile;

namespace Dummy {

    class Project;

    class Map
    {
    public:
        Map(const Project& project,
            std::uint16_t width = 1,
            std::uint16_t height = 1);

        virtual ~Map();

        inline const Project& project() const {
            return m_project;
        }

        inline unsigned short version() const {
            return m_version;
        }

        const std::wstring& name() const {
            return m_name;
        }

        std::uint16_t width() const {
            return m_width;
        }

        std::uint16_t height() const {
            return m_height;
        }

        const std::wstring& chipset() const {
            return m_chipset;
        }

        const std::wstring& music() const {
            return m_music;
        }

        const std::wstring& backgroundPicture() const {
            return m_backgroundPicture;
        }

        Map& setVersion(unsigned short version) {
            m_version = version;
            return *this;
        }

        Map& setName(const std::wstring& name) {
            m_name = name;
            return *this;
        }

        Map& setWidth(std::uint16_t width) {
            m_width = width;
            return *this;
        }

        Map& setHeight(std::uint16_t height) {
            m_height = height;
            return *this;
        }

        Map& setChipset(const std::wstring& chipset) {
            m_chipset = chipset;
            return *this;
        }

        Map& setMusic(const std::wstring& music) {
            m_music = music;
            return *this;
        }

        Map& setBackgroundPicture(const std::wstring& backgroundPicture) {
            m_backgroundPicture = backgroundPicture;
            return *this;
        }

        inline Layer& firstLayer() {
            return m_firstLayer;
        }

        inline Layer& secondLayer() {
            return m_secondLayer;
        }

        inline Layer& thirdLayer() {
            return m_thirdLayer;
        }

        static std::shared_ptr<Map> loadFromFile(const Project&,
                                                 const std::wstring& filename);
        static std::shared_ptr<Map> loadFromFile(const Project&, QFile& file);

        void saveToFile(const std::wstring& filename) const;
        void saveToFile(QFile& file) const;

        friend QDataStream& operator<<(QDataStream& stream,
                                       const Dummy::Map& map) {
            map._writeToStream(stream);
            return stream;
        }

        friend QDataStream& operator>>(QDataStream& stream,
                                       Dummy::Map& map) {
            map._loadFromStream(stream);
            return stream;
        }

    private:

        void _loadFromStream(QDataStream&);
        void _writeToStream(QDataStream&) const;

        const Project& m_project;
        unsigned short m_version;
        std::wstring m_name;
        std::uint16_t m_width, m_height; // Map dimension
        std::wstring m_chipset;
        std::wstring m_music;
        std::wstring m_backgroundPicture;
        Layer m_firstLayer, m_secondLayer, m_thirdLayer;
    };
}

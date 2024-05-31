//
// Created by 翁廷豪 on 2024/3/6.
//

#ifndef BACKGROUND_IMAGE_HPP
#define BACKGROUND_IMAGE_HPP

#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

class BackgroundImage : public Util::GameObject {

public:
    BackgroundImage() : GameObject(
            std::make_unique<Util::Image>(RESOURCE_DIR"/Image/Background/Map/map0.png"), -10) {
        m_ImagePath = RESOURCE_DIR"/Image/Background/Map/map0.png";
    }

    void NextPhase(const int phase) {
        auto temp = std::dynamic_pointer_cast<Util::Image>(m_Drawable);
        temp->SetImage(ImagePath(phase));
    }

    void SetImage(const std::string& ImagePath) {
        auto temp = std::dynamic_pointer_cast<Util::Image>(m_Drawable);
        temp->SetImage(ImagePath);
        m_ImagePath = ImagePath;
    }

    [[nodiscard]] const std::string& GetImagePath() const { return m_ImagePath; }

private:
    inline std::string ImagePath(const int phase) {
        if (phase == 15) {
            m_ImagePath = RESOURCE_DIR"/Image/Background/Map/mapBoss.png";
            return m_ImagePath;
        }
        else {
            m_ImagePath = RESOURCE_DIR"/Image/Background/Map/map" + std::to_string(phase) + ".png";
            return m_ImagePath;
        }
    }

    std::string m_ImagePath;
};

#endif //BACKGROUND_IMAGE_HPP

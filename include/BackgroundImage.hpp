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
            std::make_unique<Util::Image>("/Users/wengtinghao/-tiptree/Resources/Image/Background/background_test.png"), -10) {
    }

    void NextPhase(const int phase) {
        auto temp = std::dynamic_pointer_cast<Util::Image>(m_Drawable);
        temp->SetImage(ImagePath(phase));
    }

private:
    inline std::string ImagePath(const int phase) {
        return "/Users/wengtinghao/-tiptree/Resources/Image/Background/background_test.png";
    }
};

#endif //BACKGROUND_IMAGE_HPP

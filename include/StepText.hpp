//
// Created by 翁廷豪 on 2024/3/11.
//

#ifndef STEPTEXT_HPP
#define STEPTEXT_HPP

#include "Util/GameObject.hpp"
#include "Util/Text.hpp"
#include "Util/Color.hpp"

class StepText : public Util::GameObject {
public:
    StepText() : GameObject(
            std::make_unique<Util::Text>(RESOURCE_DIR"/Font/Inkfree.ttf", 100,
                                         convert_int_to_string(s_PhaseTasks[0] - 1),
                                         Util::Color::FromName(Util::Colors::WHITE)),
            100) {
        m_Transform.translation = {-530.0F, -215.F};
    }

    void ShowLeftStep() {
        auto temp = std::dynamic_pointer_cast<Util::Text>(m_Drawable);
        temp->SetText(convert_int_to_string(step--));
    }

    void UpdatePhaseStep(const int phase) {
        step = s_PhaseTasks[phase];
    }

    //TODO: find out why == -2
    [[nodiscard]] bool IsStepZero() const{
        return step == -2;
    }

private:
    inline static std::string convert_int_to_string(int step) {
        return std::to_string(step);
    }

    //TODO: add the limit step in each phase here
    static constexpr int s_PhaseTasks[6] = {
            26,
            28,
    };

    int step = s_PhaseTasks[0];

};

#endif //STEPTEXT_HPP

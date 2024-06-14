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
            std::make_unique<Util::Text>(RESOURCE_DIR"/Font/Inkfree.ttf", 80,
                                         convert_int_to_string(s_PhaseTasks[0] - 1),
                                         Util::Color::FromName(Util::Colors::WHITE)),
            100) {
        m_Transform.translation = {-530.0F, -215.F};
    }

    void ShowLeftStep() {
        auto temp = std::dynamic_pointer_cast<Util::Text>(m_Drawable);
        temp->SetText(convert_int_to_string(step--));
    }

    void UpdatePhaseStep(int phase) {
        if (phase >= 9) {
            phase--;
            step = s_PhaseTasks[phase];
            m_Phase = phase;
        }
        else {
            step = s_PhaseTasks[phase];
            m_Phase = phase;
        }

        if (phase == 10 || phase == 12 || phase == 14 || phase == 15) {
            SetVisible(false);
        }
        else if (phase == 9) {
            SetVisible(true);
            SetPosition({40, 215});
        }
        else if (phase == 11) {
            SetVisible(true);
            SetPosition({10, 225});
        }
        else if (phase == 13) {
            SetVisible(true);
            SetPosition({40, 230});
        }
        else {
            SetVisible(true);
            SetPosition({-530.0F, -215.F});
        }
    }

    [[nodiscard]] bool IsStepZero() const{
        return step <= -2;
    }

    int GetPhase() {
        return  m_Phase;
    }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

private:
    inline static std::string convert_int_to_string(int step) {
        if (step == 0) {
            return "X";
        }
        return std::to_string(step);
    }

    static constexpr int s_PhaseTasks[16] = {
            23,
            24,
            32,
            23,
            23,
            43,
            32,
            12,
            33,
            21,
            0,
            35,
            0,
            49,
            0,
            0,
    };

    int step = s_PhaseTasks[0];
    int m_Phase;
};

#endif //STEPTEXT_HPP

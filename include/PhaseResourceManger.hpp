//
// Created by 翁廷豪 on 2024/3/6.
//

#ifndef PHASE_MANGER_HPP
#define PHASE_MANGER_HPP

#include "Util/GameObject.hpp"
#include "TaskText.hpp"
#include "Character.hpp"
#include "BackgroundImage.hpp"
#include "StepText.hpp"

class PhaseResourceManger {
public:
    PhaseResourceManger();

    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildren() const {
        return {m_TaskText, m_Background};
    }

    void NextPhase();

    void SwitchTo8_2() {
        if (m_Background->GetImagePath() == RESOURCE_DIR"/Image/Background/Map/map7.png") {
            m_Background->SetImage(RESOURCE_DIR"/Image/Background/Map/map7_2.png");
        }
    }

    void SwitchTo8() {
        if (m_Background->GetImagePath() == RESOURCE_DIR"/Image/Background/Map/map7_2.png") {
            m_Background->SetImage(RESOURCE_DIR"/Image/Background/Map/map7.png");
        }
    }

    void SetPhase(int i) {
        m_Phase = i;
    }

private:
    std::shared_ptr<TaskText> m_TaskText;
    std::shared_ptr<BackgroundImage> m_Background;

    int m_Phase = 1;
};


#endif //PHASE_MANGER_HPP

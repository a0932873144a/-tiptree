//
// Created by 翁廷豪 on 2024/3/6.
//

#include "AppUtil.hpp"
#include "App.hpp"

/**
 * @brief The function to validate the tasks.
 * @warning modify this function.
 * @note See README.md for the task details.
 */
 //TODO(to RAY): complete the deploy of objects in each phase
 //TODO: complete the IsPass function
void App::ValidTask() {
    LOG_DEBUG("Validating the task {}", static_cast<int>(m_Phase));
    switch (m_Phase) {
        case Phase::Phase1:
            //player
            m_Player->SetPosition({-150, 100});
            m_Player->SetVisible(true);

            //boss1
            m_Boss1->SetPosition({400.0f, 50.0f});
            m_Boss1->SetVisible(true);

            //rock
            m_Rock->SetPosition({100, -100});
            m_Rock->SetVisible(true);

            //enemy
            m_Enemy->SetPosition({0, -100});
            m_Enemy->SetVisible(true);

            //boundaries
            m_BoundaryL->SetPosition({-280, -300});
            m_BoundaryL->SetVisible(false);
            m_BoundaryR->SetPosition({300, -300});
            m_BoundaryR->SetVisible(false);
            m_BoundaryT->SetPosition({-200, 300});
            m_BoundaryT->SetVisible(false);
            m_BoundaryB->SetPosition({-200, -250});
            m_BoundaryB->SetVisible(false);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            if (m_Player->GetImagePath() == RESOURCE_DIR"/Image/Character/rock.png") {
                m_Phase = Phase::Phase2;
                m_Player->SetPosition({-112.5f, -140.5f});

                m_PRM->NextPhase();
            } else {
                LOG_DEBUG("You do not pass yet");
            }
            break;


        case Phase::Phase2:
            if (isInsideTheSquare(*m_Player)) {
                LOG_DEBUG("Congratulations!");
                m_CurrentState = State::END;
            } else {
                LOG_DEBUG("You do not pass yet");
            }
            break;
    }
}

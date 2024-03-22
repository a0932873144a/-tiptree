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
//            m_BoundaryL->SetPosition({-280, -300});
//            m_BoundaryL->SetVisible(false);
//            m_BoundaryR->SetPosition({300, -300});
//            m_BoundaryR->SetVisible(false);
//            m_BoundaryT->SetPosition({-200, 300});
//            m_BoundaryT->SetVisible(false);
//            m_BoundaryB->SetPosition({-200, -250});
//            m_BoundaryB->SetVisible(false);

            //boundaries_precise
            m_BoundaryT1->SetPosition({140, 245});
            m_BoundaryT1->SetVisible(false);
            m_BoundaryT2->SetPosition({70, 245});
            m_BoundaryT2->SetVisible(false);
            m_BoundaryT3->SetPosition({-5, 180});
            m_BoundaryT3->SetVisible(false);
            m_BoundaryT4->SetPosition({-75, 180});
            m_BoundaryT4->SetVisible(false);
            m_BoundaryT5->SetPosition({-145, 180});
            m_BoundaryT5->SetVisible(false);

            m_BoundaryL1->SetPosition({-210, 110});
            m_BoundaryL1->SetVisible(false);
            m_BoundaryL2->SetPosition({-210, 35});
            m_BoundaryL2->SetVisible(false);
            m_BoundaryL3->SetPosition({-285, -35});
            m_BoundaryL3->SetVisible(false);
            m_BoundaryL4->SetPosition({-285, -105});
            m_BoundaryL4->SetVisible(false);
            m_BoundaryL5->SetPosition({-285, -180});
            m_BoundaryL5->SetVisible(false);

            m_BoundaryR1->SetPosition({210, 180});
            m_BoundaryR1->SetVisible(false);
            m_BoundaryR2->SetPosition({210, 110});
            m_BoundaryR2->SetVisible(false);
            m_BoundaryR3->SetPosition({140, 35});
            m_BoundaryR3->SetVisible(false);
            m_BoundaryR4->SetPosition({210, -35});
            m_BoundaryR4->SetVisible(false);
            m_BoundaryR5->SetPosition({280, -105});
            m_BoundaryR5->SetVisible(false);
            m_BoundaryR6->SetPosition({280, -180});
            m_BoundaryR6->SetVisible(false);

            m_BoundaryIB1->SetPosition({140, -40});
            m_BoundaryIB1->SetVisible(true);
            m_BoundaryIB2->SetPosition({70, -40});
            m_BoundaryIB2->SetVisible(true);
            m_BoundaryIB3->SetPosition({-5, -40});
            m_BoundaryIB3->SetVisible(true);
            m_BoundaryIB4->SetPosition({-75, -40});
            m_BoundaryIB4->SetVisible(true);



            m_BoundaryB1->SetPosition({210, -240});
            m_BoundaryB1->SetVisible(false);
            m_BoundaryB2->SetPosition({140, -240});
            m_BoundaryB2->SetVisible(false);
            m_BoundaryB3->SetPosition({70, -240});
            m_BoundaryB3->SetVisible(false);
            m_BoundaryB4->SetPosition({-5, -240});
            m_BoundaryB4->SetVisible(false);
            m_BoundaryB5->SetPosition({-75, -240});
            m_BoundaryB5->SetVisible(false);
            m_BoundaryB6->SetPosition({-145, -240});
            m_BoundaryB6->SetVisible(false);
            m_BoundaryB7->SetPosition({-210, -240});
            m_BoundaryB7->SetVisible(false);


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

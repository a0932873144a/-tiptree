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
        //Phase1
        case Phase::Phase1:
            //player
            m_Player->SetPosition({138, 180});
            m_Player->SetVisible(true);

            //boss1
            m_Boss1->SetPosition({210, -160});
            m_Boss1->SetVisible(true);

            //rocks
            m_Rocks[0]->SetPosition({72, -105});
            m_Rocks[0]->SetVisible(true);
            m_Rocks[1]->SetPosition({-5, -180});
            m_Rocks[1]->SetVisible(true);
            m_Rocks[2]->SetPosition({-145, -105});
            m_Rocks[2]->SetVisible(true);
            m_Rocks[3]->SetPosition({-145, -180});
            m_Rocks[3]->SetVisible(true);

            //enemies
            m_Enemies[0]->SetPosition({72, 35});
            m_Enemies[0]->SetVisible(true);
            m_Enemies[1]->SetPosition({-5, 110});
            m_Enemies[1]->SetVisible(true);
            m_Enemies[2]->SetPosition({-75, 35});
            m_Enemies[2]->SetVisible(true);

            //boundaries_precise
            m_BoundaryTs[0]->SetPosition({140, 245});
            m_BoundaryTs[1]->SetPosition({70, 245});
            m_BoundaryTs[2]->SetPosition({-5, 180});
            m_BoundaryTs[3]->SetPosition({-75, 180});
            m_BoundaryTs[4]->SetPosition({-145, 180});

            m_BoundaryLs[0]->SetPosition({-210, 110});
            m_BoundaryLs[1]->SetPosition({-210, 35});
            m_BoundaryLs[2]->SetPosition({-285, -35});
            m_BoundaryLs[3]->SetPosition({-285, -105});
            m_BoundaryLs[4]->SetPosition({-285, -180});

            m_BoundaryRs[0]->SetPosition({210, 180});
            m_BoundaryRs[1]->SetPosition({210, 110});
            m_BoundaryRs[2]->SetPosition({140, 35});
            m_BoundaryRs[3]->SetPosition({210, -105});
            m_BoundaryRs[4]->SetPosition({280, -105});
            m_BoundaryRs[5]->SetPosition({280, -180});

            m_BoundaryIBs[0]->SetPosition({142, -38});
            m_BoundaryIBs[1]->SetPosition({72, -38});
            m_BoundaryIBs[2]->SetPosition({-2, -38});
            m_BoundaryIBs[3]->SetPosition({-73, -38});

            m_BoundaryBs[0]->SetPosition({210, -240});
            m_BoundaryBs[1]->SetPosition({140, -240});
            m_BoundaryBs[2]->SetPosition({70, -240});
            m_BoundaryBs[3]->SetPosition({-5, -240});
            m_BoundaryBs[4]->SetPosition({-75, -240});
            m_BoundaryBs[5]->SetPosition({-145, -240});
            m_BoundaryBs[6]->SetPosition({-210, -240});

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            break;

        //Phase2
        case Phase::Phase2:
            //player
            m_Player->SetPosition({-100, -100});
            m_Player->SetVisible(true);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            break;

        //Phase3
        case Phase::Phase3:

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            break;

        //Phase4
        case Phase::Phase4:
            break;

        //Phase5
        case Phase::Phase5:
            break;

        //Phase6
        case Phase::Phase6:
            break;

        //Phase7
        case Phase::Phase7:
            break;

        //Phase8
        case Phase::Phase8:
            break;

        //Phase9
        case Phase::Phase9:
            break;

        //Phase10
        case Phase::Phase10:
            break;

        default:
            break;

    }
}

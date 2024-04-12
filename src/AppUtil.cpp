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
            m_Player->SetPosition({-210, -110});
            m_Player->SetVisible(true);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            //boss1
            m_Boss1->SetPosition({80, -180});
            m_Boss1->SetVisible(true);

            //enemies
            m_Enemies[0]->SetPosition({-145, 105});
            m_Enemies[0]->SetVisible(true);
            m_Enemies[1]->SetPosition({150, -105});
            m_Enemies[1]->SetVisible(true);
            m_Enemies[2]->SetPosition({220, -180});
            m_Enemies[2]->SetVisible(true);

            //boundaries_precise
            m_BoundaryTs[0]->SetPosition({220, 180});
            m_BoundaryTs[1]->SetPosition({150, 180});
            m_BoundaryTs[2]->SetPosition({80, 240});
            m_BoundaryTs[3]->SetPosition({5, 240});
            m_BoundaryTs[4]->SetPosition({-70, 240});
            m_BoundaryTs[5]->SetPosition({-145, 240});

            m_BoundaryLs[0]->SetPosition({-210, 180});
            m_BoundaryLs[1]->SetPosition({-210, 105});
            m_BoundaryLs[2]->SetPosition({-285, 30});
            m_BoundaryLs[3]->SetPosition({-285, -30});
            m_BoundaryLs[4]->SetPosition({-285, -110});

            m_BoundaryRs[0]->SetPosition({290, 105});
            m_BoundaryRs[1]->SetPosition({290, 30});
            m_BoundaryRs[2]->SetPosition({290, -30});
            m_BoundaryRs[3]->SetPosition({290, -105});
            m_BoundaryRs[4]->SetPosition({290, -180});

            m_BoundaryIBs[0]->SetPosition({5, 30});
            m_BoundaryIBs[1]->SetPosition({5, -30});
            m_BoundaryIBs[2]->SetPosition({5, -105});
            m_BoundaryIBs[3]->SetPosition({5, -180});
            m_BoundaryIBs[4]->SetPosition({-70, 105});
            m_BoundaryIBs[5]->SetPosition({-70, 30});
            m_BoundaryIBs[6]->SetPosition({-70, -30});
            m_BoundaryIBs[7]->SetPosition({-70, -105});

            m_BoundaryBs[0]->SetPosition({220, -240});
            m_BoundaryBs[1]->SetPosition({150, -240});
            m_BoundaryBs[2]->SetPosition({80, -240});
            m_BoundaryBs[3]->SetPosition({-145, -180});
            m_BoundaryBs[4]->SetPosition({-210, -180});

            //rocks
            m_Rocks[0]->SetPosition({80, 30});
            m_Rocks[0]->SetVisible(true);
            m_Rocks[1]->SetPosition({150, 30});
            m_Rocks[1]->SetVisible(true);
            m_Rocks[2]->SetPosition({220, 30});
            m_Rocks[2]->SetVisible(true);


            break;

        //Phase3
        case Phase::Phase3:

            //player
            m_Player->SetPosition({250, 70});
            m_Player->SetVisible(true);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            //boss1
            m_Boss1->SetPosition({105, 220});
            m_Boss1->SetVisible(true);

            //enemies
            m_Enemies[0]->SetPosition({105, -210});
            m_Enemies[0]->SetVisible(true);
            m_Enemies[1]->SetPosition({30, -70});
            m_Enemies[1]->SetVisible(true);

            //boundaries_precise
            m_BoundaryTs[0]->SetPosition({180, 280});
            m_BoundaryTs[1]->SetPosition({105, 280});
            m_BoundaryTs[2]->SetPosition({30, 280});
            m_BoundaryTs[3]->SetPosition({-40, 280});
            m_BoundaryTs[4]->SetVisible(true);            //等你改喔寶

            m_BoundaryLs[0]->SetPosition({-110, 210});
            m_BoundaryLs[1]->SetPosition({-110, 150});
            m_BoundaryLs[2]->SetPosition({-180, 70});
            m_BoundaryLs[3]->SetPosition({-180, 0});
            m_BoundaryLs[4]->SetPosition({-180, -70});
            m_BoundaryLs[5]->SetPosition({-250, -70});
            m_BoundaryLs[6]->SetPosition({-310, -140});
            m_BoundaryLs[7]->SetPosition({-310, -210});

            m_BoundaryRs[0]->SetPosition({250, 210});
            m_BoundaryRs[1]->SetPosition({250, 150});
            m_BoundaryRs[2]->SetPosition({320, 70});
            m_BoundaryRs[3]->SetPosition({320, 0});
            m_BoundaryRs[4]->SetPosition({320, -70});
            m_BoundaryRs[5]->SetPosition({250, -140});
            m_BoundaryRs[6]->SetPosition({250, -210});

            m_BoundaryIBs[0]->SetPosition({105, 150});
            m_BoundaryIBs[1]->SetPosition({105, 0});
            m_BoundaryIBs[2]->SetPosition({105, -140});
            m_BoundaryIBs[3]->SetPosition({30, 150});
            m_BoundaryIBs[4]->SetPosition({-40, 150});
            m_BoundaryIBs[5]->SetPosition({-40, 0});
            m_BoundaryIBs[6]->SetPosition({-40, -140});
            m_BoundaryIBs[7]->SetPosition({-180, -140});

            m_BoundaryBs[0]->SetPosition({180, -280});
            m_BoundaryBs[1]->SetPosition({105, -280});
            m_BoundaryBs[2]->SetPosition({30, -280});
            m_BoundaryBs[3]->SetPosition({-40, -280});
            m_BoundaryBs[4]->SetPosition({-110, -280});
            m_BoundaryBs[5]->SetPosition({-180, -280});
            m_BoundaryBs[6]->SetPosition({-250, -280});



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

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
void App::ValidTask() {
    LOG_DEBUG("Validating the task {}", static_cast<int>(m_Phase));
    switch (m_Phase) {
        //Phase1
        case Phase::Phase1:
            Origin();

            //player
            m_Player->SetPosition({138, 180});
            m_Player->SetVisible(true);

            //boss
            m_Boss->SetImage(RESOURCE_DIR"/Image/Character/boss/boss1.png");
            m_Boss->SetPosition({210, -160});
            m_Boss->SetVisible(true);

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
            Origin();

            //player
            m_Player->SetPosition({-210, -110});
            m_Player->SetVisible(true);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            //boss
            m_Boss->SetImage(RESOURCE_DIR"/Image/Character/boss/boss2.png");
            m_Boss->SetPosition({80, -180});
            m_Boss->SetVisible(true);

            //enemies
            m_Enemies[0]->SetPosition({-145, 105});
            m_Enemies[0]->SetVisible(true);
            m_Enemies[1]->SetPosition({145, -105});
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

            //spikeTraps
            m_SpikeTraps[0]->SetPosition({145, -30});
            m_SpikeTraps[0]->SetVisible(true);
            m_SpikeTraps[1]->SetPosition({75, 100});
            m_SpikeTraps[1]->SetVisible(true);
            m_SpikeTraps[2]->SetPosition({0, 100});
            m_SpikeTraps[2]->SetVisible(true);
            m_SpikeTraps[3]->SetPosition({-145, 30});
            m_SpikeTraps[3]->SetVisible(true);

            break;

            //Phase3
        case Phase::Phase3:
            Origin();

            //player
            m_Player->SetPosition({250, 70});
            m_Player->SetVisible(true);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            //bosses
            m_Bosses[0]->SetImage(RESOURCE_DIR"/Image/Character/boss/boss3a.png");
            m_Bosses[0]->SetPosition({105, 220});
            m_Bosses[0]->SetVisible(true);
            m_Bosses[1]->SetImage(RESOURCE_DIR"/Image/Character/boss/boss3b.png");
            m_Bosses[1]->SetPosition({35, 220});
            m_Bosses[1]->SetVisible(true);
            m_Bosses[2]->SetImage(RESOURCE_DIR"/Image/Character/boss/boss3c.png");
            m_Bosses[2]->SetPosition({-45, 220});
            m_Bosses[2]->SetVisible(true);

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
            m_BoundaryRs[4]->SetPosition({250, -70});
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

            //spikeTraps
            m_SpikeTraps[0]->SetPosition({180, -70});
            m_SpikeTraps[0]->SetVisible(true);
            m_SpikeTraps[1]->SetPosition({105, -70});
            m_SpikeTraps[1]->SetVisible(true);
            m_SpikeTraps[2]->SetPosition({30, 70});
            m_SpikeTraps[2]->SetVisible(true);
            m_SpikeTraps[3]->SetPosition({30, 0});
            m_SpikeTraps[3]->SetVisible(true);
            m_SpikeTraps[4]->SetPosition({30, -140});
            m_SpikeTraps[4]->SetVisible(true);
            m_SpikeTraps[5]->SetPosition({-40, 70});
            m_SpikeTraps[5]->SetVisible(true);
            m_SpikeTraps[6]->SetPosition({-110, 0});
            m_SpikeTraps[6]->SetVisible(true);
            m_SpikeTraps[7]->SetPosition({-110, -140});
            m_SpikeTraps[7]->SetVisible(true);

            m_Key->SetPosition({-250, -140});
            m_Key->SetVisible(true);

            m_TreasureBox->SetPosition({180, 150});
            m_TreasureBox->SetVisible(true);

            break;

            //Phase4
        case Phase::Phase4:
            Origin();

            //player
            m_Player->SetPosition({-248, 148});
            m_Player->SetVisible(true);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            //boss
            m_Boss->SetImage(RESOURCE_DIR"/Image/Character/boss/boss4.png");
            m_Boss->SetPosition({255, 0});
            m_Boss->SetVisible(true);

            //boundaries_precise
            m_BoundaryTs[0]->SetPosition({255, 70});
            m_BoundaryTs[1]->SetPosition({180, 140});
            m_BoundaryTs[2]->SetPosition({110, 140});
            m_BoundaryTs[3]->SetPosition({40, 210});
            m_BoundaryTs[4]->SetPosition({-40, 210});
            m_BoundaryTs[5]->SetPosition({-110, 210});
            m_BoundaryTs[6]->SetPosition({-175, 140});
            m_BoundaryTs[7]->SetPosition({-250, 210});

            m_BoundaryLs[0]->SetPosition({-310, 150});
            m_BoundaryLs[1]->SetPosition({-310, 80});
            m_BoundaryLs[2]->SetPosition({-310, 0});
            m_BoundaryLs[3]->SetPosition({-310, -70});

            m_BoundaryRs[0]->SetPosition({320, 0});
            m_BoundaryRs[1]->SetPosition({320, -70});

            m_BoundaryBs[0]->SetPosition({255, -140});
            m_BoundaryBs[1]->SetPosition({180, -140});
            m_BoundaryBs[2]->SetPosition({110, -210});
            m_BoundaryBs[3]->SetPosition({40, -210});
            m_BoundaryBs[4]->SetPosition({-40, -210});
            m_BoundaryBs[5]->SetPosition({-110, -210});
            m_BoundaryBs[6]->SetPosition({-175, -210});
            m_BoundaryBs[7]->SetPosition({-250, -140});

            //rocks
            m_Rocks[0]->SetPosition({180, -70});
            m_Rocks[0]->SetVisible(true);
            m_Rocks[1]->SetPosition({110, 0});
            m_Rocks[1]->SetVisible(true);
            m_Rocks[2]->SetPosition({110, -70});
            m_Rocks[2]->SetVisible(true);
            m_Rocks[3]->SetPosition({40, 150});
            m_Rocks[3]->SetVisible(true);
            m_Rocks[4]->SetPosition({40, 0});
            m_Rocks[4]->SetVisible(true);
            m_Rocks[5]->SetPosition({40, -140});
            m_Rocks[5]->SetVisible(true);
            m_Rocks[6]->SetPosition({-40, 80});
            m_Rocks[6]->SetVisible(true);
            m_Rocks[7]->SetPosition({-40, -70});
            m_Rocks[7]->SetVisible(true);
            m_Rocks[8]->SetPosition({-110, 0});
            m_Rocks[8]->SetVisible(true);
            m_Rocks[9]->SetPosition({-110, -140});
            m_Rocks[9]->SetVisible(true);
            m_Rocks[10]->SetPosition({-175, 80});
            m_Rocks[10]->SetVisible(true);
            m_Rocks[11]->SetPosition({-175, -70});
            m_Rocks[11]->SetVisible(true);
            m_Rocks[12]->SetPosition({-250, 0});
            m_Rocks[12]->SetVisible(true);

            m_Key->SetPosition({-110, 150});
            m_Key->SetVisible(true);

            m_TreasureBox->SetPosition({110, 80});
            m_TreasureBox->SetVisible(true);

            //spikeTraps
            m_SpikeTraps[0]->SetPosition({-40, 80});
            m_SpikeTraps[0]->SetVisible(true);
            m_SpikeTraps[1]->SetPosition({-110, 80});
            m_SpikeTraps[1]->SetVisible(true);

            break;

            //Phase5
        case Phase::Phase5:
            Origin();

            //player
            m_Player->SetPosition({-180, 70});
            m_Player->SetVisible(true);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            //boss
            m_Boss->SetImage(RESOURCE_DIR"/Image/Character/boss/boss5.png");
            m_Boss->SetPosition({105, 210});
            m_Boss->SetVisible(true);

            //boundaries_precise
            m_BoundaryTs[0]->SetPosition({180, 210});
            m_BoundaryTs[1]->SetPosition({105, 280});
            m_BoundaryTs[2]->SetPosition({30, 280});
            m_BoundaryTs[3]->SetPosition({-40, 210});
            m_BoundaryTs[4]->SetPosition({-110, 130});
            m_BoundaryTs[5]->SetPosition({-180, 130});

            m_BoundaryLs[0]->SetPosition({-250, 70});
            m_BoundaryLs[1]->SetPosition({-250, 0});
            m_BoundaryLs[2]->SetPosition({-250, -70});
            m_BoundaryLs[3]->SetPosition({-250, -140});

            m_BoundaryRs[0]->SetPosition({250, 130});
            m_BoundaryRs[1]->SetPosition({250, 70});
            m_BoundaryRs[2]->SetPosition({250, 0});
            m_BoundaryRs[3]->SetPosition({250, -70});
            m_BoundaryRs[4]->SetPosition({250, -140});
            m_BoundaryRs[5]->SetPosition({250, -210});

            m_BoundaryBs[0]->SetPosition({180, -280});
            m_BoundaryBs[1]->SetPosition({105, -210});
            m_BoundaryBs[2]->SetPosition({30, -210});
            m_BoundaryBs[3]->SetPosition({-40, -210});
            m_BoundaryBs[4]->SetPosition({-110, -210});
            m_BoundaryBs[5]->SetPosition({-180, -210});

            m_BoundaryIBs[0]->SetPosition({-110, 70});
            m_BoundaryIBs[1]->SetPosition({-110, 0});
            m_BoundaryIBs[2]->SetPosition({-110, -70});

            //rocks
            m_Rocks[0]->SetPosition({180, -70});
            m_Rocks[0]->SetVisible(true);
            m_Rocks[1]->SetPosition({105, 130});
            m_Rocks[1]->SetVisible(true);
            m_Rocks[2]->SetPosition({105, 70});
            m_Rocks[2]->SetVisible(true);
            m_Rocks[3]->SetPosition({105, -70});
            m_Rocks[3]->SetVisible(true);
            m_Rocks[4]->SetPosition({30, -70});
            m_Rocks[4]->SetVisible(true);
            m_Rocks[5]->SetPosition({-40, -70});
            m_Rocks[5]->SetVisible(true);

            m_Key->SetPosition({180, -210});
            m_Key->SetVisible(true);

            m_TreasureBox->SetPosition({30, 130});
            m_TreasureBox->SetVisible(true);

            //spikeTraps
            m_SpikeTraps[0]->SetPosition({180, 0});
            m_SpikeTraps[1]->SetPosition({180, -140});
            m_SpikeTraps[2]->SetPosition({30, 0});
            m_SpikeTraps[3]->SetPosition({-40, 70});
            m_SpikeTraps[4]->SetPosition({-40, -140});
            m_SpikeTraps[5]->SetPosition({-180, -140});

            //hiddenspikeTraps
            m_HiddenSpikeTraps[0]->SetPosition({180, 0});
            m_HiddenSpikeTraps[0]->SetVisible(true);
            m_HiddenSpikeTraps[1]->SetPosition({180, -140});
            m_HiddenSpikeTraps[1]->SetVisible(true);
            m_HiddenSpikeTraps[2]->SetPosition({30, 0});
            m_HiddenSpikeTraps[2]->SetVisible(true);
            m_HiddenSpikeTraps[3]->SetPosition({-40, 70});
            m_HiddenSpikeTraps[3]->SetVisible(true);
            m_HiddenSpikeTraps[4]->SetPosition({-40, -140});
            m_HiddenSpikeTraps[4]->SetVisible(true);
            m_HiddenSpikeTraps[5]->SetPosition({-180, -140});
            m_HiddenSpikeTraps[5]->SetVisible(true);



            //enemies
            m_Enemies[0]->SetPosition({-180, -70});
            m_Enemies[0]->SetVisible(true);


            break;

            //Phase6
        case Phase::Phase6:
            Origin();

            //player
            m_Player->SetPosition({-70, 250});
            m_Player->SetVisible(true);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            //boss
            m_Boss->SetImage(RESOURCE_DIR"/Image/Character/boss/boss5.png");
            m_Boss->SetPosition({140, -240});
            m_Boss->SetVisible(true);

            //boundaries_precise
            m_BoundaryTs[0]->SetPosition({220, 40});
            m_BoundaryTs[1]->SetPosition({140, 40});
            m_BoundaryTs[2]->SetPosition({65, 120});
            m_BoundaryTs[3]->SetPosition({0, 320});
            m_BoundaryTs[4]->SetPosition({-70, 320});
            m_BoundaryTs[5]->SetPosition({-150, 320});
//            m_BoundaryTs[0]->SetVisible(true);
//            m_BoundaryTs[1]->SetVisible(true);
//            m_BoundaryTs[2]->SetVisible(true);
//            m_BoundaryTs[3]->SetVisible(true);
//            m_BoundaryTs[4]->SetVisible(true);
//            m_BoundaryTs[5]->SetVisible(true);

            m_BoundaryRs[0]->SetPosition({65, 250});
            m_BoundaryRs[1]->SetPosition({65, 180});
            m_BoundaryRs[2]->SetPosition({280, -30});
            m_BoundaryRs[3]->SetPosition({280, -110});
            m_BoundaryRs[4]->SetPosition({280, -170});
//            m_BoundaryRs[0]->SetVisible(true);
//            m_BoundaryRs[1]->SetVisible(true);
//            m_BoundaryRs[2]->SetVisible(true);
//            m_BoundaryRs[3]->SetVisible(true);
//            m_BoundaryRs[4]->SetVisible(true);

            m_BoundaryBs[0]->SetPosition({220, -240});
            m_BoundaryBs[1]->SetPosition({140, -310});
            m_BoundaryBs[2]->SetPosition({65, -310});
            m_BoundaryBs[3]->SetPosition({0, -240});
            m_BoundaryBs[4]->SetPosition({0, -170});
            m_BoundaryBs[5]->SetPosition({-70, -170});
            m_BoundaryBs[6]->SetPosition({-150, -170});
//            m_BoundaryBs[0]->SetVisible(true);
//            m_BoundaryBs[1]->SetVisible(true);
//            m_BoundaryBs[2]->SetVisible(true);
//            m_BoundaryBs[3]->SetVisible(true);
//            m_BoundaryBs[4]->SetVisible(true);
//            m_BoundaryBs[3]->SetVisible(true);
//            m_BoundaryBs[4]->SetVisible(true);

            m_BoundaryLs[0]->SetPosition({-220, 250});
            m_BoundaryLs[1]->SetPosition({-220, 180});
            m_BoundaryLs[2]->SetPosition({-290, 120});
            m_BoundaryLs[3]->SetPosition({-220, 40});
            m_BoundaryLs[4]->SetPosition({-220, -30});
            m_BoundaryLs[5]->SetPosition({-220, -110});
//            m_BoundaryLs[0]->SetVisible(true);
//            m_BoundaryLs[1]->SetVisible(true);
//            m_BoundaryLs[2]->SetVisible(true);
//            m_BoundaryLs[3]->SetVisible(true);
//            m_BoundaryLs[4]->SetVisible(true);
//            m_BoundaryLs[5]->SetVisible(true);

            m_BoundaryIBs[0]->SetPosition({220, -110});
            m_BoundaryIBs[1]->SetPosition({-70, -30});

            //rocks
            m_Rocks[0]->SetPosition({140, -170});
            m_Rocks[0]->SetVisible(true);
            m_Rocks[1]->SetPosition({65, -30});
            m_Rocks[1]->SetVisible(true);
            m_Rocks[2]->SetPosition({0, 180});
            m_Rocks[2]->SetVisible(true);
            m_Rocks[3]->SetPosition({0, -30});
            m_Rocks[3]->SetVisible(true);
            m_Rocks[4]->SetPosition({0, -110});
            m_Rocks[4]->SetVisible(true);
            m_Rocks[5]->SetPosition({-70, 180});
            m_Rocks[5]->SetVisible(true);
            m_Rocks[6]->SetPosition({-70, 40});
            m_Rocks[6]->SetVisible(true);
            m_Rocks[7]->SetPosition({-150, 180});
            m_Rocks[7]->SetVisible(true);

            m_Key->SetPosition({0, 120});
            m_Key->SetVisible(true);

            m_TreasureBox->SetPosition({60, -170});
            m_TreasureBox->SetVisible(true);

            //spikeTraps
            m_SpikeTraps[0]->SetPosition({-70, 40});
            m_SpikeTraps[1]->SetPosition({-150, 40});

            //hiddenspikeTraps
            m_HiddenSpikeTraps[0]->SetPosition({-70, 40});
            m_HiddenSpikeTraps[0]->SetVisible(true);
            m_HiddenSpikeTraps[1]->SetPosition({-150, 40});
            m_HiddenSpikeTraps[1]->SetVisible(true);

            //enemies
            m_Enemies[0]->SetPosition({140, -100});
            m_Enemies[0]->SetVisible(true);
            m_Enemies[1]->SetPosition({-150, -30});
            m_Enemies[1]->SetVisible(true);

            break;

            //Phase7
        case Phase::Phase7:
            Origin();

            //player
            m_Player->SetPosition({173, -70});
            m_Player->SetVisible(true);
            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            //boss
            m_Boss->SetImage(RESOURCE_DIR"/Image/Character/boss/boss5.png");
            m_Boss->SetPosition({30, 210});
            m_Boss->SetVisible(true);

            //boundaries_precise
            m_BoundaryTs[0]->SetPosition({180, 210});
            m_BoundaryTs[1]->SetPosition({105, 280});
            m_BoundaryTs[2]->SetPosition({30, 280});
            m_BoundaryTs[3]->SetPosition({-40, 210});
            m_BoundaryTs[4]->SetPosition({-40, 150});
            m_BoundaryTs[5]->SetPosition({-40, 70});
            m_BoundaryTs[6]->SetPosition({-110, 150});
            m_BoundaryTs[7]->SetPosition({-180, 150});
//            m_BoundaryTs[0]->SetVisible(true);
//            m_BoundaryTs[1]->SetVisible(true);
//            m_BoundaryTs[2]->SetVisible(true);
//            m_BoundaryTs[3]->SetVisible(true);
//            m_BoundaryTs[4]->SetVisible(true);
//            m_BoundaryTs[5]->SetVisible(true);
//            m_BoundaryTs[6]->SetVisible(true);
//            m_BoundaryTs[7]->SetVisible(true);

            m_BoundaryRs[0]->SetPosition({250, 150});
            m_BoundaryRs[1]->SetPosition({250, 70});
            m_BoundaryRs[2]->SetPosition({250, 0});
            m_BoundaryRs[3]->SetPosition({250, -70});
            m_BoundaryRs[4]->SetPosition({180, -140});
            m_BoundaryRs[5]->SetPosition({105, -140});
            m_BoundaryRs[6]->SetPosition({105, -210});
//            m_BoundaryRs[0]->SetVisible(true);
//            m_BoundaryRs[1]->SetVisible(true);
//            m_BoundaryRs[2]->SetVisible(true);
//            m_BoundaryRs[3]->SetVisible(true);
//            m_BoundaryRs[4]->SetVisible(true);
//            m_BoundaryRs[5]->SetVisible(true);
//            m_BoundaryRs[6]->SetVisible(true);

            m_BoundaryBs[0]->SetPosition({30, -280});
            m_BoundaryBs[1]->SetPosition({-40, -280});
            m_BoundaryBs[2]->SetPosition({-110, -280});
            m_BoundaryBs[3]->SetPosition({-180, -280});
//            m_BoundaryBs[0]->SetVisible(true);
//            m_BoundaryBs[1]->SetVisible(true);
//            m_BoundaryBs[2]->SetVisible(true);
//            m_BoundaryBs[3]->SetVisible(true);


            m_BoundaryLs[0]->SetPosition({-250, 70});
            m_BoundaryLs[1]->SetPosition({-250, 0});
            m_BoundaryLs[2]->SetPosition({-250, -70});
            m_BoundaryLs[3]->SetPosition({-250, -140});
            m_BoundaryLs[4]->SetPosition({-250, -210});
//            m_BoundaryLs[0]->SetVisible(true);
//            m_BoundaryLs[1]->SetVisible(true);
//            m_BoundaryLs[2]->SetVisible(true);
//            m_BoundaryLs[3]->SetVisible(true);
//            m_BoundaryLs[4]->SetVisible(true);

            m_BoundaryIBs[0]->SetPosition({-40, -140});
            m_BoundaryIBs[1]->SetPosition({-110, -70});
            m_BoundaryIBs[2]->SetPosition({-110, -140});

            //rocks
            m_Rocks[0]->SetPosition({180, 70});
            m_Rocks[0]->SetVisible(true);
            m_Rocks[1]->SetPosition({105, 70});
            m_Rocks[1]->SetVisible(true);
            m_Rocks[2]->SetPosition({105, 0});
            m_Rocks[2]->SetVisible(true);
            m_Rocks[3]->SetPosition({30, 70});
            m_Rocks[3]->SetVisible(true);
            m_Rocks[4]->SetPosition({-110, 0});
            m_Rocks[4]->SetVisible(true);


            m_Key->SetPosition({-110, 70});
            m_Key->SetVisible(true);

            m_TreasureBox->SetPosition({100, 150});
            m_TreasureBox->SetVisible(true);

            //spikeTraps
            m_SpikeTraps[0]->SetPosition({30, -140});
            m_SpikeTraps[1]->SetPosition({30, -210});
            m_SpikeTraps[1]->SetVisible(true);
            m_SpikeTraps[2]->SetPosition({-40, -210});
            m_SpikeTraps[3]->SetPosition({-110, -210});
            m_SpikeTraps[3]->SetVisible(true);
            m_SpikeTraps[4]->SetPosition({-180, -140});
            m_SpikeTraps[4]->SetVisible(true);
            m_SpikeTraps[5]->SetPosition({-180, -210});

            //hiddenspikeTraps
            m_HiddenSpikeTraps[0]->SetPosition({30, -140});
            m_HiddenSpikeTraps[0]->SetVisible(true);
            m_HiddenSpikeTraps[1]->SetPosition({30, -210});
            m_HiddenSpikeTraps[1]->SetVisible(true);
            m_HiddenSpikeTraps[2]->SetPosition({-40, -210});
            m_HiddenSpikeTraps[2]->SetVisible(true);
            m_HiddenSpikeTraps[3]->SetPosition({-110, -210});
            m_HiddenSpikeTraps[3]->SetVisible(true);
            m_HiddenSpikeTraps[4]->SetPosition({-180, -140});
            m_HiddenSpikeTraps[4]->SetVisible(true);
            m_HiddenSpikeTraps[5]->SetPosition({-180, -210});
            m_HiddenSpikeTraps[5]->SetVisible(true);

            //enemies
            m_Enemies[0]->SetPosition({30, 0});
            m_Enemies[0]->SetVisible(true);
            m_Enemies[1]->SetPosition({-40, -70});
            m_Enemies[1]->SetVisible(true);
            m_Enemies[2]->SetPosition({-180, 0});
            m_Enemies[2]->SetVisible(true);

            break;

            //Phase8
        case Phase::Phase8:
            Origin();

            //player
            m_Player->SetPosition({0, -200});
            m_Player->SetVisible(true);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            //boundaries_precise
            m_BoundaryIBs[0]->SetPosition({140, 290});
            m_BoundaryIBs[1]->SetPosition({140, 150});
            m_BoundaryIBs[2]->SetPosition({140, 10});
            m_BoundaryIBs[3]->SetPosition({140, -130});
            m_BoundaryIBs[4]->SetPosition({-140, 290});
            m_BoundaryIBs[5]->SetPosition({-140, 150});
            m_BoundaryIBs[6]->SetPosition({-140, 10});
            m_BoundaryIBs[7]->SetPosition({-140, -130});

            m_BoundaryRs[0]->SetPosition({350, 360});
            m_BoundaryRs[1]->SetPosition({350, 290});
            m_BoundaryRs[2]->SetPosition({350, 220});
            m_BoundaryRs[3]->SetPosition({350, 150});
            m_BoundaryRs[4]->SetPosition({350, 80});
            m_BoundaryRs[5]->SetPosition({280, 10});
            m_BoundaryRs[6]->SetPosition({280, -60});
            m_BoundaryRs[7]->SetPosition({280, -130});
            m_BoundaryRs[8]->SetPosition({280, -200});
            m_BoundaryRs[9]->SetPosition({210, -270});
            m_BoundaryRs[10]->SetPosition({140, -270});


            m_BoundaryLs[0]->SetPosition({-350, 360});
            m_BoundaryLs[1]->SetPosition({-350, 290});
            m_BoundaryLs[2]->SetPosition({-350, 220});
            m_BoundaryLs[3]->SetPosition({-350, 150});
            m_BoundaryLs[4]->SetPosition({-350, 80});
            m_BoundaryLs[5]->SetPosition({-280, 10});
            m_BoundaryLs[6]->SetPosition({-280, -60});
            m_BoundaryLs[7]->SetPosition({-280, -130});
            m_BoundaryLs[8]->SetPosition({-280, -200});
            m_BoundaryLs[9]->SetPosition({-210, -270});
            m_BoundaryLs[10]->SetPosition({-140, -270});

            m_BoundaryBs[0]->SetPosition({70, -340});
            m_BoundaryBs[1]->SetPosition({0, -340});
            m_BoundaryBs[2]->SetPosition({-70, -340});

            //enemies
            m_Enemies[0]->SetPosition({0, -60});
            m_Enemies[0]->SetVisible(true);
            m_Enemies[1]->SetPosition({0, 10});
            m_Enemies[1]->SetVisible(true);
            m_Enemies[2]->SetPosition({0, 80});
            m_Enemies[2]->SetVisible(true);
            m_Enemies[3]->SetPosition({0, 150});
            m_Enemies[3]->SetVisible(true);
            m_Enemies[4]->SetPosition({0, 220});
            m_Enemies[4]->SetVisible(true);
            m_Enemies[5]->SetPosition({0, 290});
            m_Enemies[5]->SetVisible(true);
            m_Enemies[6]->SetPosition({0, 360});
            m_Enemies[6]->SetVisible(true);

            break;

            //Phase8_2
        case Phase::Phase8_2:
            Origin();

            //player
            m_Player->SetPosition({0, -280});
            m_Player->SetVisible(true);

            //boss
            m_Boss->SetImage(RESOURCE_DIR"/Image/Character/boss/boss5.png");
            m_Boss->SetPosition({0, -70});
            m_Boss->SetVisible(true);

            //boundaries_precise
            m_BoundaryIBs[0]->SetPosition({140, -270});
            m_BoundaryIBs[1]->SetPosition({-140, -270});
//            m_BoundaryIBs[0]->SetVisible(true);
//            m_BoundaryIBs[1]->SetVisible(true);



//            m_BoundaryRs[0]->SetPosition({350, 360});
//            m_BoundaryRs[1]->SetPosition({350, 290});
//            m_BoundaryRs[2]->SetPosition({350, 220});
//            m_BoundaryRs[3]->SetPosition({350, 150});
//            m_BoundaryRs[4]->SetPosition({350, 80});
//            m_BoundaryRs[5]->SetPosition({280, 10});
//            m_BoundaryRs[6]->SetPosition({280, -60});
//            m_BoundaryRs[7]->SetPosition({280, -130});
//            m_BoundaryRs[8]->SetPosition({280, -200});
//            m_BoundaryRs[9]->SetPosition({210, -270});
//            m_BoundaryRs[10]->SetPosition({140, -270});
//            m_BoundaryRs[0]->SetVisible(true);
//            m_BoundaryRs[1]->SetVisible(true);
//            m_BoundaryRs[2]->SetVisible(true);
//            m_BoundaryRs[3]->SetVisible(true);
//            m_BoundaryRs[4]->SetVisible(true);
//            m_BoundaryRs[5]->SetVisible(true);
//            m_BoundaryRs[6]->SetVisible(true);
//            m_BoundaryRs[7]->SetVisible(true);
//            m_BoundaryRs[8]->SetVisible(true);
//            m_BoundaryRs[9]->SetVisible(true);
//            m_BoundaryRs[10]->SetVisible(true);


            m_BoundaryLs[0]->SetPosition({-220, 70});
            m_BoundaryLs[1]->SetPosition({-290, 10});
            m_BoundaryLs[2]->SetPosition({-360, -60});
            m_BoundaryLs[3]->SetPosition({-360, -130});
            m_BoundaryLs[4]->SetPosition({-360, -200});
            m_BoundaryLs[5]->SetPosition({-360, -270});
            m_BoundaryLs[6]->SetPosition({-360, -340});
//            m_BoundaryLs[0]->SetVisible(true);
//            m_BoundaryLs[1]->SetVisible(true);
//            m_BoundaryLs[2]->SetVisible(true);
//            m_BoundaryLs[3]->SetVisible(true);
//            m_BoundaryLs[4]->SetVisible(true);
//            m_BoundaryLs[5]->SetVisible(true);
//            m_BoundaryLs[6]->SetVisible(true);

            m_BoundaryTs[0]->SetPosition({140, -70});
            m_BoundaryTs[1]->SetPosition({70, -70});
//            m_BoundaryTs[2]->SetPosition({0, -70});
            m_BoundaryTs[3]->SetPosition({-70, -70});
            m_BoundaryTs[4]->SetPosition({-140, -70});
//            m_BoundaryTs[0]->SetVisible(true);
//            m_BoundaryTs[1]->SetVisible(true);
//            m_BoundaryTs[3]->SetVisible(true);
//            m_BoundaryTs[4]->SetVisible(true);

            break;

            //Phase9
        case Phase::Phase9:
            Origin();

            //player
            m_Player->SetPosition({-210, -250});
            m_Player->SetVisible(true);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            //boss
            m_Boss->SetImage(RESOURCE_DIR"/Image/Character/boss/boss5.png");
            m_Boss->SetPosition({0, 110});
            m_Boss->SetVisible(true);

            m_BoundaryLs[0]->SetPosition({-290, -10});
            m_BoundaryLs[1]->SetPosition({-360, -90});
            m_BoundaryLs[2]->SetPosition({-360, -170});
            m_BoundaryLs[3]->SetPosition({-290, -250});
//            m_BoundaryLs[0]->SetVisible(true);
//            m_BoundaryLs[1]->SetVisible(true);
//            m_BoundaryLs[2]->SetVisible(true);
//            m_BoundaryLs[3]->SetVisible(true);

            m_BoundaryBs[0]->SetPosition({220, -330});
            m_BoundaryBs[1]->SetPosition({150, -330});
            m_BoundaryBs[2]->SetPosition({60, -330});
            m_BoundaryBs[3]->SetPosition({-10, -330});
            m_BoundaryBs[4]->SetPosition({-80, -330});
            m_BoundaryBs[5]->SetPosition({-150, -330});
            m_BoundaryBs[6]->SetPosition({-220, -330});
//            m_BoundaryBs[0]->SetVisible(true);
//            m_BoundaryBs[1]->SetVisible(true);
//            m_BoundaryBs[2]->SetVisible(true);
//            m_BoundaryBs[3]->SetVisible(true);
//            m_BoundaryBs[4]->SetVisible(true);
//            m_BoundaryBs[5]->SetVisible(true);
//            m_BoundaryBs[6]->SetVisible(true);

            m_BoundaryRs[0]->SetPosition({290, -10});
            m_BoundaryRs[1]->SetPosition({360, -90});
            m_BoundaryRs[2]->SetPosition({360, -170});
            m_BoundaryRs[3]->SetPosition({290, -250});
//            m_BoundaryRs[0]->SetVisible(true);
//            m_BoundaryRs[1]->SetVisible(true);
//            m_BoundaryRs[2]->SetVisible(true);
//            m_BoundaryRs[3]->SetVisible(true);

            m_BoundaryTs[0]->SetPosition({220, 60});
            m_BoundaryTs[1]->SetPosition({150, -10});
            m_BoundaryTs[2]->SetPosition({150, 60});
            m_BoundaryTs[3]->SetPosition({150, 130});
            m_BoundaryTs[4]->SetPosition({60, 170});
            m_BoundaryTs[6]->SetPosition({-80, 170});
            m_BoundaryTs[7]->SetPosition({-150, 130});
            m_BoundaryIBs[0]->SetPosition({-150, 60});
            m_BoundaryIBs[1]->SetPosition({-150, -10});
            m_BoundaryIBs[2]->SetPosition({-220, 60});
//            m_BoundaryTs[0]->SetVisible(true);
//            m_BoundaryTs[1]->SetVisible(true);
//            m_BoundaryTs[2]->SetVisible(true);
//            m_BoundaryTs[3]->SetVisible(true);
//            m_BoundaryTs[4]->SetVisible(true);
//            m_BoundaryTs[6]->SetVisible(true);
//            m_BoundaryTs[7]->SetVisible(true);
//            m_BoundaryIBs[0]->SetVisible(true);
//            m_BoundaryIBs[1]->SetVisible(true);
//            m_BoundaryIBs[2]->SetVisible(true);

            m_Key->SetPosition({290, -100});
            m_Key->SetVisible(true);

            m_TreasureBox->SetPosition({0, 40});
            m_TreasureBox->SetVisible(true);

            //rocks
            m_Rocks[0]->SetPosition({220, -170});
            m_Rocks[0]->SetVisible(true);
            m_Rocks[1]->SetPosition({150, -170});
            m_Rocks[1]->SetVisible(true);
            m_Rocks[2]->SetPosition({150, -250});
            m_Rocks[2]->SetVisible(true);
            m_Rocks[3]->SetPosition({70, 40});
            m_Rocks[3]->SetVisible(true);
            m_Rocks[4]->SetPosition({70, -100});
            m_Rocks[4]->SetVisible(true);
            m_Rocks[5]->SetPosition({0, -100});
            m_Rocks[5]->SetVisible(true);
            m_Rocks[6]->SetPosition({-70, 40});
            m_Rocks[6]->SetVisible(true);
            m_Rocks[7]->SetPosition({-70, -30});
            m_Rocks[7]->SetVisible(true);
            m_Rocks[8]->SetPosition({-70, -100});
            m_Rocks[8]->SetVisible(true);
            m_Rocks[9]->SetPosition({-70, -170});
            m_Rocks[9]->SetVisible(true);
            m_Rocks[10]->SetPosition({-70, -250});
            m_Rocks[10]->SetVisible(true);
            m_Rocks[11]->SetPosition({-150, -170});
            m_Rocks[11]->SetVisible(true);
            m_Rocks[12]->SetPosition({-220, -30});
            m_Rocks[12]->SetVisible(true);
            m_Rocks[13]->SetPosition({-220, -170});
            m_Rocks[13]->SetVisible(true);
            m_Rocks[14]->SetPosition({-290, -100});
            m_Rocks[14]->SetVisible(true);

            break;

            //Phase10
        case Phase::Phase10:
            Origin();

            //player
            m_Player->SetPosition({-180, -300});
            m_Player->SetVisible(true);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            //Machines
            m_Machines[0]->SetPosition({35, 70});
            m_Machines[0]->SetVisible(true);

            //rocks
            m_Rocks[0]->SetPosition({-40, -230});
            m_Rocks[0]->SetVisible(true);
            m_Rocks[1]->SetPosition({30, -230});
            m_Rocks[1]->SetVisible(true);
            m_Rocks[2]->SetPosition({100, -230});
            m_Rocks[2]->SetVisible(true);

            m_BoundaryLs[0]->SetPosition({-120, 130});
            m_BoundaryLs[1]->SetPosition({-120, 60});
            m_BoundaryLs[2]->SetPosition({-190, -20});
            m_BoundaryLs[3]->SetPosition({-190, -100});
            m_BoundaryLs[4]->SetPosition({-190, -185});
            m_BoundaryLs[5]->SetPosition({-190, -260});
            m_BoundaryLs[6]->SetPosition({-260, -330});
//            m_BoundaryLs[0]->SetVisible(true);
//            m_BoundaryLs[1]->SetVisible(true);
//            m_BoundaryLs[2]->SetVisible(true);
//            m_BoundaryLs[3]->SetVisible(true);
//            m_BoundaryLs[4]->SetVisible(true);
//            m_BoundaryLs[5]->SetVisible(true);
//            m_BoundaryLs[6]->SetVisible(true);

            m_BoundaryTs[0]->SetPosition({-40, 140});
            m_BoundaryTs[1]->SetPosition({30, 140});
            m_BoundaryTs[2]->SetPosition({100, 140});
//            m_BoundaryTs[0]->SetVisible(true);
//            m_BoundaryTs[1]->SetVisible(true);
//            m_BoundaryTs[2]->SetVisible(true);

            m_BoundaryRs[0]->SetPosition({180, 130});
            m_BoundaryRs[1]->SetPosition({180, 60});
            m_BoundaryRs[2]->SetPosition({250, -20});
            m_BoundaryRs[3]->SetPosition({250, -100});
            m_BoundaryRs[4]->SetPosition({250, -180});
            m_BoundaryRs[5]->SetPosition({180, -240});
            m_BoundaryRs[6]->SetPosition({180, -320});
//            m_BoundaryRs[0]->SetVisible(true);
//            m_BoundaryRs[1]->SetVisible(true);
//            m_BoundaryRs[2]->SetVisible(true);
//            m_BoundaryRs[3]->SetVisible(true);
//            m_BoundaryRs[4]->SetVisible(true);
//            m_BoundaryRs[5]->SetVisible(true);
//            m_BoundaryRs[6]->SetVisible(true);

            //m_LaserMechBoxes
            m_LaserMechBoxes[0]->SetPosition({170, -10});
            m_LaserMechBoxes[0]->SetVisible(true);
            m_LaserMechBoxes[1]->SetPosition({170, -80});
            m_LaserMechBoxes[1]->SetVisible(true);
            m_LaserMechBoxes[2]->SetPosition({170, -150});
            m_LaserMechBoxes[2]->SetVisible(true);

            ControlShootLaser();

            break;

            //Phase11
        case Phase::Phase11:
            Origin();

            //player
            m_Player->SetPosition({-210, -95});
            m_Player->SetVisible(true);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            //Machines
            m_Machines[0]->SetPosition({280, 50});
            m_Machines[0]->SetVisible(true);

//            //rocks
//            m_Rocks[0]->SetPosition({70, -240});
//            m_Rocks[0]->SetVisible(true);
//            m_Rocks[1]->SetPosition({0, -170});
//            m_Rocks[1]->SetVisible(true);

            m_BoundaryLs[0]->SetPosition({-290, -100});
            m_BoundaryLs[1]->SetPosition({-290, -170});
            m_BoundaryLs[3]->SetPosition({0, -310});
            m_BoundaryLs[4]->SetPosition({0, -100});
            m_BoundaryLs[5]->SetPosition({0, -170});
            m_BoundaryLs[6]->SetPosition({-70, -100});
            m_BoundaryLs[7]->SetPosition({-70, -170});
//            m_BoundaryLs[0]->SetVisible(true);
//            m_BoundaryLs[1]->SetVisible(true);
//            m_BoundaryLs[3]->SetVisible(true);
//            m_BoundaryLs[4]->SetVisible(true);
//            m_BoundaryLs[5]->SetVisible(true);
//            m_BoundaryLs[6]->SetVisible(true);
//            m_BoundaryLs[7]->SetVisible(true);

            m_BoundaryTs[0]->SetPosition({280, 130});
            m_BoundaryTs[1]->SetPosition({210, 130});
            m_BoundaryTs[2]->SetPosition({140, 130});
            m_BoundaryTs[3]->SetPosition({70, 90});
            m_BoundaryTs[4]->SetPosition({-140, -30});
            m_BoundaryTs[5]->SetPosition({-210, -30});
            m_BoundaryTs[6]->SetPosition({0, -30});
//            m_BoundaryTs[0]->SetVisible(true);
//            m_BoundaryTs[1]->SetVisible(true);
//            m_BoundaryTs[2]->SetVisible(true);
//            m_BoundaryTs[3]->SetVisible(true);
//            m_BoundaryTs[4]->SetVisible(true);
//            m_BoundaryTs[5]->SetVisible(true);

            m_BoundaryRs[0]->SetPosition({360, 130});
            m_BoundaryRs[1]->SetPosition({360, 50});
            m_BoundaryRs[2]->SetPosition({360, -30});
            m_BoundaryRs[3]->SetPosition({360, -100});
            m_BoundaryRs[4]->SetPosition({360, -170});
            m_BoundaryRs[5]->SetPosition({290, -240});
            m_BoundaryRs[6]->SetPosition({290, -310});
            m_BoundaryRs[7]->SetPosition({290, -270});
//            m_BoundaryRs[0]->SetVisible(true);
//            m_BoundaryRs[1]->SetVisible(true);
//            m_BoundaryRs[2]->SetVisible(true);
//            m_BoundaryRs[3]->SetVisible(true);
//            m_BoundaryRs[4]->SetVisible(true);
//            m_BoundaryRs[5]->SetVisible(true);
//            m_BoundaryRs[6]->SetVisible(true);

            m_BoundaryBs[0]->SetPosition({210, -390});
            m_BoundaryBs[1]->SetPosition({140, -390});
            m_BoundaryBs[2]->SetPosition({70, -390});
            m_BoundaryBs[3]->SetPosition({-70, -310});
            m_BoundaryBs[4]->SetPosition({-140, -310});
            m_BoundaryBs[5]->SetPosition({-210, -310});
            m_BoundaryBs[6]->SetPosition({50, -390});
            m_BoundaryBs[7]->SetPosition({90, -390});
//            m_BoundaryBs[0]->SetVisible(true);
//            m_BoundaryBs[1]->SetVisible(true);
//            m_BoundaryBs[2]->SetVisible(true);
//            m_BoundaryBs[3]->SetVisible(true);
//            m_BoundaryBs[4]->SetVisible(true);
//            m_BoundaryBs[5]->SetVisible(true);


            //m_LaserMechBoxes
            m_LaserMechBoxes[0]->SetPosition({280, -100});
            m_LaserMechBoxes[0]->SetVisible(true);
            m_LaserMechBoxes[1]->SetPosition({280, -170});
            m_LaserMechBoxes[1]->SetVisible(true);
            m_LaserMechBoxes[2]->SetPosition({210, 50});
            m_LaserMechBoxes[2]->SetVisible(true);
            m_LaserMechBoxes[3]->SetPosition({140, 50});
            m_LaserMechBoxes[3]->SetVisible(true);
            m_LaserMechBoxes[4]->SetPosition({70, -20});
            m_LaserMechBoxes[4]->SetVisible(true);
            m_LaserMechBoxes[5]->SetPosition({-270, -230});
            m_LaserMechBoxes[5]->SetVisible(true);

            InitiateBlinkLaser();
            ControlShootLaser();

            break;

            //Phase12
        case Phase::Phase12:
            Origin();

            //player
            m_Player->SetPosition({-40, -230});
            m_Player->SetVisible(true);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            //Machines
            m_Machines[0]->SetPosition({255, -240});
            m_Machines[0]->SetVisible(true);
            m_Machines[1]->SetPosition({-170, 60});
            m_Machines[1]->SetVisible(true);

            //rocks
            m_Rocks[0]->SetPosition({-180, -100});
            m_Rocks[0]->SetVisible(true);
            m_Rocks[1]->SetPosition({-40, -170});
            m_Rocks[1]->SetVisible(true);
            m_Rocks[2]->SetPosition({40, -100});
            m_Rocks[2]->SetVisible(true);
            m_Rocks[3]->SetPosition({100, -170});
            m_Rocks[3]->SetVisible(true);
            m_Rocks[4]->SetPosition({100, -240});
            m_Rocks[4]->SetVisible(true);
            m_Rocks[5]->SetPosition({250, -310});
            m_Rocks[5]->SetVisible(true);
            m_Rocks[6]->SetPosition({-30, 60});
            m_Rocks[6]->SetVisible(true);

            m_BoundaryLs[0]->SetPosition({-260, 50});
            m_BoundaryLs[1]->SetPosition({-260, -20});
            m_BoundaryLs[2]->SetPosition({-310, -100});
            m_BoundaryLs[3]->SetPosition({-310, -180});
            m_BoundaryLs[4]->SetPosition({-260, -260});
//            m_BoundaryLs[0]->SetVisible(true);
//            m_BoundaryLs[1]->SetVisible(true);
//            m_BoundaryLs[2]->SetVisible(true);
//            m_BoundaryLs[3]->SetVisible(true);
//            m_BoundaryLs[4]->SetVisible(true);

            m_BoundaryTs[0]->SetPosition({190, 130});
            m_BoundaryTs[1]->SetPosition({120, 130});
            m_BoundaryTs[2]->SetPosition({40, 130});
            m_BoundaryTs[3]->SetPosition({-30, 130});
            m_BoundaryTs[4]->SetPosition({-110, 130});
            m_BoundaryTs[5]->SetPosition({-180, 130});
//            m_BoundaryTs[0]->SetVisible(true);
//            m_BoundaryTs[1]->SetVisible(true);
//            m_BoundaryTs[2]->SetVisible(true);
//            m_BoundaryTs[3]->SetVisible(true);
//            m_BoundaryTs[4]->SetVisible(true);
//            m_BoundaryTs[5]->SetVisible(true);

            m_BoundaryRs[0]->SetPosition({250, 50});
            m_BoundaryRs[1]->SetPosition({250, -20});
            m_BoundaryRs[2]->SetPosition({250, -100});
            m_BoundaryRs[3]->SetPosition({250, -180});
            m_BoundaryRs[4]->SetPosition({320, -240});
            m_BoundaryRs[5]->SetPosition({320, -320});
//            m_BoundaryRs[0]->SetVisible(true);
//            m_BoundaryRs[1]->SetVisible(true);
//            m_BoundaryRs[2]->SetVisible(true);
//            m_BoundaryRs[3]->SetVisible(true);
//            m_BoundaryRs[4]->SetVisible(true);
//            m_BoundaryRs[5]->SetVisible(true);


            m_BoundaryBs[0]->SetPosition({260, -390});
            m_BoundaryBs[1]->SetPosition({190, -390});
            m_BoundaryBs[2]->SetPosition({100, -320});
            m_BoundaryBs[3]->SetPosition({35, -320});
            m_BoundaryBs[4]->SetPosition({-30, -320});
            m_BoundaryBs[5]->SetPosition({-110, -320});
            m_BoundaryBs[6]->SetPosition({-170, -320});
//            m_BoundaryBs[0]->SetVisible(true);
//            m_BoundaryBs[1]->SetVisible(true);
//            m_BoundaryBs[2]->SetVisible(true);
//            m_BoundaryBs[3]->SetVisible(true);
//            m_BoundaryBs[4]->SetVisible(true);
//            m_BoundaryBs[5]->SetVisible(true);
//            m_BoundaryBs[6]->SetVisible(true);

            m_LaserMechBoxes[0]->SetPosition({180, 60});
            m_LaserMechBoxes[0]->SetVisible(true);
            m_LaserMechBoxes[1]->SetPosition({110, 60});
            m_LaserMechBoxes[1]->SetVisible(true);
            m_LaserMechBoxes[2]->SetPosition({35, 60});
            m_LaserMechBoxes[2]->SetVisible(true);
            m_LaserMechBoxes[3]->SetPosition({-100, 60});
            m_LaserMechBoxes[3]->SetVisible(true);

            ControlShootLaser();

            break;

            //Phase13
        case Phase::Phase13:
            Origin();

            //player
            m_Player->SetPosition({140, -310});
            m_Player->SetVisible(true);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            //Machines
            m_Machines[0]->SetPosition({140, 50});
            m_Machines[0]->SetVisible(true);
            m_Machines[1]->SetPosition({-280, -170});
            m_Machines[1]->SetVisible(true);

            //rocks
            m_Rocks[0]->SetPosition({210, -170});
            m_Rocks[0]->SetVisible(true);
            m_Rocks[1]->SetPosition({140, -100});
            m_Rocks[1]->SetVisible(true);
            m_Rocks[2]->SetPosition({0, -30});
            m_Rocks[2]->SetVisible(true);
            m_Rocks[3]->SetPosition({0, 40});
            m_Rocks[3]->SetVisible(true);
            m_Rocks[4]->SetPosition({-140, 40});
            m_Rocks[4]->SetVisible(true);


            m_BoundaryLs[0]->SetPosition({-220, 50});
            m_BoundaryLs[1]->SetPosition({-220, -20});
            m_BoundaryLs[2]->SetPosition({-290, -90});
            m_BoundaryLs[4]->SetPosition({-360, -260});
//            m_BoundaryLs[0]->SetVisible(true);
//            m_BoundaryLs[1]->SetVisible(true);
//            m_BoundaryLs[2]->SetVisible(true);
//            m_BoundaryLs[3]->SetVisible(true);
//            m_BoundaryLs[4]->SetVisible(true);

            m_BoundaryTs[0]->SetPosition({210, 130});
            m_BoundaryTs[1]->SetPosition({140, 130});
            m_BoundaryTs[2]->SetPosition({60, 130});
            m_BoundaryTs[3]->SetPosition({-10, 130});
            m_BoundaryTs[4]->SetPosition({-80, 130});
            m_BoundaryTs[5]->SetPosition({-150, 130});
//            m_BoundaryTs[0]->SetVisible(true);
//            m_BoundaryTs[1]->SetVisible(true);
//            m_BoundaryTs[2]->SetVisible(true);
//            m_BoundaryTs[3]->SetVisible(true);
//            m_BoundaryTs[4]->SetVisible(true);
//            m_BoundaryTs[5]->SetVisible(true);

            m_BoundaryRs[0]->SetPosition({280, 50});
            m_BoundaryRs[1]->SetPosition({360, -20});
            m_BoundaryRs[2]->SetPosition({360, -100});
            m_BoundaryRs[3]->SetPosition({280, -180});
            m_BoundaryRs[4]->SetPosition({280, -260});
            m_BoundaryRs[5]->SetPosition({280, -340});
//            m_BoundaryRs[0]->SetVisible(true);
//            m_BoundaryRs[1]->SetVisible(true);
//            m_BoundaryRs[2]->SetVisible(true);
//            m_BoundaryRs[3]->SetVisible(true);
//            m_BoundaryRs[4]->SetVisible(true);
//            m_BoundaryRs[5]->SetVisible(true);


            m_BoundaryBs[0]->SetPosition({210, -410});
            m_BoundaryBs[1]->SetPosition({140, -410});
            m_BoundaryBs[2]->SetPosition({60, -180});
            m_BoundaryBs[3]->SetPosition({-10, -180});
            m_BoundaryBs[4]->SetPosition({-80, -260});
            m_BoundaryBs[5]->SetPosition({-150, -410});
            m_BoundaryBs[6]->SetPosition({-220, -340});
            m_BoundaryBs[7]->SetPosition({-290, -340});
//            m_BoundaryBs[0]->SetVisible(true);
//            m_BoundaryBs[1]->SetVisible(true);
//            m_BoundaryBs[2]->SetVisible(true);
//            m_BoundaryBs[3]->SetVisible(true);
//            m_BoundaryBs[4]->SetVisible(true);
//            m_BoundaryBs[5]->SetVisible(true);
//            m_BoundaryBs[6]->SetVisible(true);
//            m_BoundaryBs[7]->SetVisible(true);

            m_BoundaryIBs[0]->SetPosition({60, -260});
            m_BoundaryIBs[1]->SetPosition({60, -340});
            m_BoundaryIBs[2]->SetPosition({-80, -340});
//            m_BoundaryIBs[0]->SetVisible(true);
//            m_BoundaryIBs[1]->SetVisible(true);
//            m_BoundaryIBs[2]->SetVisible(true);

            m_LaserMechBoxes[0]->SetPosition({280, -20});
            m_LaserMechBoxes[0]->SetVisible(true);
            m_LaserMechBoxes[1]->SetPosition({280, -90});
            m_LaserMechBoxes[1]->SetVisible(true);
            m_LaserMechBoxes[2]->SetPosition({140, -240});
            m_LaserMechBoxes[2]->SetVisible(true);
            m_LaserMechBoxes[3]->SetPosition({140, -170});
            m_LaserMechBoxes[3]->SetVisible(true);
            m_LaserMechBoxes[4]->SetPosition({70, 60});
            m_LaserMechBoxes[4]->SetVisible(true);
            m_LaserMechBoxes[5]->SetPosition({-70, 60});
            m_LaserMechBoxes[5]->SetVisible(true);
            m_LaserMechBoxes[6]->SetPosition({-140, -310});
            m_LaserMechBoxes[6]->SetVisible(true);
            m_LaserMechBoxes[7]->SetPosition({-200, -90});
            m_LaserMechBoxes[7]->SetVisible(true);
            m_LaserMechBoxes[8]->SetPosition({-200, -160});
            m_LaserMechBoxes[8]->SetVisible(true);

            InitiateBlinkLaser();
            ControlShootLaser();

            break;

            //Phase14
        case Phase::Phase14:
            Origin();

            //player
            m_Player->SetPosition({210, -310});
            m_Player->SetVisible(true);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            //Machines
            m_Machines[0]->SetPosition({70, 60});
            m_Machines[0]->SetVisible(true);
            m_Machines[1]->SetPosition({-210, -20});
            m_Machines[1]->SetVisible(true);


            m_BoundaryLs[0]->SetPosition({-220, 130});
            m_BoundaryLs[1]->SetPosition({-220, 60});
            m_BoundaryLs[2]->SetPosition({-290, -20});
            m_BoundaryLs[3]->SetPosition({-360, -90});
            m_BoundaryLs[4]->SetPosition({-360, -170});
            m_BoundaryLs[5]->SetPosition({-290, -260});
            m_BoundaryLs[6]->SetPosition({-220, -260});
//            m_BoundaryLs[0]->SetVisible(true);
//            m_BoundaryLs[1]->SetVisible(true);
//            m_BoundaryLs[2]->SetVisible(true);
//            m_BoundaryLs[3]->SetVisible(true);
//            m_BoundaryLs[4]->SetVisible(true);
//            m_BoundaryLs[5]->SetVisible(true);
//            m_BoundaryLs[6]->SetVisible(true);

            m_BoundaryTs[0]->SetPosition({210, 130});
            m_BoundaryTs[1]->SetPosition({140, 130});
            m_BoundaryTs[2]->SetPosition({60, 130});
            m_BoundaryTs[3]->SetPosition({-10, 130});
            m_BoundaryTs[4]->SetPosition({-80, 130});
            m_BoundaryTs[5]->SetPosition({-150, 130});
//            m_BoundaryTs[0]->SetVisible(true);
//            m_BoundaryTs[1]->SetVisible(true);
//            m_BoundaryTs[2]->SetVisible(true);
//            m_BoundaryTs[3]->SetVisible(true);
//            m_BoundaryTs[4]->SetVisible(true);
//            m_BoundaryTs[5]->SetVisible(true);

            m_BoundaryRs[0]->SetPosition({290, 60});
            m_BoundaryRs[1]->SetPosition({290, -20});
            m_BoundaryRs[2]->SetPosition({360, -100});
            m_BoundaryRs[3]->SetPosition({360, -180});
            m_BoundaryRs[4]->SetPosition({360, -260});
            m_BoundaryRs[5]->SetPosition({360, -340});
            m_BoundaryRs[6]->SetPosition({325, -20});
//            m_BoundaryRs[0]->SetVisible(true);
//            m_BoundaryRs[1]->SetVisible(true);
//            m_BoundaryRs[2]->SetVisible(true);
//            m_BoundaryRs[3]->SetVisible(true);
//            m_BoundaryRs[4]->SetVisible(true);
//            m_BoundaryRs[5]->SetVisible(true);


            m_BoundaryBs[0]->SetPosition({290, -420});
            m_BoundaryBs[1]->SetPosition({210, -420});
            m_BoundaryBs[2]->SetPosition({140, -420});
            m_BoundaryBs[3]->SetPosition({60, -330});
            m_BoundaryBs[4]->SetPosition({-10, -330});
            m_BoundaryBs[5]->SetPosition({-80, -330});
            m_BoundaryBs[6]->SetPosition({-150, -330});
            m_BoundaryBs[7]->SetPosition({-290, -260});
//            m_BoundaryBs[0]->SetVisible(true);
//            m_BoundaryBs[1]->SetVisible(true);
//            m_BoundaryBs[2]->SetVisible(true);
//            m_BoundaryBs[3]->SetVisible(true);
//            m_BoundaryBs[4]->SetVisible(true);
//            m_BoundaryBs[5]->SetVisible(true);
//            m_BoundaryBs[6]->SetVisible(true);
//            m_BoundaryBs[7]->SetVisible(true);

            //rocks
            m_Rocks[0]->SetPosition({210, 60});
            m_Rocks[0]->SetVisible(true);
            m_Rocks[1]->SetPosition({210, -20});
            m_Rocks[1]->SetVisible(true);
            m_Rocks[2]->SetPosition({210, -90});
            m_Rocks[2]->SetVisible(true);
            m_Rocks[3]->SetPosition({210, -170});
            m_Rocks[3]->SetVisible(true);
            m_Rocks[4]->SetPosition({210, -250});
            m_Rocks[4]->SetVisible(true);
            m_Rocks[5]->SetPosition({70, -170});
            m_Rocks[5]->SetVisible(true);
            m_Rocks[6]->SetPosition({-220, -100});
            m_Rocks[6]->SetVisible(true);

            m_LaserMechBoxes[0]->SetPosition({140, 70});
            m_LaserMechBoxes[0]->SetVisible(true);
            m_LaserMechBoxes[1]->SetPosition({-70, 70});
            m_LaserMechBoxes[1]->SetVisible(true);
            m_LaserMechBoxes[2]->SetPosition({-78, -20});
            m_LaserMechBoxes[2]->SetVisible(true);
            m_LaserMechBoxes[3]->SetPosition({-140, 70});
            m_LaserMechBoxes[3]->SetVisible(true);



            ControlShootLaser();

            break;

            //Phase15
        case Phase::Phase15:
            Origin();

            //player
            m_Player->SetPosition({390, -180});
            m_Player->SetVisible(true);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            //Machines
            m_Machines[0]->SetPosition({390, 30});
            m_Machines[0]->SetVisible(true);
            m_Machines[1]->SetPosition({-320, 30});
            m_Machines[1]->SetVisible(true);

            m_BoundaryLs[0]->SetPosition({-480, 40});
            m_BoundaryLs[1]->SetPosition({-480, -40});
            m_BoundaryLs[2]->SetPosition({-550, -120});
            m_BoundaryLs[3]->SetPosition({-550, -200});
            m_BoundaryLs[4]->SetPosition({-480, -280});
//            m_BoundaryLs[0]->SetVisible(true);
//            m_BoundaryLs[1]->SetVisible(true);
//            m_BoundaryLs[2]->SetVisible(true);
//            m_BoundaryLs[3]->SetVisible(true);
//            m_BoundaryLs[4]->SetVisible(true);

            m_BoundaryRs[0]->SetPosition({470, 120});
            m_BoundaryRs[1]->SetPosition({470, 40});
            m_BoundaryRs[2]->SetPosition({540, -40});
            m_BoundaryRs[3]->SetPosition({540, -120});
            m_BoundaryRs[4]->SetPosition({470, -200});
            m_BoundaryRs[5]->SetPosition({400, -260});
            m_BoundaryRs[6]->SetPosition({400, -340});
//            m_BoundaryRs[0]->SetVisible(true);
//            m_BoundaryRs[1]->SetVisible(true);
//            m_BoundaryRs[2]->SetVisible(true);
//            m_BoundaryRs[3]->SetVisible(true);
//            m_BoundaryRs[4]->SetVisible(true);
//            m_BoundaryRs[5]->SetVisible(true);
//            m_BoundaryRs[6]->SetVisible(true);

            m_BoundaryTs[0]->SetPosition({390, 130});
            m_BoundaryTs[1]->SetPosition({320, 130});
            m_BoundaryTs[2]->SetPosition({250, 130});
            m_BoundaryTs[3]->SetPosition({180, -180});
            m_BoundaryTs[4]->SetPosition({110, -180});
            m_BoundaryTs[5]->SetPosition({40, -120});
            m_BoundaryTs[6]->SetPosition({-30, -250});
            m_BoundaryTs[7]->SetPosition({-100, -250});
            m_BoundaryTs[8]->SetPosition({-170, -40});
            m_BoundaryTs[9]->SetPosition({-240, 130});
            m_BoundaryTs[10]->SetPosition({-310, 130});
            m_BoundaryTs[11]->SetPosition({-380, 130});
//            m_BoundaryTs[0]->SetVisible(true);
//            m_BoundaryTs[1]->SetVisible(true);
//            m_BoundaryTs[2]->SetVisible(true);
//            m_BoundaryTs[3]->SetVisible(true);
//            m_BoundaryTs[4]->SetVisible(true);
//            m_BoundaryTs[5]->SetVisible(true);
//            m_BoundaryTs[6]->SetVisible(true);
//            m_BoundaryTs[7]->SetVisible(true);
//            m_BoundaryTs[8]->SetVisible(true);
//            m_BoundaryTs[9]->SetVisible(true);
//            m_BoundaryTs[10]->SetVisible(true);
//            m_BoundaryTs[11]->SetVisible(true);

            m_BoundaryBs[0]->SetPosition({320, -420});
            m_BoundaryBs[1]->SetPosition({250, -420});
            m_BoundaryBs[2]->SetPosition({180, -420});
            m_BoundaryBs[3]->SetPosition({110, -420});
            m_BoundaryBs[4]->SetPosition({40, -420});
            m_BoundaryBs[5]->SetPosition({-30, -420});
            m_BoundaryBs[6]->SetPosition({-100, -420});
            m_BoundaryBs[7]->SetPosition({-170, -420});
            m_BoundaryBs[8]->SetPosition({-250, -330});
            m_BoundaryBs[9]->SetPosition({-320, -330});
            m_BoundaryBs[10]->SetPosition({-390, -330});
//            m_BoundaryBs[0]->SetVisible(true);
//            m_BoundaryBs[1]->SetVisible(true);
//            m_BoundaryBs[2]->SetVisible(true);
//            m_BoundaryBs[3]->SetVisible(true);
//            m_BoundaryBs[4]->SetVisible(true);
//            m_BoundaryBs[5]->SetVisible(true);
//            m_BoundaryBs[6]->SetVisible(true);
//            m_BoundaryBs[7]->SetVisible(true);
//            m_BoundaryBs[8]->SetVisible(true);
//            m_BoundaryBs[9]->SetVisible(true);
//            m_BoundaryBs[10]->SetVisible(true);

            m_BoundaryIBs[0]->SetPosition({180, 40});
            m_BoundaryIBs[1]->SetPosition({180, -40});
            m_BoundaryIBs[2]->SetPosition({180, -120});
            m_BoundaryIBs[3]->SetPosition({-30, -180});
            m_BoundaryIBs[4]->SetPosition({-100, -180});
            m_BoundaryIBs[5]->SetPosition({-170, 40});
            m_BoundaryIBs[6]->SetPosition({-100, -120});
            m_BoundaryIBs[7]->SetPosition({-30, -220});
            m_BoundaryIBs[8]->SetPosition({-100, -220});
//            m_BoundaryIBs[0]->SetVisible(true);
//            m_BoundaryIBs[1]->SetVisible(true);
//            m_BoundaryIBs[2]->SetVisible(true);
//            m_BoundaryIBs[3]->SetVisible(true);
//            m_BoundaryIBs[4]->SetVisible(true);
//            m_BoundaryIBs[5]->SetVisible(true);
//            m_BoundaryIBs[6]->SetVisible(true);
//            m_BoundaryIBs[7]->SetVisible(true);
//            m_BoundaryIBs[8]->SetVisible(true);

            //rocks
            m_Rocks[0]->SetPosition({320, -40});
            m_Rocks[0]->SetVisible(true);
            m_Rocks[1]->SetPosition({320, -250});
            m_Rocks[1]->SetVisible(true);
            m_Rocks[2]->SetPosition({250, -180});
            m_Rocks[2]->SetVisible(true);
            m_Rocks[3]->SetPosition({-180, -260});
            m_Rocks[3]->SetVisible(true);
            m_Rocks[4]->SetPosition({-250, -40});
            m_Rocks[4]->SetVisible(true);
            m_Rocks[5]->SetPosition({-320, -40});
            m_Rocks[5]->SetVisible(true);
            m_Rocks[6]->SetPosition({-400, -40});
            m_Rocks[6]->SetVisible(true);

            m_LaserMechBoxes[0]->SetPosition({470, -30});
            m_LaserMechBoxes[0]->SetVisible(true);
            m_LaserMechBoxes[1]->SetPosition({470, -110});
            m_LaserMechBoxes[1]->SetVisible(true);
            m_LaserMechBoxes[2]->SetPosition({320, 30});
            m_LaserMechBoxes[2]->SetVisible(true);
            m_LaserMechBoxes[3]->SetPosition({330, -320});
            m_LaserMechBoxes[3]->SetVisible(true);
            m_LaserMechBoxes[4]->SetPosition({250, 30});
            m_LaserMechBoxes[4]->SetVisible(true);
            m_LaserMechBoxes[5]->SetPosition({-250, -260});
            m_LaserMechBoxes[5]->SetVisible(true);
            m_LaserMechBoxes[6]->SetPosition({-320, -260});
            m_LaserMechBoxes[6]->SetVisible(true);
            m_LaserMechBoxes[7]->SetPosition({-390, -260});
            m_LaserMechBoxes[7]->SetVisible(true);
            m_LaserMechBoxes[8]->SetPosition({-460, -120});
            m_LaserMechBoxes[8]->SetVisible(true);
            m_LaserMechBoxes[9]->SetPosition({-460, -190});
            m_LaserMechBoxes[9]->SetVisible(true);

            InitiateBlinkLaser();
            ControlShootLaser();

            break;

        case Phase::PhaseFindal:
            Origin();

            //player
            m_Player->SetPosition({0, 0});
            m_Player->SetVisible(true);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            //SpikeTrap
            m_SpikeTraps[0]->SetPosition({210, 140});
            m_SpikeTraps[0]->SetVisible(true);
            m_SpikeTraps[1]->SetPosition({210, -280});
            m_SpikeTraps[1]->SetVisible(true);
            m_SpikeTraps[2]->SetPosition({140, 140});
            m_SpikeTraps[2]->SetVisible(true);
            m_SpikeTraps[3]->SetPosition({140, -280});
            m_SpikeTraps[3]->SetVisible(true);
            m_SpikeTraps[4]->SetPosition({70, 140});
            m_SpikeTraps[4]->SetVisible(true);
            m_SpikeTraps[5]->SetPosition({70, -280});
            m_SpikeTraps[5]->SetVisible(true);
            m_SpikeTraps[6]->SetPosition({0, 140});
            m_SpikeTraps[6]->SetVisible(true);
            m_SpikeTraps[7]->SetPosition({0, -280});
            m_SpikeTraps[7]->SetVisible(true);
            m_SpikeTraps[8]->SetPosition({-70, 140});
            m_SpikeTraps[8]->SetVisible(true);
            m_SpikeTraps[9]->SetPosition({-70, -280});
            m_SpikeTraps[9]->SetVisible(true);
            m_SpikeTraps[10]->SetPosition({-140, 140});
            m_SpikeTraps[10]->SetVisible(true);
            m_SpikeTraps[11]->SetPosition({-140, -280});
            m_SpikeTraps[11]->SetVisible(true);
            m_SpikeTraps[12]->SetPosition({-210, 140});
            m_SpikeTraps[12]->SetVisible(true);
            m_SpikeTraps[13]->SetPosition({-210, -280});
            m_SpikeTraps[13]->SetVisible(true);

            //chains
            m_ChainVerticals[0]->SetPosition({210, -70});
            m_ChainVerticals[1]->SetPosition({140, -70});
            m_ChainVerticals[2]->SetPosition({70, -70});
            m_ChainVerticals[3]->SetPosition({0, -70});
            m_ChainVerticals[4]->SetPosition({-70, -70});
            m_ChainVerticals[5]->SetPosition({-140, -70});
            m_ChainVerticals[6]->SetPosition({-210, -70});

            m_ChainHorizontals[0]->SetPosition({0, 70});
            m_ChainHorizontals[1]->SetPosition({0, 0});
            m_ChainHorizontals[2]->SetPosition({0, -70});
            m_ChainHorizontals[3]->SetPosition({0, -140});
            m_ChainHorizontals[4]->SetPosition({0, -210});

            m_BoundaryLs[0]->SetPosition({-280, 120});
            m_BoundaryLs[1]->SetPosition({-280, 40});
            m_BoundaryLs[2]->SetPosition({-280, -40});
            m_BoundaryLs[3]->SetPosition({-280, -120});
            m_BoundaryLs[4]->SetPosition({-280, -200});
            m_BoundaryLs[5]->SetPosition({-280, -280});

            m_BoundaryRs[0]->SetPosition({280, 120});
            m_BoundaryRs[1]->SetPosition({280, 40});
            m_BoundaryRs[2]->SetPosition({280, -40});
            m_BoundaryRs[3]->SetPosition({280, -120});
            m_BoundaryRs[4]->SetPosition({280, -200});
            m_BoundaryRs[5]->SetPosition({280, -280});
            m_BoundaryRs[6]->SetPosition({280, -360});

            m_BoundaryTs[0]->SetPosition({390, 210});
            m_BoundaryTs[1]->SetPosition({320, 210});
            m_BoundaryTs[2]->SetPosition({250, 210});
            m_BoundaryTs[3]->SetPosition({180, 210});
            m_BoundaryTs[4]->SetPosition({110, 210});
            m_BoundaryTs[5]->SetPosition({40, 210});
            m_BoundaryTs[6]->SetPosition({-30, 210});
            m_BoundaryTs[7]->SetPosition({-100, 210});
            m_BoundaryTs[8]->SetPosition({-170, 210});
            m_BoundaryTs[9]->SetPosition({-240, 210});
            m_BoundaryTs[10]->SetPosition({-310, 210});
            m_BoundaryTs[11]->SetPosition({-380, 210});

            m_BoundaryBs[0]->SetPosition({320, -350});
            m_BoundaryBs[1]->SetPosition({250, -350});
            m_BoundaryBs[2]->SetPosition({180, -350});
            m_BoundaryBs[3]->SetPosition({110, -350});
            m_BoundaryBs[4]->SetPosition({40, -350});
            m_BoundaryBs[5]->SetPosition({-30, -350});
            m_BoundaryBs[6]->SetPosition({-100, -350});
            m_BoundaryBs[7]->SetPosition({-170, -350});
            m_BoundaryBs[8]->SetPosition({-250, -350});
            m_BoundaryBs[9]->SetPosition({-320, -350});
            m_BoundaryBs[10]->SetPosition({-390, -350});

            m_Crosses[3]->SetPosition({340, -340});
            m_Crosses[2]->SetPosition({190, -340});
            m_Crosses[1]->SetPosition({-190, -340});
            m_Crosses[0]->SetPosition({-340, -340});

            InitiateBlinkChain();

        default:
            break;
    }
}

void App::Origin() {
    m_Player->SetPosition({-1000, -1000});
    m_Player->SetVisible(false);

    m_Boss->SetPosition({-1000, -1000});
    m_Boss->SetVisible(false);

    for (const auto &m_Bosse: m_Bosses) {
        m_Bosse->SetPosition({-1000, -1000});
        m_Bosse->SetVisible(false);
    }

    for (const auto &m_Machine: m_Machines) {
        m_Machine->SetImage(RESOURCE_DIR"/Image/Object/BEEMO.png");
        m_Machine->SetPosition({-1000, -1000});
        m_Machine->SetVisible(false);
        m_Machine->ReSetHitCount();
    }

    for (const auto &m_Rock: m_Rocks) {
        m_Rock->SetPosition({-1000, -1000});
        m_Rock->SetVisible(false);
    }

    for (const auto &m_Enemie: m_Enemies) {
        m_Enemie->SetPosition({-1000, -1000});
        m_Enemie->SetVisible(false);
    }

    for (const auto &m_SpikeTrap: m_SpikeTraps) {
        m_SpikeTrap->SetPosition({-1000, -1000});
        m_SpikeTrap->SetVisible(false);
    }

    for (const auto &m_HiddenSpikeTrap: m_HiddenSpikeTraps) {
        m_HiddenSpikeTrap->SetPosition({-1000, -1000});
        m_HiddenSpikeTrap->SetVisible(false);
    }

    m_Key->SetPosition({-1000, -1000});
    m_Key->SetVisible(false);

    m_TreasureBox->SetPosition({-1000, -1000});
    m_TreasureBox->SetVisible(false);

    for (const auto &m_LaserMechBox: m_LaserMechBoxes) {
        m_LaserMechBox->SetPosition({-1000, -1000});
        m_LaserMechBox->SetVisible(false);
        m_LaserMechBox->ResetUsedLaserIndex();
    }

    for (const auto &m_LaserT: m_LaserTs) {
        m_LaserT->SetImage(RESOURCE_DIR"/Image/Object/laserBeamT.png");
        m_LaserT->SetPosition({-1000, -1000});
        m_LaserT->SetVisible(false);
        m_LaserT->SetUsed(false);
        m_LaserT->SetIfHurt(true);
        m_LaserT->SetIfReverse(false);
    }
    for (const auto &m_LaserL: m_LaserLs) {
        m_LaserL->SetImage(RESOURCE_DIR"/Image/Object/laserBeamL.png");
        m_LaserL->SetPosition({-1000, -1000});
        m_LaserL->SetVisible(false);
        m_LaserL->SetUsed(false);
        m_LaserL->SetIfHurt(true);
        m_LaserL->SetIfReverse(false);
    }
    for (const auto &m_LaserR: m_LaserRs) {
        m_LaserR->SetImage(RESOURCE_DIR"/Image/Object/laserBeamR.png");
        m_LaserR->SetPosition({-1000, -1000});
        m_LaserR->SetVisible(false);
        m_LaserR->SetUsed(false);
        m_LaserR->SetIfHurt(true);
        m_LaserR->SetIfReverse(false);
    }
    for (const auto &m_LaserB: m_LaserBs) {
        m_LaserB->SetImage(RESOURCE_DIR"/Image/Object/laserBeamB.png");
        m_LaserB->SetPosition({-1000, -1000});
        m_LaserB->SetVisible(false);
        m_LaserB->SetUsed(false);
        m_LaserB->SetIfHurt(true);
        m_LaserB->SetIfReverse(false);
    }

    for (const auto &m_BoundaryT: m_BoundaryTs) {
        m_BoundaryT->SetPosition({-1000, -1000});
        m_BoundaryT->SetVisible(false);
    }
    for (const auto &m_BoundaryL: m_BoundaryLs) {
        m_BoundaryL->SetPosition({-1000, -1000});
        m_BoundaryL->SetVisible(false);
    }
    for (const auto &m_BoundaryR: m_BoundaryRs) {
        m_BoundaryR->SetPosition({-1000, -1000});
        m_BoundaryR->SetVisible(false);
    }
    for (const auto &m_BoundaryIB: m_BoundaryIBs) {
        m_BoundaryIB->SetPosition({-1000, -1000});
        m_BoundaryIB->SetVisible(false);
    }
    for (const auto &m_BoundaryB: m_BoundaryBs) {
        m_BoundaryB->SetPosition({-1000, -1000});
        m_BoundaryB->SetVisible(false);
    }

    for (const auto &m_ChainVertical: m_ChainVerticals) {
        m_ChainVertical->SetImage(RESOURCE_DIR"/Image/Object/chainAttackVertical.png");
        m_ChainVertical->SetPosition({-1000, -1000});
        m_ChainVertical->SetVisible(false);
        m_ChainVertical->SetUsed(false);
    }
    for (const auto &m_ChainHorizontal: m_ChainHorizontals) {
        m_ChainHorizontal->SetImage(RESOURCE_DIR"/Image/Object/chainAttackHorizontal.png");
        m_ChainHorizontal->SetPosition({-1000, -1000});
        m_ChainHorizontal->SetVisible(false);
        m_ChainHorizontal->SetUsed(false);
    }

    for (const auto &m_Cross: m_Crosses) {
        m_Cross->SetPosition({-1000, -1000});
        m_Cross->SetVisible(false);
    }

    m_StateImage->SetPosition({-1000, -1000});
    m_StateImage->SetVisible(false);
    m_StateImage->SetImage(RESOURCE_DIR"/Image/Character/healthBar/state1_1.png");
}
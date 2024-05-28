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
            m_SpikeTraps[0]->SetPosition({145,-30});
            m_SpikeTraps[0]->SetVisible(true);
            m_SpikeTraps[1]->SetPosition({75, 100});
            m_SpikeTraps[1]->SetVisible(true);
            m_SpikeTraps[2]->SetPosition({0,100});
            m_SpikeTraps[2]->SetVisible(true);
            m_SpikeTraps[3]->SetPosition({-145,30});
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
            m_SpikeTraps[0]->SetPosition({180,-70});
            m_SpikeTraps[0]->SetVisible(true);
            m_SpikeTraps[1]->SetPosition({105, -70});
            m_SpikeTraps[1]->SetVisible(true);
            m_SpikeTraps[2]->SetPosition({30,70});
            m_SpikeTraps[2]->SetVisible(true);
            m_SpikeTraps[3]->SetPosition({30,0});
            m_SpikeTraps[3]->SetVisible(true);
            m_SpikeTraps[4]->SetPosition({30,-140});
            m_SpikeTraps[4]->SetVisible(true);
            m_SpikeTraps[5]->SetPosition({-40,70});
            m_SpikeTraps[5]->SetVisible(true);
            m_SpikeTraps[6]->SetPosition({-110,0});
            m_SpikeTraps[6]->SetVisible(true);
            m_SpikeTraps[7]->SetPosition({-110,-140});
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
            m_SpikeTraps[0]->SetPosition({-40,80});
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
            m_SpikeTraps[0]->SetPosition({180,0});
            m_SpikeTraps[1]->SetPosition({180, -140});
            m_SpikeTraps[2]->SetPosition({30,0});
            m_SpikeTraps[3]->SetPosition({-40, 70});
            m_SpikeTraps[4]->SetPosition({-40,-140});
            m_SpikeTraps[5]->SetPosition({-180, -140});

            //hiddenspikeTraps
            m_HiddenSpikeTraps[0]->SetPosition({180,0});
            m_HiddenSpikeTraps[0]->SetVisible(true);
            m_HiddenSpikeTraps[1]->SetPosition({180, -140});
            m_HiddenSpikeTraps[1]->SetVisible(true);
            m_HiddenSpikeTraps[2]->SetPosition({30,0});
            m_HiddenSpikeTraps[2]->SetVisible(true);
            m_HiddenSpikeTraps[3]->SetPosition({-40, 70});
            m_HiddenSpikeTraps[3]->SetVisible(true);
            m_HiddenSpikeTraps[4]->SetPosition({-40,-140});
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
            m_SpikeTraps[0]->SetPosition({-70,40});
            m_SpikeTraps[1]->SetPosition({-150, 40});

            //hiddenspikeTraps
            m_HiddenSpikeTraps[0]->SetPosition({-70,40});
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
            m_SpikeTraps[0]->SetPosition({30,-140});
            m_SpikeTraps[1]->SetPosition({30, -210});
            m_SpikeTraps[1]->SetVisible(true);
            m_SpikeTraps[2]->SetPosition({-40,-210});
            m_SpikeTraps[3]->SetPosition({-110, -210});
            m_SpikeTraps[3]->SetVisible(true);
            m_SpikeTraps[4]->SetPosition({-180,-140});
            m_SpikeTraps[4]->SetVisible(true);
            m_SpikeTraps[5]->SetPosition({-180, -210});

            //hiddenspikeTraps
            m_HiddenSpikeTraps[0]->SetPosition({30,-140});
            m_HiddenSpikeTraps[0]->SetVisible(true);
            m_HiddenSpikeTraps[1]->SetPosition({30, -210});
            m_HiddenSpikeTraps[1]->SetVisible(true);
            m_HiddenSpikeTraps[2]->SetPosition({-40, -210});
            m_HiddenSpikeTraps[2]->SetVisible(true);
            m_HiddenSpikeTraps[3]->SetPosition({-110,-210});
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
            m_Player->SetPosition({0, -140});
            m_Player->SetVisible(true);

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

            break;

        //Phase9
        case Phase::Phase9:
            Origin();

            //player
            m_Player->SetPosition({0, 0});
            m_Player->SetVisible(true);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            //boss
            m_Boss->SetImage(RESOURCE_DIR"/Image/Character/boss/boss5.png");
            m_Boss->SetPosition({105, 210});
            m_Boss->SetVisible(true);

            break;

        //Phase10
        case Phase::Phase10:
            Origin();

            //player
            m_Player->SetPosition({-190, -330});
            m_Player->SetVisible(true);

            //StepText
            m_StepText->UpdatePhaseStep(static_cast<int>(m_Phase));
            m_StepText->ShowLeftStep();

            //boss
            m_Boss->SetImage(RESOURCE_DIR"/Image/Character/boss/boss5.png");
            m_Boss->SetPosition({105, 210});
            m_Boss->SetVisible(true);

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
            m_BoundaryRs[4]->SetPosition({250, -185});
            m_BoundaryRs[5]->SetPosition({180, -260});
            m_BoundaryRs[6]->SetPosition({180, -330});
//            m_BoundaryRs[0]->SetVisible(true);
//            m_BoundaryRs[1]->SetVisible(true);
//            m_BoundaryRs[2]->SetVisible(true);
//            m_BoundaryRs[3]->SetVisible(true);
//            m_BoundaryRs[4]->SetVisible(true);
//            m_BoundaryRs[5]->SetVisible(true);
//            m_BoundaryRs[6]->SetVisible(true);

            //m_LaserMechBoxes
            m_LaserMechBoxes[0]->SetPosition({170, -100});
            m_LaserMechBoxes[0]->SetVisible(true);
            ShootLaserL(m_LaserMechBoxes[0]);

            break;

        //Phase11
        case Phase::Phase11:
            Origin();

            break;

        default:
            break;
    }
}

void App::Origin() {
    m_Player->SetPosition({-1000, -1000});
    m_Player->SetVisible(false);

    m_Boss->SetPosition({-1000, -1000});
    m_Boss->SetVisible(false);

    for (int i = 0; i < m_Bosses.size(); i++) {
        m_Bosses[i]->SetPosition({-1000, -1000});
        m_Bosses[i]->SetVisible(false);
    }

    for (int i = 0; i < m_Rocks.size(); i++) {
        m_Rocks[i]->SetPosition({-1000, -1000});
        m_Rocks[i]->SetVisible(false);
    }

    for (int i = 0; i < m_Enemies.size(); i++) {
        m_Enemies[i]->SetPosition({-1000, -1000});
        m_Enemies[i]->SetVisible(false);
    }

    for (int i = 0; i < m_SpikeTraps.size(); i++) {
        m_SpikeTraps[i]->SetPosition({-1000, -1000});
        m_SpikeTraps[i]->SetVisible(false);
    }

    for (int i = 0; i < m_HiddenSpikeTraps.size(); i++) {
        m_HiddenSpikeTraps[i]->SetPosition({-1000, -1000});
        m_HiddenSpikeTraps[i]->SetVisible(false);
    }

    m_Key->SetPosition({-1000, -1000});
    m_Key->SetVisible(false);

    m_TreasureBox->SetPosition({-1000, -1000});
    m_TreasureBox->SetVisible(false);

    for (int i = 0; i < m_LaserMechBoxes.size(); i++) {
        m_LaserMechBoxes[i]->SetPosition({-1000, -1000});
        m_LaserMechBoxes[i]->SetVisible(false);
    }

    for (int i = 0; i < m_LaserTs.size(); ++i) {
        m_LaserTs[i]->SetPosition({-1000, -1000});
        m_LaserTs[i]->SetVisible(false);
    }
    for (int i = 0; i < m_LaserLs.size(); ++i) {
        m_LaserLs[i]->SetPosition({-1000, -1000});
        m_LaserLs[i]->SetVisible(false);
    }
    for (int i = 0; i < m_LaserRs.size(); ++i) {
        m_LaserRs[i]->SetPosition({-1000, -1000});
        m_LaserRs[i]->SetVisible(false);
    }
    for (int i = 0; i < m_LaserBs.size(); ++i) {
        m_LaserBs[i]->SetPosition({-1000, -1000});
        m_LaserBs[i]->SetVisible(false);
    }

    for (int i = 0; i < m_BoundaryTs.size(); i++) {
        m_BoundaryTs[i]->SetPosition({-1000, -1000});
        m_BoundaryTs[i]->SetVisible(false);
    }
    for (int i = 0; i < m_BoundaryLs.size(); i++) {
        m_BoundaryLs[i]->SetPosition({-1000, -1000});
        m_BoundaryLs[i]->SetVisible(false);
    }
    for (int i = 0; i < m_BoundaryRs.size(); i++) {
        m_BoundaryRs[i]->SetPosition({-1000, -1000});
        m_BoundaryRs[i]->SetVisible(false);
    }
    for (int i = 0; i < m_BoundaryIBs.size(); i++) {
        m_BoundaryIBs[i]->SetPosition({-1000, -1000});
        m_BoundaryIBs[i]->SetVisible(false);
    }
    for (int i = 0; i < m_BoundaryBs.size(); i++) {
        m_BoundaryBs[i]->SetPosition({-1000, -1000});
        m_BoundaryBs[i]->SetVisible(false);
    }
}
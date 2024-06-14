#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Util/Root.hpp"
#include "Character.hpp"
#include "Util/Text.hpp"
#include "PhaseResourceManger.hpp"
#include "AnimatedCharacter.hpp"
#include "Util/GameObject.hpp"
#include "FinalMechanics.hpp"

class App {
public:
    App();

    enum class State {
        START,
        UPDATE,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void Start();

    void Update();

    void End(); // NOLINT(readability-convert-member-functions-to-static)

    //if the player let an enemy crash something, the enemy will die
    //CrushEnemy(the enemy, something being hit)
    void CrushEnemy(const std::shared_ptr<Character> &enemy) const {
        enemy->SetVisible(false);
        enemy->SetPosition({-1000, -1000});
    }

    //if the player get the key, the key will disappear
    void GetKey(const std::shared_ptr<Character> &key) const {
        key->SetVisible(false);
        key->SetPosition({-1000, -1000});
    }

    //if the play touched the laser
    void IfPlayerTouchLaser() {
        for (const auto &m_LaserT: m_LaserTs) {
            if (m_LaserT->GetVisibility() && m_LaserT->IfUsed()) {
                if (m_Player->IfCollides(m_LaserT) && m_LaserT->GetIfHurt()) {
                    m_CurrentState = State::START;
                    return;
                }
            }
        }
        for (const auto &m_LaserL: m_LaserLs) {
            if (m_LaserL->GetVisibility() && m_LaserL->IfUsed()) {
                if (m_Player->IfCollides(m_LaserL) && m_LaserL->GetIfHurt()) {
                    m_CurrentState = State::START;
                    return;
                }
            }
        }
        for (const auto &m_LaserR: m_LaserRs) {
            if (m_LaserR->GetVisibility() && m_LaserR->IfUsed()) {
                if (m_Player->IfCollides(m_LaserR) && m_LaserR->GetIfHurt()) {
                    m_CurrentState = State::START;
                    return;
                }
            }
        }
        for (const auto &m_LaserB: m_LaserBs) {
            if (m_LaserB->GetVisibility() && m_LaserB->IfUsed()) {
                if (m_Player->IfCollides(m_LaserB) && m_LaserB->GetIfHurt()) {
                    m_CurrentState = State::START;
                    return;
                }
            }
        }
    }

    //blink the laser
    void BlinkLaser() {
        if (timer > 0.6) {
            if (switchCount < 3) {
                if (switchImage) {
                    for (const auto &m_LaserL: m_LaserLs) {
                        if (m_LaserL->IfUsed() && m_LaserL->GetIfReverse()) {
                            if (switchCount == 0) {
                                m_LaserL->SetImage(RESOURCE_DIR"/Image/Object/laserBeamTempL.png");
                                m_LaserL->SetIfHurt(false);
                            }
                            else if (switchCount == 1) {
                                m_LaserL->SetImage(RESOURCE_DIR"/Image/Object/laserBeamL.png");
                                m_LaserL->SetIfHurt(true);
                            }
                            else if (switchCount == 2){
                                m_LaserL->SetImage(RESOURCE_DIR"/Image/Object/Transparent.png");
                                m_LaserL->SetIfHurt(false);
                            }
                        }
                    }
                    for (const auto &m_LaserR: m_LaserRs) {
                        if (m_LaserR->IfUsed() && m_LaserR->GetIfReverse()) {
                            if (switchCount == 0) {
                                m_LaserR->SetImage(RESOURCE_DIR"/Image/Object/laserBeamTempR.png");
                                m_LaserR->SetIfHurt(false);
                            }
                            else if (switchCount == 1) {
                                m_LaserR->SetImage(RESOURCE_DIR"/Image/Object/laserBeamR.png");
                                m_LaserR->SetIfHurt(true);
                            }
                            else if (switchCount == 2){
                                m_LaserR->SetImage(RESOURCE_DIR"/Image/Object/Transparent.png");
                                m_LaserR->SetIfHurt(false);
                            }
                        }
                    }
                    for (const auto &m_LaserT: m_LaserTs) {
                        if (m_LaserT->IfUsed() && m_LaserT->GetIfReverse()) {
                            if (switchCount == 0) {
                                m_LaserT->SetImage(RESOURCE_DIR"/Image/Object/laserBeamTempT.png");
                                m_LaserT->SetIfHurt(false);
                            }
                            else if (switchCount == 1) {
                                m_LaserT->SetImage(RESOURCE_DIR"/Image/Object/laserBeamT.png");
                                m_LaserT->SetIfHurt(true);
                            }
                            else if (switchCount == 2){
                                m_LaserT->SetImage(RESOURCE_DIR"/Image/Object/Transparent.png");
                                m_LaserT->SetIfHurt(false);
                            }
                        }
                    }
                    for (const auto &m_LaserB: m_LaserBs) {
                        if (m_LaserB->IfUsed() && m_LaserB->GetIfReverse()) {
                            if (switchCount == 0) {
                                m_LaserB->SetImage(RESOURCE_DIR"/Image/Object/laserBeamTempB.png");
                                m_LaserB->SetIfHurt(false);
                            }
                            else if (switchCount == 1) {
                                m_LaserB->SetImage(RESOURCE_DIR"/Image/Object/laserBeamB.png");
                                m_LaserB->SetIfHurt(true);
                            }
                            else if (switchCount == 2){
                                m_LaserB->SetImage(RESOURCE_DIR"/Image/Object/Transparent.png");
                                m_LaserB->SetIfHurt(false);
                            }
                        }
                    }
                }
                else {
                    for (const auto &m_LaserL: m_LaserLs) {
                        if (m_LaserL->IfUsed() && !m_LaserL->GetIfReverse()) {
                            if (switchCount == 0) {
                                m_LaserL->SetImage(RESOURCE_DIR"/Image/Object/laserBeamTempL.png");
                                m_LaserL->SetIfHurt(false);
                            }
                            else if (switchCount == 1) {
                                m_LaserL->SetImage(RESOURCE_DIR"/Image/Object/laserBeamL.png");
                                m_LaserL->SetIfHurt(true);
                            }
                            else if (switchCount == 2){
                                m_LaserL->SetImage(RESOURCE_DIR"/Image/Object/Transparent.png");
                                m_LaserL->SetIfHurt(false);
                            }
                        }
                    }
                    for (const auto &m_LaserR: m_LaserRs) {
                        if (m_LaserR->IfUsed() && !m_LaserR->GetIfReverse()) {
                            if (switchCount == 0) {
                                m_LaserR->SetImage(RESOURCE_DIR"/Image/Object/laserBeamTempR.png");
                                m_LaserR->SetIfHurt(false);
                            }
                            else if (switchCount == 1) {
                                m_LaserR->SetImage(RESOURCE_DIR"/Image/Object/laserBeamR.png");
                                m_LaserR->SetIfHurt(true);
                            }
                            else if (switchCount == 2){
                                m_LaserR->SetImage(RESOURCE_DIR"/Image/Object/Transparent.png");
                                m_LaserR->SetIfHurt(false);
                            }
                        }
                    }
                    for (const auto &m_LaserT: m_LaserTs) {
                        if (m_LaserT->IfUsed() && !m_LaserT->GetIfReverse()) {
                            if (switchCount == 0) {
                                m_LaserT->SetImage(RESOURCE_DIR"/Image/Object/laserBeamTempT.png");
                                m_LaserT->SetIfHurt(false);
                            }
                            else if (switchCount == 1) {
                                m_LaserT->SetImage(RESOURCE_DIR"/Image/Object/laserBeamT.png");
                                m_LaserT->SetIfHurt(true);
                            }
                            else if (switchCount == 2){
                                m_LaserT->SetImage(RESOURCE_DIR"/Image/Object/Transparent.png");
                                m_LaserT->SetIfHurt(false);
                            }
                        }
                    }
                    for (const auto &m_LaserB: m_LaserBs) {
                        if (m_LaserB->IfUsed() && !m_LaserB->GetIfReverse()) {
                            if (switchCount == 0) {
                                m_LaserB->SetImage(RESOURCE_DIR"/Image/Object/laserBeamTempB.png");
                                m_LaserB->SetIfHurt(false);
                            }
                            else if (switchCount == 1) {
                                m_LaserB->SetImage(RESOURCE_DIR"/Image/Object/laserBeamB.png");
                                m_LaserB->SetIfHurt(true);
                            }
                            else if (switchCount == 2){
                                m_LaserB->SetImage(RESOURCE_DIR"/Image/Object/Transparent.png");
                                m_LaserB->SetIfHurt(false);
                            }
                        }
                    }
                }

                switchCount++;
                timer = 0;
            }
            else {
                switchCount = 0;
                switchImage = !switchImage;
            }
        }
    }

    //Set all layers transparent
    void InitiateBlinkLaser() {
        for (const auto & m_LaserT : m_LaserTs) {
            m_LaserT->SetImage(RESOURCE_DIR"/Image/Object/Transparent.png");
            m_LaserT->SetIfHurt(false);
        }
        for (const auto & m_LaserL : m_LaserLs) {
            m_LaserL->SetImage(RESOURCE_DIR"/Image/Object/Transparent.png");
            m_LaserL->SetIfHurt(false);
        }
        for (const auto & m_LaserR : m_LaserRs) {
            m_LaserR->SetImage(RESOURCE_DIR"/Image/Object/Transparent.png");
            m_LaserR->SetIfHurt(false);
        }
        for (const auto & m_LaserB : m_LaserBs) {
            m_LaserB->SetImage(RESOURCE_DIR"/Image/Object/Transparent.png");
            m_LaserB->SetIfHurt(false);
        }
    }

    double timer = 0;

    double invincibleTime;

    FinalMechanics FM;

    void ChangeChainPattern();

    void ShootChain(const std::shared_ptr<Character>& chain);

    void InitiateBlinkChain();

    void BlinkChain();

    void IfPlayerTouchChain();

    void IfPlayerTouchSpike();

    void UpGoingPlayer();

    void DamagePlayer();

    void Healing();

    void ValidState();

    void ResetBeemo();

    void ChangeStateImage();

private:
    void ValidTask();

    void Origin();

    void Move(const std::shared_ptr<Character> &player) const;

    void MoveEx(const std::shared_ptr<Character> &player);

    void MoveFinal(const std::shared_ptr<Character> &player);

    void Push(const std::shared_ptr<Character> &other, char direction) const;

    void IsEnemyHitTrap() const;

    void ChangeSpikeTrap() const;

    void ShootLaserR(const std::shared_ptr<Character> &laserMech);

    void ShootLaserL(const std::shared_ptr<Character> &laserMech);

    void ShootLaserT(const std::shared_ptr<Character> &laserMech);

    void ShootLaserB(const std::shared_ptr<Character> &laserMech);

    void ControlShootLaser();

    void ShootReverse(const std::shared_ptr<Character> &laserMech, char direction);

    bool IsPhasePassed();

    bool IsPhase3Passed();

    bool IsPhaseExPassed();

private:
    enum class Phase {
        Phase1,
        Phase2,
        Phase3,
        Phase4,
        Phase5,
        Phase6,
        Phase7,
        Phase8,
        Phase8_2,
        Phase9,
        Phase10,
        Phase11,
        Phase12,
        Phase13,
        Phase14,
        Phase15,
        PhaseFindal,
        PhaseEnd,
    };

    Phase nextPhase(Phase currentPhase) {
        if (currentPhase == Phase::Phase8 || currentPhase == Phase::Phase8_2) {
            currentPhase = Phase::Phase8_2;
        }
        return static_cast<Phase>(static_cast<int>(currentPhase) + 1);
    }

    State m_CurrentState = State::START;
    Phase m_Phase = Phase::Phase1;

    Util::Root m_Root;

    std::vector<std::shared_ptr<Character>> m_CollideObjects;
    std::vector<std::shared_ptr<AnimatedCharacter>> m_AnimatedCollideObjects;

    std::shared_ptr<Character> m_Player;
    std::shared_ptr<Character> m_Boss;
    std::vector<std::shared_ptr<Character>> m_Bosses;
    std::vector<std::shared_ptr<Character>> m_Machines;

    std::vector<std::shared_ptr<Character>> m_Rocks;
    std::vector<std::shared_ptr<Character>> m_Enemies;
    std::vector<std::shared_ptr<Character>> m_SpikeTraps;
    std::vector<std::shared_ptr<Character>> m_HiddenSpikeTraps;

    std::shared_ptr<Character> m_Key;
    std::shared_ptr<Character> m_TreasureBox;

    std::vector<std::shared_ptr<Character>> m_LaserMechBoxes;

    //lasers
    std::vector<std::shared_ptr<Character>> m_LaserTs;
    std::vector<std::shared_ptr<Character>> m_LaserLs;
    std::vector<std::shared_ptr<Character>> m_LaserRs;
    std::vector<std::shared_ptr<Character>> m_LaserBs;

    //boundary_precise
    std::vector<std::shared_ptr<Character>> m_BoundaryTs;
    std::vector<std::shared_ptr<Character>> m_BoundaryLs;
    std::vector<std::shared_ptr<Character>> m_BoundaryRs;
    std::vector<std::shared_ptr<Character>> m_BoundaryIBs;
    std::vector<std::shared_ptr<Character>> m_BoundaryBs;

    //chains
    std::vector<std::shared_ptr<Character>> m_ChainVerticals;
    std::vector<std::shared_ptr<Character>> m_ChainHorizontals;

    std::vector<std::shared_ptr<Character>> m_Crosses;

    std::shared_ptr<Character> m_StateImage;

    std::shared_ptr<StepText> m_StepText;

    std::shared_ptr<PhaseResourceManger> m_PRM;

    const float grid_size = 70.0f;

    bool switchImage = false;
    int switchCount = 0;
};

#endif

#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Util/Root.hpp"
#include "Character.hpp"
#include "Util/Text.hpp"
#include "PhaseResourceManger.hpp"
#include "AnimatedCharacter.hpp"

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
    void CrushEnemy(const std::shared_ptr<Character>& enemy) const {
        enemy->SetVisible(false);
        enemy->SetPosition({-1000, -1000});
    }

    //if the player get the key, the key will disappear
    void GetKey(const std::shared_ptr<Character>& key) const {
        key->SetVisible(false);
        key->SetPosition({-1000, -1000});
    }

private:
    void ValidTask();
    void Origin();

    void Move(const std::shared_ptr<Character>& player) const;
    void Push(const std::shared_ptr<Character>& player, const std::shared_ptr<Character>& other, char direction) const;
    void StepIntoTrap(const std::shared_ptr<Character>& player, const std::shared_ptr<Character>& trap);
    void GetKey(const std::shared_ptr<Character>& player, const std::shared_ptr<Character>& key);

    bool IsPhasePassed();
    bool IsPhase3Passed();

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
        Phase9,
        Phase10,
    };


    State m_CurrentState = State::START;
    Phase m_Phase = Phase::Phase1;

    Util::Root m_Root;

    std::vector<std::shared_ptr<Character>> m_CollideObjects;

    std::shared_ptr<Character> m_Player;
    std::shared_ptr<Character> m_Boss;
    std::vector<std::shared_ptr<Character>> m_Bosses;

    std::vector<std::shared_ptr<Character>> m_Rocks;
    std::vector<std::shared_ptr<Character>> m_Enemies;
    std::vector<std::shared_ptr<Character>> m_SpikeTraps;
    std::vector<std::shared_ptr<Character>> m_HiddenSpikeTraps;

    std::shared_ptr<Character> m_Key;
    std::shared_ptr<Character> m_TreasureBox;

    //boundary_precise
    std::vector<std::shared_ptr<Character>> m_BoundaryTs;
    std::vector<std::shared_ptr<Character>> m_BoundaryLs;
    std::vector<std::shared_ptr<Character>> m_BoundaryRs;
    std::vector<std::shared_ptr<Character>> m_BoundaryIBs;
    std::vector<std::shared_ptr<Character>> m_BoundaryBs;

    std::shared_ptr<StepText> m_StepText;

    std::shared_ptr<PhaseResourceManger> m_PRM;

    const float grid_size = 70.0f;

};

#endif

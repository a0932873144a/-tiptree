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

private:
    void ValidTask();
    void Move(const std::shared_ptr<Character>& other) const;
    void Push(const std::shared_ptr<Character>& player, const std::shared_ptr<Character>& other) const;
    void HitBoundaryGetBack(const std::shared_ptr<Character>& ptr, const std::shared_ptr<Character>& boundary) const;
    static void CrushEnemy(const std::shared_ptr<Character>& enemy, const std::shared_ptr<Character>& other) ;
    bool IsPhase1Passed();

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

    std::shared_ptr<Character> m_Player;
    std::shared_ptr<Character> m_Boss1;
    std::vector<std::shared_ptr<Character>> m_Rocks;
    std::vector<std::shared_ptr<Character>> m_Enemies;

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

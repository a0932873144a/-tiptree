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
    void HitBoundary(const std::shared_ptr<Character>& other) const;
    void CrushEnemy(const std::shared_ptr<Character>& enemy, const std::shared_ptr<Character>& other) const;

private:
    enum class Phase {
        Phase1,
        Phase2,
    };


    State m_CurrentState = State::START;
    Phase m_Phase = Phase::Phase1;

    Util::Root m_Root;

    std::shared_ptr<Character> m_Player;
    std::shared_ptr<Character> m_Boss1;
    std::shared_ptr<Character> m_Rock;
    std::shared_ptr<Character> m_Enemy;

    //boundary_precise
    std::shared_ptr<Character> m_BoundaryT1;
    std::shared_ptr<Character> m_BoundaryT2;
    std::shared_ptr<Character> m_BoundaryT3;
    std::shared_ptr<Character> m_BoundaryT4;
    std::shared_ptr<Character> m_BoundaryT5;

    std::shared_ptr<Character> m_BoundaryL1;
    std::shared_ptr<Character> m_BoundaryL2;
    std::shared_ptr<Character> m_BoundaryL3;
    std::shared_ptr<Character> m_BoundaryL4;
    std::shared_ptr<Character> m_BoundaryL5;

    std::shared_ptr<Character> m_BoundaryR1;
    std::shared_ptr<Character> m_BoundaryR2;
    std::shared_ptr<Character> m_BoundaryR3;
    std::shared_ptr<Character> m_BoundaryR4;
    std::shared_ptr<Character> m_BoundaryR5;
    std::shared_ptr<Character> m_BoundaryR6;

    std::shared_ptr<Character> m_BoundaryIB1;
    std::shared_ptr<Character> m_BoundaryIB2;
    std::shared_ptr<Character> m_BoundaryIB3;
    std::shared_ptr<Character> m_BoundaryIB4;


    std::shared_ptr<Character> m_BoundaryB1;
    std::shared_ptr<Character> m_BoundaryB2;
    std::shared_ptr<Character> m_BoundaryB3;
    std::shared_ptr<Character> m_BoundaryB4;
    std::shared_ptr<Character> m_BoundaryB5;
    std::shared_ptr<Character> m_BoundaryB6;
    std::shared_ptr<Character> m_BoundaryB7;



    std::shared_ptr<StepText> m_StepText;


    //TODO(to RAY): example here
//    std::vector<std::shared_ptr<Character>> m_Rocks_Phase1;
//
//    std::shared_ptr<AnimatedCharacter> m_Bee;
//    std::shared_ptr<AnimatedCharacter> m_Ball;

    std::shared_ptr<PhaseResourceManger> m_PRM;

    //TODO(to RAY): adjust grid_size that make player move on the grid, also adjust the image size
    const float grid_size = 70.0f;

};

#endif

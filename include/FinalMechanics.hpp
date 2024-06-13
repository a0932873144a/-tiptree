//
// Created by 翁廷豪 on 2024/6/11.
//

#ifndef REPLACE_WITH_YOUR_PROJECT_NAME_FINALMECHANICS_HPP
#define REPLACE_WITH_YOUR_PROJECT_NAME_FINALMECHANICS_HPP

#include "Util/Root.hpp"
#include "Character.hpp"
#include "Util/Text.hpp"
#include "PhaseResourceManger.hpp"
#include "AnimatedCharacter.hpp"
#include "Util/Time.hpp"

class FinalMechanics {
public:
    int GetState() {
        return state;
    }

    void AddState() {
        state++;
    }

    void ResetState() {
        state = 1;
    }

    int GetCycle() {
        return cycle;
    }

    void AddCycle() {
        cycle++;
    }

    bool IsCycleDone() {
        if (cycle > 5) {
            return true;
        }
        else {
            return false;
        }
    }

    void ResetCycle() {
        cycle = 0;
    }

    void SetBeemo(bool flag) {
        ifBeemoSetUp = flag;
    }

    bool GetIfSetUP() {
        return ifBeemoSetUp;
    }

private:
    int state = 1;

    int cycle = 0;

    bool ifBeemoSetUp = false;
};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_FINALMECHANICS_HPP

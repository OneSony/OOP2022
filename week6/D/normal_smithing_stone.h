#include"smithing_stone.h"
class NormalSmithingStone:public SmithingStone{
    public:
    NormalSmithingStone(int level):SmithingStone(level){
    }
    void add(int amount);
    bool greater(int need){
        return greater_equal(need);
    }
};
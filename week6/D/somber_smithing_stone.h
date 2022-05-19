#include"smithing_stone.h"
class SomberSmithingStone:public SmithingStone{
    public:
    SomberSmithingStone(int level):SmithingStone(level){
        
    }
    void add(int amount);
    bool greater(int need){
        return greater_equal(need);
    }
};
#include"weapon.h"
class SomberWeapon:public Weapon{
    public:
    SomberWeapon(string name):Weapon(name){
    };
    string getname(){
        return get_name();
    }
    int getlevel(){
        return get_level();
    }
    void levelup();
};
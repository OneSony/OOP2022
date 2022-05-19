#include"weapon.h"
class NormalWeapon:public Weapon{
    public:
    NormalWeapon(string name):Weapon(name){
    };
    string getname(){
        return get_name();
    }
    int getlevel(){
        return get_level();
    }
    void levelup();
};
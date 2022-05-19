#include<iostream>
#include<string>
#include"tarnished.h"

using namespace std;

Tarnished::Tarnished(){
    for(int i=0;i<MAX_STONES;i++){
        normal_smithing_stones[i]=nullptr;
        somber_smithing_stones[i]=nullptr;
    }

    for(int i=0;i<MAX_WEAPONS;i++){
        normal_weapons[i]=nullptr;
        somber_weapons[i]=nullptr;
    }
}

Tarnished::~Tarnished(){
    for(int i=0;i<MAX_STONES;i++){
        if(normal_smithing_stones[i]!=nullptr){
            cout<<"Normal smithing stone "<<i<<" was destroyed."<<endl;
            delete normal_smithing_stones[i];
            normal_smithing_stones[i]=nullptr;
        }
    }
    for(int i=0;i<MAX_STONES;i++){
        if(somber_smithing_stones[i]!=nullptr){
            cout<<"Somber smithing stone "<<i<<" was destroyed."<<endl;
            delete somber_smithing_stones[i];
            somber_smithing_stones[i]=nullptr;
        }
    }
    for(int i=0;i<MAX_WEAPONS;i++){
        if(normal_weapons[i]!=nullptr){
            switch(normal_weapons[i]->getlevel()){
                case 0:
                cout<<"Normal weapon "<<normal_weapons[i]->getname()<<" was destroyed."<<endl;
                break;

                default:
                cout<<"Normal weapon "<<normal_weapons[i]->getname()<<"+"<<normal_weapons[i]->getlevel()<<" was destroyed."<<endl;
                break;
            }
            delete normal_weapons[i];
            normal_weapons[i]=nullptr;
        }
    }
    for(int i=0;i<MAX_WEAPONS;i++){
        if(somber_weapons[i]!=nullptr){
            switch(somber_weapons[i]->getlevel()){
                case 0:
                cout<<"Somber weapon "<<somber_weapons[i]->getname()<<" was destroyed."<<endl;
                break;

                default:
                cout<<"Somber weapon "<<somber_weapons[i]->getname()<<"+"<<somber_weapons[i]->getlevel()<<" was destroyed."<<endl;
                break;
            }
            delete somber_weapons[i];
            somber_weapons[i]=nullptr;
        }
    }
}

void Tarnished::pick_up_stone(int type, int level, int number){
    switch(type){
        case 0://普通
        if(normal_smithing_stones[level]==nullptr){
            normal_smithing_stones[level]=new NormalSmithingStone(level);
            cout<<"Normal smithing stone "<<level<<" was created."<<endl;
            normal_smithing_stones[level]->add(number);
        }else{
            normal_smithing_stones[level]->add(number);
        }
        break;

        case 1://失色
        if(somber_smithing_stones[level]==nullptr){
            somber_smithing_stones[level]=new SomberSmithingStone(level);
            cout<<"Somber smithing stone "<<level<<" was created."<<endl;
            somber_smithing_stones[level]->add(number);
        }else{
            somber_smithing_stones[level]->add(number);
        }
        break;
    }
    return;
}

void Tarnished::pick_up_weapon(int type, string name){
    switch(type){
        case 0://普通
        for(int i=0;i<MAX_WEAPONS;i++){
            if(normal_weapons[i]==nullptr){
                normal_weapons[i]=new NormalWeapon(name);
                cout<<"Normal weapon "<<normal_weapons[i]->getname()<<" was created."<<endl;
                break;
            }
        }
        break;

        case 1://失色
        for(int i=0;i<MAX_WEAPONS;i++){
            if(somber_weapons[i]==nullptr){
                somber_weapons[i]=new SomberWeapon(name);
                cout<<"Somber weapon "<<somber_weapons[i]->getname()<<" was created."<<endl;
                break;
            }
        }
        break;
    }
}

void Tarnished::upgrade_weapon(int target,string name){
    for(int i=0;i<MAX_STONES;i++){
        if(normal_weapons[i]==nullptr){
            continue;
        }

        if(normal_weapons[i]->getname()==name){
            int weapon_old_level=normal_weapons[i]->getlevel();

            if(target<=weapon_old_level){
                cout<<"Stay calm!"<<endl;
                return;
            }
            
            /*for(int now=weapon_old_level+1;now<=target;now++){
                int now_stone_level=((now-1)/3)+1;
                int need_stone_num=(((now+2)%3)+1)*2;

                if(normal_smithing_stones[now_stone_level]==nullptr){
                    cout<<"Upgrade failed for lacking normal smithing stone "<<now_stone_level<<"."<<endl;
                    return;
                }
                if(normal_smithing_stones[now_stone_level]->greater(need_stone_num)==true){
                    continue;
                }else{
                    cout<<"Upgrade failed for lacking normal smithing stone "<<now_stone_level<<"."<<endl;
                    return;
                }
            }*/

            int temp_consume;//对某一种等级的总消耗

            int now_stone_level=-1;
            int need_stone_num;
            for(int now=weapon_old_level+1;now<=target;now++){
                need_stone_num=(((now+2)%3)+1)*2;

                if(now_stone_level!=-1){
                    if(((now-1)/3)+1==now_stone_level){//和上一轮同一等级
                        now_stone_level=((now-1)/3)+1;
                        temp_consume+=need_stone_num;
                    }else{
                        now_stone_level=((now-1)/3)+1;
                        temp_consume=need_stone_num;
                    }
                }else{
                    now_stone_level=((now-1)/3)+1;
                    temp_consume=need_stone_num;
                }
                
                if(normal_smithing_stones[now_stone_level]==nullptr){
                    cout<<"Upgrade failed for lacking normal smithing stone "<<now_stone_level<<"."<<endl;
                    return;
                }

                if(normal_smithing_stones[now_stone_level]->greater(temp_consume)==true){
                    continue;
                }else{
                    cout<<"Upgrade failed for lacking normal smithing stone "<<now_stone_level<<"."<<endl;
                    return;
                }
            }

            for(int now=weapon_old_level+1;now<=target;now++){
                int now_stone_level=((now-1)/3)+1;
                int need_stone_num=(((now+2)%3)+1)*2;

                normal_smithing_stones[now_stone_level]->add(-need_stone_num);

                if(normal_smithing_stones[now_stone_level]->greater(1)==false){
                    cout<<"Normal smithing stone "<<now_stone_level<<" was destroyed."<<endl;
                    delete normal_smithing_stones[now_stone_level];
                    normal_smithing_stones[now_stone_level]=nullptr;
                }

                normal_weapons[i]->levelup();
            }

            switch(weapon_old_level){
                case 0:
                cout<<"Upgrade "<<normal_weapons[i]->getname()<<" to "<<normal_weapons[i]->getname()<<"+"<<target<<" Successfully."<<endl;
                break;
                
                default:
                cout<<"Upgrade "<<normal_weapons[i]->getname()<<"+"<<weapon_old_level<<" to "<<normal_weapons[i]->getname()<<"+"<<target<<" Successfully."<<endl;
                break;
            }
            return;
        }
    }


    //somber
    for(int i=0;i<MAX_STONES;i++){
        if(somber_weapons[i]==nullptr){
            continue;
        }
        if(somber_weapons[i]->getname()==name){

            int weapon_old_level=somber_weapons[i]->getlevel();

            if(target<=weapon_old_level){
                cout<<"Stay calm!"<<endl;
                return;
            }
            
            for(int now=weapon_old_level+1;now<=target;now++){
                int now_stone_level=now;


                if(somber_smithing_stones[now_stone_level]==nullptr){
                    cout<<"Upgrade failed for lacking somber smithing stone "<<now_stone_level<<"."<<endl;
                    return;
                }

                if(somber_smithing_stones[now_stone_level]->greater(1)==true){
                    continue;
                }else{
                    cout<<"Upgrade failed for lacking somber smithing stone "<<now_stone_level<<"."<<endl;
                    return;
                }
            }


            for(int now=weapon_old_level+1;now<=target;now++){
                int now_stone_level=now;

                somber_smithing_stones[now_stone_level]->add(-1);

                if(somber_smithing_stones[now_stone_level]->greater(1)==false){
                    cout<<"Somber smithing stone "<<now_stone_level<<" was destroyed."<<endl;
                    delete somber_smithing_stones[now_stone_level];
                    somber_smithing_stones[now_stone_level]=nullptr;
                }

                somber_weapons[i]->levelup();
            }

            switch(weapon_old_level){
                case 0:
                cout<<"Upgrade "<<somber_weapons[i]->getname()<<" to "<<somber_weapons[i]->getname()<<"+"<<target<<" Successfully."<<endl;
                break;
                
                default:
                cout<<"Upgrade "<<somber_weapons[i]->getname()<<"+"<<weapon_old_level<<" to "<<somber_weapons[i]->getname()<<"+"<<target<<" Successfully."<<endl;
                break;
            }
            return;
        }
    }


    cout<<"You don't have the right!"<<endl;
    return;
}
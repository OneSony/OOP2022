#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include<sstream>


using namespace std;



// Change this file as you want or add more files






class Vocabulary
{
private:
    map<string,int> _m;

public:
    vector<int> insertSentReturnIds(string sentence){

        vector<int> vi;
        static stringstream ss;
        static int word_count=1;
        ss.str("");
	    ss.clear(); 
        ss<<sentence;

        string word;

        for(;;){
            if(ss.rdbuf()->in_avail()==0){
                break;
            }

            ss>>word;
            auto iter=_m.find(word);
            if(iter==_m.end()){
                _m.insert(make_pair(word,word_count));
                vi.push_back(word_count);
                word_count++;
            }else{
                vi.push_back(iter->second);
            }
        }

        return vi;
    }
};


class DataLoader{
private:
    vector<vector<int>> _all_data;
    vector<int> _rand_order;
    int batch_size;
public:
    void setBatchSize(int N){
        this->batch_size=N;
    }

    void setOrder(vector<int>& x){
        _rand_order=x;
    }

    void addData(vector<int> sent_encoding){
        _all_data.push_back(sent_encoding);
    }

    struct Iterator
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        // Add more using statement here
        // hint: using value_type = ?
        //       using reference = ?

        //Define your constructor and functions that are needed for a Iterator.

        Iterator(vector<vector<int>> *b,vector<int> *r,int bs,int c){
            dp=b;
            rp=r;
            batch_size=bs;
            cursor_first=c;
        }

        bool operator!=(Iterator &other){
            return this->cursor_first!=other.cursor_first;
        }

        void operator++(){
            cursor_first+=batch_size;
        }

        vector<vector<int>> operator*(){
            _batch.clear();
            int this_batch_size=batch_size;
            int max_length=0;
            int inner_cursor=cursor_first;

            for(int i=0;i<this_batch_size;i++){
                if(inner_cursor==rp->size()){
                    this_batch_size=i;
                    break;
                }
                _batch.push_back((*dp)[(*rp)[inner_cursor]]);
                inner_cursor++;

                if(_batch[i].size()>max_length){
                    max_length=_batch[i].size();
                }
            }

            for(int i=0;i<this_batch_size;i++){
                for(int j=_batch[i].size();j<max_length;j++){
                    _batch[i].push_back(0);
                }
            }

            return _batch;
        }


        private:
        vector<vector<int>> _batch;
        int cursor_first;

        int batch_size;
        vector<vector<int>> *dp;
        vector<int> *rp;

    };

    Iterator begin() {//begin可以不来，都放到++
        return Iterator(&_all_data,&_rand_order,batch_size,0);//batch也要返回，这些运算应该放在*运算符里
    }

    Iterator end() {
        int more=_rand_order.size()%batch_size;
        if(more==0){
            more=batch_size;
        }
        return Iterator(&_all_data,&_rand_order,batch_size,_rand_order.size()-more+batch_size);//超尾
    }

};
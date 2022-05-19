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
    static vector<int> _rand_order;
    static int batch_size;
    static vector<vector<int>> _all_data;
public:
    void setBatchSize(int N){
        this->batch_size = N; // can also change
    }

    void setOrder(vector<int>& x){
        _rand_order = x; // can also change
    }

    void addData(vector<int> sent_encoding){
        //Enter you code here;
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

        Iterator(){
            cursor=0;
        };
        Iterator(vector<vector<int>> b){
            _batch=b;
            cursor=0;
        }
        Iterator(vector<vector<int>> b,int c){
            _batch=b;
            cursor=c;
        }

        bool operator!=(Iterator &other){
            return this->_batch!=other._batch;
        }

        void operator++(){
            _batch.clear();
            int this_batch_size=batch_size;
            int max_length=0;

            //cout<<"cursor:"<<cursor<<endl;

            for(int i=0;i<this_batch_size;i++){
                if(cursor==_rand_order.size()){
                    this_batch_size=i;
                    break;
                }
                _batch.push_back(_all_data[_rand_order[cursor]]);
                cursor++;

                if(_batch[i].size()>max_length){
                    max_length=_batch[i].size();
                }
            }

            for(int i=0;i<this_batch_size;i++){
                for(int j=_batch[i].size();j<max_length;j++){
                    _batch[i].push_back(0);
                }
            }
        }

        vector<vector<int>> operator*(){
            return _batch;
        }


        private:
        vector<vector<int>> _batch;
        int cursor;
    };

    Iterator begin() {
        vector<vector<int>> _batch;
        int max_length=0;
        int this_batch_size=batch_size;

        for(int i=0;i<this_batch_size;i++){
            
            if(i==_rand_order.size()){
                this_batch_size=i;
                break;
            }

            _batch.push_back(_all_data[_rand_order[i]]);
            if(_batch[i].size()>max_length){
                max_length=_batch[i].size();
            }
        }
        
        for(int i=0;i<this_batch_size;i++){
            for(int j=_batch[i].size();j<max_length;j++){
                _batch[i].push_back(0);
            }
        }

        return Iterator(_batch,this_batch_size);
    }

    Iterator end() {
        vector<vector<int>> _batch;
        int max_length=0;
        int end_batch_size=_all_data.size()%batch_size;

        if(end_batch_size=0){
            end_batch_size=batch_size;
        }

        for(int i=_all_data.size()-end_batch_size-1;i<end_batch_size;i++){
            _batch.push_back(_all_data[_rand_order[i]]);
            if(_batch[i].size()>max_length){
                max_length=_batch[i].size();
            }
        }
        
        for(int i=_all_data.size()-end_batch_size-1;i<end_batch_size;i++){
            for(int j=_batch[i].size();j<max_length;j++){
                _batch[i].push_back(0);
            }
        }

        return Iterator(_batch,_rand_order.size());
    }

};


vector<int> DataLoader::_rand_order;
int DataLoader::batch_size;
vector<vector<int>> DataLoader::_all_data;

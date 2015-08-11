#include <iostream>

#include <vector>
#include <fstream>

#include <math.h>
#include <sstream>



using namespace std;


int main()
{
    ifstream fin;
    fin.open("lables.txt",ios::in);

    ifstream imfin;
    imfin.open("images.txt",ios::in);

    cout << fin.is_open()<<endl;


    string tmp_test;
    long times(0);//数据总组数
    long size(0);//特征总数（数据总组数*每行特征数）
    while(fin>>tmp_test){
        //cout << tmp_test << endl;
        times++;
    }
    while(imfin>>tmp_test){
        //cout << tmp_test << endl;
        size++;
    }
    long line_size(0);//每行特征数
    line_size = size / times;
    cout << line_size;

    //开始加载数据
    vector<vector<double> > IN;
    vector<double> OUT;
    fin.open("lables.txt",ios::in);
    imfin.open("images.txt",ios::in);
    double tmp_double;

    for(int i(0);i < times;i++){
        fin>>tmp_test;
        cout <<"test:"<<tmp_test <<endl;
        istringstream tmp(tmp_test);
        tmp>>tmp_double;


        OUT.push_back(tmp_double);
        vector<double> tmp_in;
        for(int j(0);j<line_size;j++){
            imfin>>tmp_test;
            istringstream tmp(tmp_test);
            tmp >> tmp_double;
            cout <<"test:"<<tmp_test <<endl;
            tmp_in.push_back(tmp_double);

        }
        IN.push_back(tmp_in);
    }
    for(int i(0);i < times;i++){

        for(int j(0);j<line_size;j++){
            cout <<IN[i][j]<<endl;

        }

    }


    int k(0);
    cin >> k;
    return 0;
}


/*
                    Data
Physics Scores  15  12  8   8   7   7   7   6   5   3
History Scores  10  25  17  11  13  17  20  13  9   15

*/
//soal = https://www.hackerrank.com/challenges/correlation-and-regression-lines-6/problem?isFullScreen=true
//sumber: https://www.geeksforgeeks.org/karl-pearsons-coefficient-of-correlation-methods-and-examples/
#include <iostream>
#include <array>
#include <cmath>
struct DataStatistic{
    int Devisiasi;
    int squareX;
    int squareY;
    int sumX;
    int sumY;
    int size;
};
void XSquared(std::array<int,10> &PhyScore,DataStatistic &stat){
    int Squared;
    int sum = 0;
    for(int i = 0; i <= PhyScore.size() - 1;i++){
        Squared = PhyScore[i] * PhyScore[i];
        sum += Squared;
    }
    stat.squareX = sum;
    std::cout << "X square: " << stat.squareX << std::endl;
}
void YSquared(std::array<int,10> &HistoScore,DataStatistic &stat){
    int Squared;
    int sum = 0;
    for(int i = 0; i <= HistoScore.size() - 1;i++){
        Squared = pow(HistoScore[i],2); // sama saja
        sum += Squared;
    }
    stat.squareY = sum;
    std::cout << "X Square: " << stat.squareY << std::endl;
}
void FinalDeviation(std::array<int,10> &PhyScore,DataStatistic &stat,std::array<int,10> &HistoScore){
    int sum = 0;
    int RCorrelation;
    int sumY = 0;
    int sumdevisiasi = 0;
    int ResultMeanY,ResultDeviationY;
    int ResultMean,ResultDeviationX,SumDeviation;
    // rata-rata x
    for(int i = 0; i <= PhyScore.size() - 1; i++){
        sum += PhyScore[i];
    }
    std::cout << "SUMX: " << sum << std::endl;
    ResultMean = sum / PhyScore.size(); //devisiasiX
    std::cout << "MeanX: " << ResultMean << std::endl;
    //rata rata Y
    for(int i = 0; i <= HistoScore.size() - 1; i++){
        sumY += HistoScore[i];
    }
    std::cout << "SUMY: " << sumY << std::endl; 
    ResultMeanY = sumY / HistoScore.size(); // Devisiasi Y
    std::cout << "MeanY: " << ResultMeanY << std::endl;
    // ini adalah sum X x Y
    for(int i = 0; i <= PhyScore.size() - 1; i++){ // 
        ResultDeviationY = HistoScore[i] - ResultMeanY;
        ResultDeviationX = PhyScore[i] - ResultMean;
        SumDeviation =  ResultDeviationX * ResultDeviationY;
        sumdevisiasi += SumDeviation;
    }
    stat.Devisiasi = sumdevisiasi;
    // stat.Devisiasi = sumDeviation;
    std::cout << "HasilDevisiasi: " << stat.Devisiasi << std::endl;   
    
}

void karl_correlation(DataStatistic &stat){
    float r;
    r = stat.Devisiasi / sqrt(stat.squareX * stat.squareY);
    std::cout << "Hasil Devisiasi: " << r << std::endl;
}


int main(){
    DataStatistic stat;
    std::array<int, 10> PhyScore= {15 ,12,8,8,7,7,7,6 ,5,3};
    std::array<int,10> HistoScore = {10,25,17,11,13,17,20,13,9,15};
    stat.size = PhyScore.size();
    XSquared(PhyScore,stat);
    YSquared(HistoScore,stat);
    FinalDeviation(PhyScore,stat,HistoScore);
    karl_correlation(stat);
    // SumIndependen(PhyScore,stat);
    // Sumdependen(HistoScore,stat);
    // XSquared(PhyScore,stat);
    // YSquared(HistoScore,stat);
    std::cin.get();
    return 0;
}
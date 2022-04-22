#include "matrix.hpp"

using std::fstream; 
using std::string; 
using std::pair; 

Matrix::Matrix() {
    fstream f("../data/fixed_data.csv");
    int i=0;
    int n=55863;
    distMatrix=nullptr;
    matrix= new bool*[n];
    for(size_t i=0;i<n;i++)
    {
        matrix[i]=new bool[n];
    }
    while(f.peek()!=EOF)
    {
        int x;
        std::string a,b;
        f>>x>>a>>b;
        if(indices.count(a))
        {
            indices.insert(pair<string,int>(a,i));
            names.insert(pair<int,string>(i,a));
            i++;
        }
        if(indices.count(b))
        {
            indices.insert(pair<string,int>(b,i));
            names.insert(pair<int,string>(i,b));
            i++;
        }
        matrix[indices[a]][indices[b]]=true;
    }
}
Matrix::Matrix(fstream f)
{
    int i=0;
    int n=55863;
    matrix= new bool*[n];
    for(size_t i=0;i<n;i++)
    {
        matrix[i]=new bool[n];
    }
    while(f.is_open())
    {
        int x;
        string a,b;
        f>>x>>a>>b;
        if(indices.count(a))
        {
            indices.insert(pair<string, int>(a,i));
            i++;
        }
        if(indices.count(b))
        {
            indices.insert(pair<string,int>(b,i));
            i++;
        }
        matrix[indices[a]][indices[b]]=true;
    }
}
Matrix::~Matrix()
{
    for(size_t i=0;i<n;i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
bool Matrix::isConnectedTo(string a, string b)
{
    return matrix[indices[a]][indices[b]];
}
std::string Matrix::name(int a)
{
    return names[a];
}
int** Matrix::shortestPath()
{
    distMatrix=new int*[n];
    for(size_t i=0;i<n;i++)
    {
        distMatrix[i]=new int[n];
    }
    for(size_t i=0;i<N;i++)
    {
        for(size_t j=0;j<N;j++)
        {
            distMatrix[i][j]=matrix[i][j];
        }
    }
    for(size_t i=0;i<N;i++)
    {
        for(size_t j=0;j<N;j++)
        {
            for(size_t k=0;k<N;k++)
            {
                if((distMatrix[j][k]>distMatrix[j][i]+distMatrix[i][k])&&(distMatrix[j][i]!=0||distMatrix[i][k]!=0))
                {
                    distMatrix[j][k]=distMatrix[j][i]+distMatrix[i][k];
                }
            }
        }
    }
    return distMatrix; 
}
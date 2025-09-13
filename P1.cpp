#include<bits/stdc++.h>
using namespace std;

int main()
{
    fstream file;
    file.open("sample.txt", ios::in | ios::out | ios::trunc);
    if (!file)
    {
        cout<<"File not opened successfully!"<<endl;
        return 1;
    }
    
    string data;
    cout<<"Enter string to put in file : ";
    getline(cin, data);
    
    file << data;
    int pos = file.tellp();
    if (pos == data.size())
    {
        cout<<"String written successfully"<<endl;
    }
    else
    {
        cout<<"Write operation failed!"<<endl;
    }
    
    file.seekg(0, ios::beg);
    string ret_data;
    while(file.good())
    {
       getline(file, ret_data);
       cout<<ret_data<<endl;
    }
    
    file.close();
    
}

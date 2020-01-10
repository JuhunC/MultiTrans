#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;
class generateCovBand{
private:
    ifstream in;
    ofstream out;
    string str;
    //StringTokenizer st;
    int snpCnt;
public:
    // COnstructor
    generateCovBand(int windowSize, string corrMatrix, string output){
        std::string zero_str = "0\t";
        try{
            in.open(corrMatrix.c_str(),ofstream::binary);
            out.open(output.c_str(),ofstream::binary);
            
            getline(in,str);
            
            snpCnt = 0;
            
            while(getline(in,str)){
                snpCnt++;
                // replace StringTokenizer(str)
                std::stringstream ss(str);
                std::string token;
                vector<std::string> st;
                
                int idx = 0;
                while (std::getline(ss, token, ' ')){
                    st.push_back(token);
                }
                for(int i=0; i<(windowSize-snpCnt);i++){
                    out.write(zero_str.c_str(),sizeof(char)*zero_str.length());
                }
                for(int i =0;i<(snpCnt-windowSize); i++){
                    idx++;
                }

                if(snpCnt <= windowSize)
                    for(int i=0;i<snpCnt;i++){
                        st.at(idx).append("\t");
                        out.write(st.at(idx).c_str(),sizeof(char)*st.at(idx).length());
                        idx++;
                    }
                else
                    for(int i=0;i<windowSize;i++){
                        st.at(idx).append("\t");
                        out.write(st.at(idx).c_str(), sizeof(char) * st.at(idx).length());
                        idx++;
                    }
                out.write("\n",sizeof(char)*string("\n").length());
            }
            out.close();
            in.close();
        }catch(std::exception& e){
            std::cout<< e.what() << std::endl;
            exit(-1);
        }
        std::cout << snpCnt << " number of lines read" << std::endl;
    }
};
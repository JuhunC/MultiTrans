#include"generateCovBand.cpp"

int main(int argc, char *argv[])
{
    if(argc != 4){
        return -1;
    }else{
        generateCovBand(std::stoi(string(argv[1])),string(argv[2]),string(argv[3]));
    }
    return 1;
}
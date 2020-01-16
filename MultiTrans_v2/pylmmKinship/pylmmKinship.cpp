#include<iostream>
#include<string>
#include<boost/program_options.hpp>

using namespace std;
namespace po = boost::program_options;

int main(int argc, char *argv[]){
    std::string tfile;
    std::string bfile;
    std::string emmaSNP;
    int emmaNumSNPs;
    std::string saveEig;
    int computeSize=1000;
    bool verbose = false;
    std::string usage = "usage: %prog [options] --[tfile | bfile] plinkFileBase outfile";

    boost::program_options::options_description desc("Allowed options");
    desc.add_options()
        ("help","Print help")
        ("tfile",po::value<std::string>(),"The base for a PLINK tped file")
        ("bfile", po::value<std::string>(),"The base for a PLINK binary ped file")
        ("emmaSNP", po::value<std::string>(),"For backwards compatibility with emma, we allow for \"EMMA\" file formats.  This is just a text file with individuals on the rows and snps on the columns.")
        ("emmaNumSNPs", po::value<int>(),"When providing the emmaSNP file you need to specify how many snps are in the file")
        ("e", po::value<std::string>(),"Save eigendecomposition to this file.")
        // efile
        ("n", po::value<int>(), "The maximum number of SNPs to read into memory at once (default 1000).  This is important when there is a large number of SNPs, because memory could be an issue.")
        ("v", po::bool_switch()->default_value(false), "Print extra information(verbose)")
        ;
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc),vm);

    if(vm.count("help")){
        std::cout<< desc<<std::endl;
        std::exit(1);
    }
    if(vm.count("tfile")){
        tfile = vm["tfile"].as<std::string>();
    }else if(vm.count("bfile")){
        bfile = vm["bfile"].as<std::string>();
    }else if(vm.count("e")){
        saveEig = vm["e"].as<std::string>();
    }else{
        std::cout << "Please provide at least one PLINK input file base (--tfile or --bfile) or an emma formatted file (--emmaSNP)." << std::endl;
        exit(1);
    }

    if(vm.count("n")){
        computeSize = vm["n"].as<int>();
    }else{
        std::cout << "You must provide the number of SNPs when specifying an emma formatted file." <<std::endl;
        exit(1);
    }
    
    


    
    return 0;
}
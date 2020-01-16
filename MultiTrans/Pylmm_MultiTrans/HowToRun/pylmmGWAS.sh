#!/bin/tcsh
#$ -N Project_1
#$ -cwd
#$ -o /u/home/j/jwjjoo/project/clusterJob/project.$JOB_ID.out
#$ -j y
#$ -l h_rt=23:59:59
module load python
python ./pylmm/pylmmGWAS.py -v --tfile=./plink --kfile=./plink.K --phenofile=./project_1.pheno ./clusterJob/project_1.log
python ./pylmm/pylmmGWAS.py -v --emmaSNP=./X.txt(snp by indi) --kfile=./plink.K --emmaPHENO=./pheno_t.txt(one row file) ./clusterJob/test.log
python ./pylmm/pylmmGWAS_multiPhHeri.py -v --emmaSNP=./project/X.txt --kfile=./plink.K --emmaPHENO=./Y.txt(pheno by indi) ./clusterJob/test.log

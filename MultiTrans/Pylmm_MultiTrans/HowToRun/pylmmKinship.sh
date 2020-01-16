#!/bin/tcsh
#$ -N esitmateK
#$ -cwd
#$ -o /u/home/j/jwjjoo/project/GAMMA/microbiota/Metisim//clusterJob/estimateK.$JOB_ID.out
#$ -j y
#$ -l h_rt=23:59:59
module load python
python ./pylmm/pylmmKinship.py --tfile=./plink ./plink.K
python ./pylmm/pylmmKinship.py --emmaSNP=./X.txt(snp by indi) --emmaNumSNPs=100 ./plink.K

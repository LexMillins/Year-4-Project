#!/bin/bash

make
#./Analysis
#root Plot_Sum.C 

for f in /disk/moose/general/asc/Y4_VV_2022/user.achishol.mc16_13TeV.* #*_000001.output.root
	do
		echo "Processing $f"
		echo ./Analysis *_000001.output.root  #DSID
	done

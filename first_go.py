import ROOT #import ROOT in python and run script in python to use pyROOT
import numpy as np
import scipy as scipy
from ROOT import TCanvas

f = ROOT.TFile.Open("~/Y4Proj/user.achishol.18108467._000001.output.root", "read") #TFile directory

f.ls()

tree = f.Get("nominal") #extract tree 

c = ROOT.TCanvas("myCanvasName", "The Canvas Title", 400, 300) #create a canvas for Histogram
tree.Draw("el_pt","el_pt") #Fill canvas with selected data

c.Draw() #plot histogram
c.Show()


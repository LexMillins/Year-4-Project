import ROOT;
import numpy as np
import scipy as scipy
from ROOT import TCanvas

f = ROOT.TFile.Open("/user207/Y4Proj user.achihol.18108467._000001.output.root", "read")

f.ls()

tree = f.Get("mini")

c = ROOT.TCanvas("myCanvasName", "The Canvas Title", 400, 300)
tree.Draw("el_pt")
c.Draw()

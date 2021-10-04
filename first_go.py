import ROOT
import numpy as np
import scipy as scipy
from ROOT import TCanvas

f = ROOT.TFile.Open("~/Y4Proj/user.achishol.18108467._000001.output.root", "read")

f.ls()

tree = f.Get("nominal")

c = ROOT.TCanvas("myCanvasName", "The Canvas Title", 400, 300)
tree.Draw("el_pt","el_pt")

c.Draw()
c.Show()

